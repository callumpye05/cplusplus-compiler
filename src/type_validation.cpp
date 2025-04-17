
/**
 * \file type_validation.cpp
 * \brief Implementation of the infer_type() and validate() methods 
 * \author Matthieu Perrin 
 * \version 1
 * \date 17-02-2025
 */

#include "ast.hpp"
#include "type_fonction.hpp"


/***********************************************************
 *                                                         *
 * Definition of the infer_type method for the expressions *
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
  case LONGUEUR:
  if(argument_type.kind == algo_types::STRING || argument_type.kind == algo_types::ARRAY)
    return algo_types(algo_types::INTEGER);

  std::cerr << "Erreur : la fonction longueur doit être utilisée avec une chaîne de caractères ou un tableau" << std::endl;
  return algo_types(algo_types::ERROR);


  case MOINS:
    if(argument_type == algo_types::INTEGER) return algo_types::INTEGER;
    std::cerr << "Erreur : l'opérateur unaire - doit être utilisé avec un entier" << std::endl;
    break;
    
  case NON:
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

    // 2) Every dimension expression must be an integer
    for (size_t i = 0; i < dimensions.size(); ++i) {
        algo_types dim_t = dimensions[i]->infer_type(program);
        if (dim_t.kind != algo_types::INTEGER) {
            std::cerr << "Erreur : la dimension #" << (i+1)
                      << " doit être un entier\n";
            return algo_types(algo_types::ERROR);
        }
    }

    // 3) Return the stored array_type (set earlier by the parser or assignment)
    return array_type;
}

algo_types ArrayAccess::infer_type(const Program& ctx) const {
  // 1) what am I indexing?
  algo_types base = array->infer_type(ctx);
  // 2) every index must be integer
  for (auto* idx : indices) {
    if (idx->infer_type(ctx) != algo_types::INTEGER) {
      std::cerr << "Erreur : l'indice d'un tableau/doit être un entier\n";
      return algo_types::ERROR;
    }
  }

  // 3a) if it was a string, exactly one index → char
  if (base.kind == algo_types::STRING) {
    if (indices.size() != 1) {
      std::cerr << "Erreur : trop d'indices pour une chaîne\n";
      return algo_types::ERROR;
    }
    return algo_types(algo_types::CHARACTER);
  }

  // 3b) if it was an array, peel off one layer per index
  if (base.kind == algo_types::ARRAY) {
    algo_types element = base;
    for (size_t i = 0; i < indices.size(); ++i) {
      if (element.parameters.empty()) {
        std::cerr << "Erreur : trop d'indices pour accéder à un élément du tableau\n";
        return algo_types::ERROR;
      }
      element = element.parameters[0];
    }
    return element;
  }

  std::cerr << "Erreur : accès par [] sur un type non‑tableau/non‑chaîne\n";
  return algo_types::ERROR;
}

bool ArrayAssignment::validate(const Program& program) const {
    // 1) Infer the type of the array being accessed
    algo_types array_t = array->infer_type(program);
    if (array_t.kind != algo_types::ARRAY) {
        std::cerr << "Erreur : l'affectation doit se faire sur un tableau." << std::endl;
        return false;
    }

    // 2) Peel off one layer per index to get the element type
    algo_types elem_t = array_t;
    for (auto* idx_expr : indices) {
        // a) check index is integer
        algo_types idx_t = idx_expr->infer_type(program);
        if (idx_t.kind != algo_types::INTEGER) {
            std::cerr << "Erreur : l'indice du tableau doit être un entier." << std::endl;
            return false;
        }
        // b) peel
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
        std::cerr << "Erreur : longueur appliquée à un non-tableau" << std::endl;
        return algo_types::ERROR;
    }
    return algo_types::INTEGER;
}




/*
 *algo_types ArrayType::infer_type(const Program& program) const {
  return algo_types::ARRAY;
}
 */
