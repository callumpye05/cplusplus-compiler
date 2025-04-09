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
// In ArrayType implementation
std::string ArrayType::cpp_code() const {
    std::string type_str;
    if (std::holds_alternative<base_types>(element_type)) {
        switch (std::get<base_types>(element_type)) {
            case base_types::BOOLEAN:   type_str = "bool"; break;
            case base_types::INTEGER:   type_str = "int"; break;
            case base_types::CHARACTER: type_str = "char"; break;
            case base_types::STRING:    type_str = "std::string"; break;
            default:                    type_str = "ERROR"; break;
        }
    } else {
        type_str = std::get<ArrayType>(element_type).cpp_code();
    }
    return type_str + "[" + std::to_string(size) + "]";
}

// In ArrayCreation implementation
std::string ArrayCreation::cpp_code() const {
    return type.cpp_code() + "{}"; // Type[size]{}
}

// In ArrayAccess implementation
std::string ArrayAccess::cpp_code() const {
    return tableau->cpp_code() + "[__check_index(" + 
           indice->cpp_code() + ", " + 
           std::to_string(std::get<ArrayType>(tableau->infer_type()).size) + ")]";
}

std::string Declaration::cpp_code(const std::string& indent) const {
    if (std::holds_alternative<ArrayType>(type)) {
        const ArrayType& array_type = std::get<ArrayType>(type);
        return indent + array_type.cpp_code() + " " + variable_name;
    } else {
        switch (std::get<base_types>(type)) {
            case base_types::BOOLEAN:   return indent + "bool " + variable_name;
            case base_types::INTEGER:   return indent + "int " + variable_name;
            case base_types::CHARACTER: return indent + "char " + variable_name;
            case base_types::STRING:    return indent + "std::string " + variable_name;
            default:                    return indent + "/* ERROR */";
        }
    }
}

std::string ArrayCreation::cpp_code() const {
    // For static arrays, creation is just declaration with size
    return "{}"; // Zero-initialized
}
std::string ArrayAccess::cpp_code() const {
    // Add bounds checking as required by 2e
    return tableau->cpp_code() + "[__check_index(" + 
           indice->cpp_code() + ", " + 
           std::to_string(array_size) + ")]";
}
std::string ArrayLength::cpp_code() const {
    return std::to_string(array_size); // Static arrays know their size
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
std::string Declaration::cpp_code(const std::string& indent) const {
  if ( type == algo_types::ARRAY) {
		
		ArrayType* type_tableau = dynamic_cast<const ArrayType*>(this);
		
		if(type_tableau) {
			std::string type_element;
			
			switch(array_type->type_element) {
				case algo_types::BOOLEAN   : element_type = "bool"; break;
				case algo_types::INTEGER   : element_type = "int"; break;
				case algo_types::CHARACTER : element_type = "char "; break;
				case algo_types::STRING    : element_type = "string"; break;
				default					   : element_type ="ERREUR" ; break;  	
			}
			 
			
			
		}
		
  switch(type) {
  case algo_types::BOOLEAN   : return indent + "bool "        + variable_name;
  case algo_types::INTEGER   : return indent + "int "         + variable_name;
  case algo_types::CHARACTER : return indent + "char "        + variable_name;
  case algo_types::STRING    : return indent + "std::string " + variable_name;
  default                    : return indent + "";
  }
}


/***************************************************
 *                                                 *
 * Implementation of cpp_code for the main program *
 *                                                 *
 ***************************************************/

std::string Program::cpp_code() const {
  std::string s =
    "#include<iostream>\n"
    "#include<string>\n\n"
    "int main() {\n";
       for(const Declaration* declaration : declarations)
         s+= declaration->cpp_code("  ") + ";\n";
       return s +
       body->cpp_code(std::string("  ")) +
    "  return 0;\n"
    "}\n";
}
