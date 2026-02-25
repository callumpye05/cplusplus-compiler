
/**
 * \file type_validation.cpp
 * \brief Implementation of the infer_type() and validate() methods 
 * \author Callum PYE
 * \version 2
 * \date 25-04-2025
 */

#include "ast.hpp"
#include "type_fonction.hpp"


/***********************************************************
 *                                                         *
 * Definition de infer_type pour les méthodes              *
 *                                                         *
 ***********************************************************/

algo_types Literal::infer_type(const Program&) const {
  return type;
}

algo_types Identifier::infer_type(const Program& program) const {
  return program.infer_type(name);
}

algo_types UnaryOperation::infer_type(const Program& context) const {
  algo_types argument_type = argument->infer_type(context);
  if(argument_type == algo_types::ERROR) return algo_types::ERROR;
  
  switch(oper) {
  case AST_LONGUEUR:
  if(argument_type.kind == algo_types::STRING || argument_type.kind == algo_types::ARRAY)
    return algo_types(algo_types::INTEGER);

  std::cerr << "Erreur : la fonction longueur doit être utilisée avec une chaîne de caractères" << std::endl;
  return algo_types(algo_types::ERROR);
  
  
  case AST_LONGUEURV:
  	if(argument_type.kind == algo_types::ARRAY) 
  		return algo_types(algo_types::INTEGER);
  	std::cerr << "Erreur : la fonction Longueur doit être utilisée avec un tableau" << std::endl;
  	return algo_types(algo_types::ERROR);
  	


  case AST_MOINS:
    if(argument_type == algo_types::INTEGER) return algo_types::INTEGER;
    std::cerr << "Erreur : l'opérateur unaire - doit être utilisé avec un entier" << std::endl;
    break;
    
  case AST_NON:
	if (argument_type == algo_types::BOOLEAN) return algo_types::BOOLEAN;
    std::cerr << "Erreur : l'opérateur unaire ! doit être utilisé avec un booléen" << std::endl;
    break;
  }
  return algo_types::ERROR;
}


algo_types ArrayCreation::infer_type(const Program& program) const {
    // 1) Must have at least one dimension
    if (dimensions.empty()) {
        std::cerr << "Erreur : aucune dimension spécifiée pour le Tableau\n";
        return algo_types(algo_types::ERROR);
    }

    //dimensions doivent etre un entier 
    for (size_t i = 0; i < dimensions.size(); ++i) {
        algo_types dim_t = dimensions[i]->infer_type(program);
        if (dim_t.kind != algo_types::INTEGER) {
            std::cerr << "Erreur : la dimension #" << (i+1)
                      << " doit être un entier\n";
            return algo_types(algo_types::ERROR);
        }
    }

    //retourne le type du tableau stocker par le parser 
    return array_type;
}

algo_types ArrayAccess::infer_type(const Program& ctx) const {
  algo_types base = array->infer_type(ctx);
  for (auto* idx : indices) {
    if (idx->infer_type(ctx) != algo_types::INTEGER) {
      std::cerr << "Erreur : l'indice d'un tableau doit etre un entier\n";
      return algo_types::ERROR;
    }
  }
  if (base.kind == algo_types::STRING) {
    if (indices.size() != 1) {
      std::cerr << "Erreur :trop d'indices pour une chaîne\n";
      return algo_types::ERROR;
    }
    return algo_types(algo_types::CHARACTER);
  }
  if (base.kind == algo_types::ARRAY) {
    algo_types element = base;
    for (size_t i = 0; i < indices.size(); ++i) {
      if (element.parameters.empty()) {
        std::cerr << "Erreur:trop d'indices pour accéder à un élément du tableau\n";
        return algo_types::ERROR;
      }
      element = element.parameters[0];
    }
    return element;
  }

  std::cerr << "Erreur: accès par [] sur un type qui n'est pas une chaine ou un tableau \n";
  return algo_types::ERROR;
}