/*
bool is_array_type(const algo_types& type) {
  return std::holds_alternative<ArrayType>(type);
}

algo_types get_array_element_type(const algo_types& type) {
  if (is_array_type(type)) {
    return std::get<ArrayType>(type).element_type;
  }
  return base_types::ERROR;
}

algo_types ArrayCreation::infer_type(const Program& program) const {
  algo_types size_type = taille->infer_type(program);
  if(size_type != algo_types::INTEGER) {
    std::cerr << "Erreur: taille du tableau doit etre un entier par défaut " << std::endl;
    return algo_types::ERROR;
  }
  return ArrayType(type);
}

algo_types ArrayAccess::infer_type(const Program& program) const {
  algo_types array_type = tableau->infer_type(program);
  algo_types index_type = indice->infer_type(program);
  
  if(array_type != algo_types::ARRAY) {
    std::cerr << "Erreur : l'accès à un tableau doit se faire sur un tableau" << std::endl;
    return algo_types::ERROR;
  }
  
  if(index_type != algo_types::INTEGER) {
    std::cerr << "Erreur : l'indice d'un tableau doit être un entier" << std::endl;
    return algo_types::ERROR;
  }
  
  return get_array_element_type(array_type);
}

algo_types ArrayLength::infer_type(const Program& program) const {
  algo_types array_type = tableau->infer_type(program);
  
  if(array_type != algo_types::ARRAY) {
    std::cerr << "Erreur : la longueur doit être appliquée à un tableau" << std::endl;
    return algo_types::ERROR;
  }
  
  return algo_types::INTEGER;
}
*/
algo_types BinaryOperation::infer_type(const Program& context) const {
  algo_types left_type  = left->infer_type(context);
  algo_types right_type = right->infer_type(context);
  if(left_type == algo_types::ERROR || right_type == algo_types::ERROR) return algo_types::ERROR;
  
  switch(oper) {
  case PLUS: 
    if(left_type == algo_types::INTEGER && right_type == algo_types::INTEGER) return algo_types::INTEGER;
    if(left_type == algo_types::STRING)  return algo_types::STRING;
    std::cerr << "Erreur : l'opérateur binaire + doit être utilisé avec des entiers ou des chaînes de caractères" << std::endl;
    break;

  case MOINS:
    if(left_type == algo_types::INTEGER && right_type == algo_types::INTEGER) return algo_types::INTEGER;
    std::cerr << "Erreur : l'opérateur binaire - doit être utilisé avec des entiers" << std::endl;
    break;
    
  case FOIS: 
    if(left_type == algo_types::INTEGER && right_type == algo_types::INTEGER) return algo_types::INTEGER;
    std::cerr << "Erreur : l'opérateur binaire * doit être utilisé avec des entiers" << std::endl;
    break;
    
  case ET:
    if(left_type == algo_types::BOOLEAN && right_type == algo_types::BOOLEAN) return algo_types::BOOLEAN;
    std::cerr << "Erreur : l'opérateur binaire et doit être utilisé avec des booléens" << std::endl;
    break;
    
  case OU: 
    if(left_type == algo_types::BOOLEAN && right_type == algo_types::BOOLEAN) return algo_types::BOOLEAN;
    std::cerr << "Erreur : l'opérateur binaire ou doit être utilisé avec des booléens" << std::endl;
    break;

  case EGAL: 
    if(left_type == right_type) return algo_types::BOOLEAN;
    std::cerr << "Erreur : l'opérateur binaire = doit être utilisé avec des valeurs de même type" << std::endl;
    break;

  case INFERIEUR : 
    if(left_type == algo_types::INTEGER && right_type == algo_types::INTEGER) return algo_types::BOOLEAN;
    std::cerr << "Erreur : l'opérateur binaire < être utilisé avec des entiers" << std::endl;
    break;

   case INDICE : 
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
 /*
bool types_equal(const algo_types& a, const algo_types& b) {
  if (is_array_type(a) && is_array_type(b)) {
    return types_equal(get_array_element_type(a), get_array_element_type(b));
  }
  return a == b;
}
*/
/*
bool Assignment::validate(const Program& context) const {
  algo_types variable_type = context.infer_type(variable);
  algo_types expression_type = value->infer_type(context);
  if(variable_type != expression_type) {
    std::cerr << "Erreur : l'affectation de " << variable << " n'est pas du bon type" << std::endl;
    return false;
  }
  return true;
}
*/
bool Assignment::validate(const Program& context) const {
    // 1) What type did we declare on the LHS?
    algo_types variable_type = context.infer_type(variable);

    // 2) If the RHS is an ArrayCreation, give it the LHS’s declared type
    if (auto* ac_const = dynamic_cast<const ArrayCreation*>(value)) {
        // now drop the const so we can assign to its array_type
        auto* ac = const_cast<ArrayCreation*>(ac_const);
        ac->array_type = variable_type;
    }

    // 3) Now infer the RHS’s type correctly
    algo_types expression_type = value->infer_type(context);

    // 4) Compare
    if (variable_type != expression_type) {
        std::cerr << "Erreur : l'affectation de " << variable 
                  << " n'est pas du bon type." << std::endl;
        return false;
    }
    return true;
}


bool Read::validate(const Program& context) const {
  algo_types variable_type = context.infer_type(variable);
  if(variable_type != algo_types::STRING) {
    std::cerr << "Erreur : lire retourne une chaîne de caractères" << std::endl;
    return false;
  }
  return true;
}

bool If::validate(const Program& context) const {
    // Validation de la condition principale
    algo_types condition_type = condition->infer_type(context);
    if (condition_type != algo_types::BOOLEAN) {
        std::cerr << "Erreur : la condition doit être une expression booléenne" << std::endl;
        return false;
    }

    // Validation du bloc ALORS
    if (!thenBranch->validate(context)) {
        std::cerr << "Erreur : le bloc ALORS est invalide" << std::endl;
        return false;
    }

    // Validation des clauses sinonsi
    for (const auto& elseIf : elseIfs) {
        algo_types elseIfConditionType = elseIf.first->infer_type(context);
        if (elseIfConditionType != algo_types::BOOLEAN) {
            std::cerr << "Erreur : la condition d'une clause sinonsi doit être une expression booléenne" << std::endl;
            return false;
        }
        if (!elseIf.second->validate(context)) {
            std::cerr << "Erreur : le bloc d'une clause sinonsi est invalide" << std::endl;
            return false;
        }
    }

    // Validation du bloc SINON (s'il existe)
    if (elseBranch && !elseBranch->validate(context)) {
        std::cerr << "Erreur : le bloc SINON est invalide" << std::endl;
        return false;
    }

    return true;
}

bool While::validate(const Program& context) const {
  algo_types condition_type = condition->infer_type(context);
  if(condition_type != algo_types::BOOLEAN) {
    std::cerr << "Erreur : la condition doit être une expression booléenne" << std::endl;
    return false;
  }
  return body->validate(context);
}

bool For::validate(const Program& context) const {
    // Validate the start, end, and step expressions
    algo_types start_type = start->infer_type(context);
    algo_types end_type = end->infer_type(context);
    algo_types step_type = step->infer_type(context);

    // Ensure start, end, and step are integers
    if (start_type != algo_types::INTEGER) {
        std::cerr << "Erreur : la valeur de début doit être un entier" << std::endl;
        return false;
    }
    if (end_type != algo_types::INTEGER) {
        std::cerr << "Erreur : la valeur de fin doit être un entier" << std::endl;
        return false;
    }
    if (step_type != algo_types::INTEGER) {
        std::cerr << "Erreur : le pas doit être un entier" << std::endl;
        return false;
    }

    // Validate the body of the loop
    return body->validate(context);
}

/********************************************************************
 *                                                                  *
 * Definition of the type and validate methods for the Program type *
 *                                                                  *
 ********************************************************************/

algo_types Program::infer_type(const std::string& variable) const {
  for(const Declaration* declaration : declarations)
    if(declaration->variable_name == variable)
      return declaration->type; 
  std::cerr << "Erreur : la variable " << variable << "n'est pas déclarée" << std::endl;
  return algo_types::ERROR;
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
