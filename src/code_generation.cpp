/**
 * \file code_generation.cpp
 * \brief Implementation of the cpp_code() method 
 * \author Matthieu Perrin 
 * \version 1
 * \date 17-02-2025
 */

#include "ast.hpp"
#include <sstream>


/**************************************************
 *                                                *
 * Implementation of cpp_code for the expressions *
 *                                                *
 **************************************************/

std::string to_string(algo_types::type_kind tk) {
    switch(tk) {
        case algo_types::BOOLEAN:    return "bool";
        case algo_types::INTEGER:    return "int";
        case algo_types::CHARACTER:  return "char";
        case algo_types::STRING:     return "std::string";
        case algo_types::ARRAY:      return "std::vector";
        case algo_types::ERROR:      return "error";
        default:                     return "unknown";
    }
}



std::string Literal::cpp_code() const {
  return literal;
}

std::string Identifier::cpp_code() const {
  return name;
}


std::string Declaration::cpp_code(const std::string& indent) const {
  return indent + type.to_cpp_type() + " " + variable_name;
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
    if (dimensions.empty()) return "/* erreur: dimensions vides */";

    
    
    std::string base_type;
	if (array_type.kind == algo_types::ARRAY && !array_type.parameters.empty()) {
		base_type = array_type.parameters[0].to_cpp_type();
	} 
	else {
    base_type = array_type.to_cpp_type();
	}
    
    
    std::string code = base_type;
    for (int i = dimensions.size() - 1; i >= 0; --i) {
        code = "std::vector<" + code + ">(" + dimensions[i]->cpp_code() + ")";
    }

    return code;
}

std::string ArrayAccess::cpp_code() const {
    std::string code = array->cpp_code();
    for (auto idx : indices) {
        code += "[" + idx->cpp_code() + "]";
    }
    return code;
}



std::string ArrayAssignment::cpp_code(const std::string& indent) const {
    std::string lhs = array->cpp_code();
    for (Expression* e : indices) {
        lhs += "[" + e->cpp_code() + "]";
    }

    // Handle array creation separately
    if (auto arrInit = dynamic_cast<ArrayCreation*>(value)) {
        const auto& dims = arrInit->dimensions;
        std::string baseType = arrInit->array_type.to_cpp_type();

        size_t accessDepth = indices.size();
        size_t neededDepth = dims.size() - accessDepth;

        std::string ctor = baseType;

        if (neededDepth == 0 && !dims.empty()) {
            ctor = "std::vector<" + baseType + ">(" + dims.back()->cpp_code() + ")";
        } else {
            for (int i = static_cast<int>(neededDepth) - 1; i >= 0; --i) {
                std::string dimCode = dims[i]->cpp_code();
                ctor = "std::vector<" + ctor + ">(" + dimCode + ")";
            }
        }

        return indent + lhs + " = " + ctor + ";\n";
    }

    // General expression fallback (e.g. i + j)
    return indent + lhs + " = " + value->cpp_code() + ";\n";
}


std::string ForEach::cpp_code(const std::string& indent) const  {
        std::ostringstream oss;
        oss << indent << "for (auto " << loop_var << " : " << array_name << ") {\n";
        oss << body->cpp_code(indent + "  ");
        oss << indent << "}\n";
        return oss.str();
    }
    

std::string Return::cpp_code() const {
    return "return " + value->cpp_code() + ";\n";
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