bool ArrayAssignment::validate(const Program& program) const {
    algo_types array_t = array->infer_type(program);
    if (array_t.kind != algo_types::ARRAY) {
        std::cerr << "Erreur : l'affectation doit etre sur un tableau" << std::endl;
        return false;
    }
    algo_types elem_t = array_t;
    for (auto* idx_expr : indices) {
        algo_types idx_t = idx_expr->infer_type(program);
        if (idx_t.kind != algo_types::INTEGER) {
            std::cerr << "Erreur: l'indice du tableau doit être un entier." << std::endl;
            return false;
        }
        if (elem_t.parameters.empty()) {
            std::cerr << "Erreur : trop d'indices pour accéder à un élément du tableau." << std::endl;
            return false;
        }
        elem_t = elem_t.parameters[0];
    }
    return true;
}

algo_types ArrayLength::infer_type(const Program& context) const {
    algo_types array_type = argument->infer_type(context);
    if (array_type.kind != algo_types::ARRAY && array_type != algo_types::STRING) {
        std::cerr << "Erreur : longueur appliquée à un type qui n'est pas un tableau" << std::endl;
        return algo_types::ERROR;
    }
    return algo_types::INTEGER;
}
algo_types BinaryOperation::infer_type(const Program& context) const {
  algo_types left_type  = left->infer_type(context);
  algo_types right_type = right->infer_type(context);
  if(left_type == algo_types::ERROR || right_type == algo_types::ERROR) return algo_types::ERROR;
  
  switch(oper) {
  case AST_PLUS: 
    if(left_type == algo_types::INTEGER && right_type == algo_types::INTEGER) return algo_types::INTEGER;
    if(left_type == algo_types::STRING)  return algo_types::STRING;
    std::cerr << "Erreur : l'opérateur binaire + doit être utilisé avec des entiers ou des chaînes de caractères" << std::endl;
    break;

  case AST_MOINS:
    if(left_type == algo_types::INTEGER && right_type == algo_types::INTEGER) return algo_types::INTEGER;
    std::cerr << "Erreur : l'opérateur binaire - doit être utilisé avec des entiers" << std::endl;
    break;
    
  case AST_FOIS: 
    if(left_type == algo_types::INTEGER && right_type == algo_types::INTEGER) return algo_types::INTEGER;
    std::cerr << "Erreur : l'opérateur binaire * doit être utilisé avec des entiers" << std::endl;
    break;
    
  case AST_ET:
    if(left_type == algo_types::BOOLEAN && right_type == algo_types::BOOLEAN) return algo_types::BOOLEAN;
    std::cerr << "Erreur : l'opérateur binaire et doit être utilisé avec des booléens" << std::endl;
    break;
    
  case AST_OU: 
    if(left_type == algo_types::BOOLEAN && right_type == algo_types::BOOLEAN) return algo_types::BOOLEAN;
    std::cerr << "Erreur : l'opérateur binaire ou doit être utilisé avec des booléens" << std::endl;
    break;

  case AST_EGAL: 
    if(left_type == right_type) return algo_types::BOOLEAN;
    std::cerr << "Erreur : l'opérateur binaire = doit être utilisé avec des valeurs de même type" << std::endl;
    break;

  case AST_INFERIEUR : 
    if(left_type == algo_types::INTEGER && right_type == algo_types::INTEGER) return algo_types::BOOLEAN;
    std::cerr << "Erreur : l'opérateur binaire < être utilisé avec des entiers" << std::endl;
    break;

   case AST_INDICE : 
    if(left_type.kind == algo_types::ARRAY) {
        if(right_type == algo_types::INTEGER) {
            if(left_type.parameters.empty()) {
                std::cerr << "Erreur : type d'éléments du tableau non spécifié" << std::endl;
                return algo_types::ERROR;
            }
            return left_type.parameters[0];
        } else {
            std::cerr << "Erreur : l'indice doit être un entier" << std::endl;
        }
    } else if(left_type == algo_types::STRING && right_type == algo_types::INTEGER) {
        return algo_types::CHARACTER;
    } else {
        std::cerr << "Erreur : accès à un indice sur un non-tableau" << std::endl;
    }
	}
	return algo_types::ERROR;
}

/**********************************************************
 *                                                        *
 * Definition of the validate method for the instructions *
 *                                                        *
 **********************************************************/

bool Sequence::validate(const Program& context) const {
  for(Instruction* instruction : instructions) {
    if(!instruction->validate(context)) {
      return false;
    }
  }
  return true;
}

