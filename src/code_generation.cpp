/**
 * \file code_generation.cpp
 * \brief Implementation of the cpp_code() method 
 * \author Matthieu Perrin 
 * \version 1
 * \date 17-02-2025
 */

#include "ast.hpp"

/**************************************************
 *                                                *
 * Implementation of cpp_code for the expressions *
 *                                                *
 **************************************************/

std::string Literal::cpp_code() const {
  return literal;
}

std::string Identifier::cpp_code() const {
  return name;
}


std::string Declaration::cpp_code(const std::string& indent) const {
  switch(type.kind) {
    case algo_types::BOOLEAN   : return indent + "bool "         + variable_name;
    case algo_types::INTEGER   : return indent + "int "          + variable_name;
    case algo_types::CHARACTER : return indent + "char "         + variable_name;
    case algo_types::STRING    : return indent + "std::string "  + variable_name;
    case algo_types::ARRAY     : {  // Handle arrays (e.g., "tableau de entier")
      if (type.parameters.empty()) {
        return indent + "std::vector<int> " + variable_name;  // Default to int if no inner type
      }
      // Map inner type to C++ (e.g., "entier" → "int")
      std::string inner_type;
      switch(type.parameters[0].kind) {
        case algo_types::INTEGER   : inner_type = "int";          break;
        case algo_types::BOOLEAN   : inner_type = "bool";         break;
        case algo_types::CHARACTER : inner_type = "char";         break;
        case algo_types::STRING    : inner_type = "std::string";  break;
        default                    : inner_type = "int";          break;
      }
      return indent + "std::vector<" + inner_type + "> " + variable_name;
    }
    default: return indent + "/* UNKNOWN TYPE */ " + variable_name;  // Debug fallback
  }
}


std::string UnaryOperation::cpp_code() const {
    std::cerr << "Generating code for UnaryOperation: oper = " << oper << std::endl;
    switch (oper) {
        case LONGUEUR:
            return "(" + argument->cpp_code() + ").length()";
        case MOINS:
            return "-(" + argument->cpp_code() + ")";
        case NON:
            return "!(" + argument->cpp_code() + ")";
        default:
            throw std::invalid_argument("Invalid unary operation");
    }
}

std::string BinaryOperation::cpp_code() const {
  switch(oper) {
  case PLUS      : return "(" + left->cpp_code() + ") + ("  + right->cpp_code() + ")";
  case MOINS     : return "(" + left->cpp_code() + ") - ("  + right->cpp_code() + ")";
  case FOIS      : return "(" + left->cpp_code() + ") * ("  + right->cpp_code() + ")";
  case ET        : return "(" + left->cpp_code() + ") && (" + right->cpp_code() + ")";
  case OU        : return "(" + left->cpp_code() + ") || (" + right->cpp_code() + ")";
  case EGAL      : return "(" + left->cpp_code() + ") == (" + right->cpp_code() + ")";
  case INFERIEUR : return "(" + left->cpp_code() + ") < ("  + right->cpp_code() + ")";
  case INDICE    : return "(" + left->cpp_code() + ")[("    + right->cpp_code() + ")-1]";
  }
  return "";
}


/***************************************************
 *                                                 *
 * Implementation of cpp_code for the instructions *
 *                                                 *
 ***************************************************/

std::string Sequence::cpp_code(const std::string& indent) const {
  std::string s = "";
  for(Instruction* instruction : instructions) {
    s+=instruction->cpp_code(indent);
  }
  return s;
}

std::string Assignment::cpp_code(const std::string& indent) const {
  return indent + variable + " = " + value->cpp_code() + ";\n";
}

std::string Write::cpp_code(const std::string& indent) const {
    std::string code = indent + "std::cout";
    for (const Expression* arg : arguments) {
        code += " << " + arg->cpp_code();  // Add each argument to the output
    }
    code += ";\n";  // End the statement
    return code;
}

std::string Read::cpp_code(const std::string& indent) const {
  return indent + "std::getline(std::cin, " + variable + ");\n";
}