bool Assignment::validate(const Program& context) const {
    algo_types variable_type = context.infer_type(variable);
    if (auto* ac_const = dynamic_cast<const ArrayCreation*>(value)) {
        auto* ac = const_cast<ArrayCreation*>(ac_const);
        ac->array_type = variable_type;
    }
    algo_types expression_type = value->infer_type(context);
    if (variable_type != expression_type) {
        std::cerr << "erreur :l'affectation de " << variable 
                  << " n'est pas du bon type." << std::endl;
        return false;
    }
    return true;
}

bool Read::validate(const Program& context) const {
  algo_types variable_type = context.infer_type(variable);
  if(variable_type != algo_types::STRING) {
    std::cerr << "Erreur: lire retourne une chaine de caractères" << std::endl;
    return false;
  }
  return true;
}

bool If::validate(const Program& context) const {
    algo_types condition_type = condition->infer_type(context);
    if (condition_type != algo_types::BOOLEAN) {
        std::cerr << "Erreur :la condition doit etre une expression booléenne" << std::endl;
        return false;
    }
    if (!thenBranch->validate(context)) {
        std::cerr << "Erreur :le bloc ALORS est invalide" << std::endl;
        return false;
    }
    for (const auto& elseIf : elseIfs) {
        algo_types elseIfConditionType = elseIf.first->infer_type(context);
        if (elseIfConditionType != algo_types::BOOLEAN) {
            std::cerr << "Erreur :la condition d'un sinonsi doit etre une expression booléenne" << std::endl;
            return false;
        }
        if (!elseIf.second->validate(context)) {
            std::cerr << "Erreur : le bloc d'un sinonsi est invalide" << std::endl;
            return false;
        }
    }
    if (elseBranch && !elseBranch->validate(context)) {
        std::cerr << "Erreur : le bloc SINON est invalide" << std::endl;
        return false;
    }

    return true;
}

bool While::validate(const Program& context) const {
  algo_types condition_type = condition->infer_type(context);
  if(condition_type != algo_types::BOOLEAN) {
    std::cerr << "Erreur :la condition doit être une expression booléenne" << std::endl;
    return false;
  }
  return body->validate(context);
}

bool For::validate(const Program& context) const {
    algo_types start_type = start->infer_type(context);
    algo_types end_type = end->infer_type(context);
    algo_types step_type = step->infer_type(context);
    if (start_type != algo_types::INTEGER) {
        std::cerr << "Erreur :la valeur de début doit être un entier" << std::endl;
        return false;
    }
    if (end_type != algo_types::INTEGER) {
        std::cerr << "Erreur: la valeur de fin doit être un entier" << std::endl;
        return false;
    }
    if (step_type != algo_types::INTEGER) {
        std::cerr << "Erreur: le pas doit être un entier" << std::endl;
        return false;
    }
    return body->validate(context);
}

bool ForEach::validate(const Program& p) const  {
        auto t = p.lookup_type(array_name);
        if (t.kind != algo_types::ARRAY) {
            std::cerr << "Erreur :  " <<array_name<< " n’est pas un tableau.\n";
            return false;
        }
        return body->validate(p);
    }
    
bool FunctionDefinition::validate(const Program& context) const {
    return body->validate(context);
}

bool ProcedureDefinition::validate(const Program& context) const {
    return body->validate(context);
}

bool Return::validate(const Program& context) const {
    return value->infer_type(context) != algo_types::ERROR;
}


/********************************************************************
 *                                                                  *
 * Définition des types et methodes                                 *
 *                                                                  *
 ********************************************************************/

algo_types Program::infer_type(const std::string& variable) const {
    auto it = symtab.find(variable);
    if (it != symtab.end()) {
        return it->second;
    }
    
    std::cerr << "Erreur : la variable " << variable << " n'est pas déclarée dans le contexte actuel" << std::endl;
    return algo_types(algo_types::ERROR);
}

bool Program::validate() const {
  for(size_t i = 0; i<declarations.size(); i++) {
    for(size_t j = i+1; j<declarations.size(); j++) {
      if(declarations[i]->variable_name == declarations[j]->variable_name) {
	std::cerr << "Erreur : la variable " << declarations[i]->variable_name << "est déclarée deux fois" << std::endl;
	return false;
      }
    }
  }
  return body->validate(*this);
}