std::string If::cpp_code(const std::string& indent) const {
  std::string code;

        // Condition principale
        code += indent + "if (" + condition->cpp_code() + ") {\n";
        code += thenBranch->cpp_code(indent + "    ") + "\n";
        code += indent + "}";

        // Clauses sinonsi
        for (const auto& elseIf : elseIfs) {
            code += " else if (" + elseIf.first->cpp_code() + ") {\n";
            code += elseIf.second->cpp_code(indent + "    ") + "\n";
            code += indent + "}";
        }

        // Clause SINON (si elle existe)
        if (elseBranch) {
            code += " else {\n";
            code += elseBranch->cpp_code(indent + "    ") + "\n";
            code += indent + "}";
        }

        return code;
}

std::string While::cpp_code(const std::string& indent) const {
  return
    indent + "while(" + condition->cpp_code() + ") {\n" + 
                body->cpp_code("  " + indent) + 
    indent + "}\n";
}

std::string For::cpp_code(const std::string& indent) const {
    std::string loop_var = "i";  
    std::string code =
        indent + "for(int " + loop_var + " = " + start->cpp_code() + "; " + 
        loop_var + " < " + end->cpp_code() + "; " +                         
        loop_var + " += " + step->cpp_code() + ") {\n" +                    
        body->cpp_code("  " + indent) +                                      
        indent + "}\n";                                                      

    return code;
}

/* A MODIFIER 
 * Il faut representer le tableau dans un cas appart afin de representer le type de ces elements 
 * Donc il faut deux cas distincts , soit nous avons un tableau , soit un type du style, ENTIER, BOOL , etc 
 * */




std::string ArrayCreation::cpp_code() const {
    algo_types element_type = infer_type(Program({}, nullptr)); // Context fictif
    
    if (element_type.kind == algo_types::ARRAY && !element_type.parameters.empty()) {
        element_type = element_type.parameters[0];
    }
    
    std::string type_name;
    switch(element_type.kind) {
        case algo_types::INTEGER: type_name = "int"; break;
        case algo_types::BOOLEAN: type_name = "bool"; break;
        case algo_types::CHARACTER: type_name = "char"; break;
        case algo_types::STRING: type_name = "std::string"; break;
        default: type_name = "int"; 
    }
    
    return "std::vector<" + type_name + ">(" + taille->cpp_code() + ")";
}

algo_types ArrayCreation::infer_type(const Program& context) const {
    algo_types size_type = taille->infer_type(context);
    if (size_type != algo_types::INTEGER) {
        std::cerr << "Erreur : la taille du tableau doit être un entier" << std::endl;
        return algo_types::ERROR;
    }
    return algo_types(algo_types::ARRAY, {algo_types::INTEGER}); // Exemple pour un tableau d'entiers
}

std::string ArrayAccess::cpp_code() const {
    return tableau->cpp_code() + "[" + indice->cpp_code() + "]";
}

algo_types ArrayAccess::infer_type(const Program& context) const {
    algo_types array_type = tableau->infer_type(context);
    algo_types index_type = indice->infer_type(context);
    
    if (array_type.kind != algo_types::ARRAY) {
        std::cerr << "Erreur : accès à un indice sur un non-tableau" << std::endl;
        return algo_types::ERROR;
    }
    if (index_type != algo_types::INTEGER) {
        std::cerr << "Erreur : l'indice doit être un entier" << std::endl;
        return algo_types::ERROR;
    }
    if (array_type.parameters.empty()) {
        return algo_types::ERROR;
    }
    return array_type.parameters[0];
}

algo_types ArrayLength::infer_type(const Program& context) const {
    algo_types array_type = argument->infer_type(context);
    if (array_type.kind != algo_types::ARRAY && array_type != algo_types::STRING) {
        std::cerr << "Erreur : longueur appliquée à un non-tableau" << std::endl;
        return algo_types::ERROR;
    }
    return algo_types::INTEGER;
}


/***************************************************
 *                                                 *
 * Implementation of cpp_code for the main program *
 *                                                 *
 ***************************************************/

std::string Program::cpp_code() const {
  std::string s =
    "#include<iostream>\n"
    "#include<string>\n"
    "#include<vector>\n\n"  // ← Always added
    "int main() {\n";
       for(const Declaration* declaration : declarations)
         s += declaration->cpp_code("  ") + ";\n";
       return s +
       body->cpp_code(std::string("  ")) +
    "  return 0;\n"
    "}\n";
}
