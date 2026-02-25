/**
 * \file code_generation.cpp
 * \brief Implementation of the cpp_code() method 
 * \author Callum PYE 
 * \version 2
 * \date 25-04-2025
 */

#include "ast.hpp"
#include <sstream>
#include <vector>


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



std::string Literal::cpp_code(const Program& prog) const {
  return literal;
}

std::string Identifier::cpp_code(const Program& prog) const {
  return name;
}



std::string Declaration::cpp_code(const std::string& indent, const Program& /*prog*/) const {
    return indent + type.to_cpp_type() + " " + variable_name + ";\n";
}



std::string UnaryOperation::cpp_code(const Program& prog) const {
    std::cerr << "Generating code for UnaryOperation: oper = " << oper << std::endl;
    switch (oper) {
        case AST_LONGUEUR:
            
            //analyse sémantique: on adapte la méthode C++ selon le type
            //Les tableaux(vector) utilisent .size() tandis que les chaines utilisent .length()
            if (argument->infer_type(prog).kind == algo_types::ARRAY) {
                return "(" + argument->cpp_code(prog) + ").size()";
            }
            return "(" + argument->cpp_code(prog) + ").length()";
        
        case AST_LONGUEURV:
            return "(" + argument->cpp_code(prog) + ").size()";
        case AST_MOINS:
            return "-(" + argument->cpp_code(prog) + ")";
        case AST_NON:
            return "!(" + argument->cpp_code(prog) + ")";
        default:
            throw std::invalid_argument("Invalid unary operation");
    }
}

std::string BinaryOperation::cpp_code(const Program& prog) const {
  
  //utilisation systématique de parenthèses pour garantir que les priorités 
  //de l'algorithme original sont préservées lors de la compilation
  switch(oper) {
  case AST_PLUS      : return "(" + left->cpp_code(prog) + ") + ("  + right->cpp_code(prog) + ")";
  case AST_MOINS     : return "(" + left->cpp_code(prog) + ") - ("  + right->cpp_code(prog) + ")";
  case AST_FOIS      : return "(" + left->cpp_code(prog) + ") * ("  + right->cpp_code(prog) + ")";
  case AST_ET        : return "(" + left->cpp_code(prog) + ") && (" + right->cpp_code(prog) + ")";
  case AST_OU        : return "(" + left->cpp_code(prog) + ") || (" + right->cpp_code(prog) + ")";
  case AST_EGAL      : return "(" + left->cpp_code(prog) + ") == (" + right->cpp_code(prog) + ")";
  case AST_INFERIEUR : return "(" + left->cpp_code(prog) + ") < ("  + right->cpp_code(prog) + ")";
  case AST_INDICE    : return "(" + left->cpp_code(prog) + ")[("    + right->cpp_code(prog) + ")-1]";
  }
  return "";
}


/***************************************************
 *                                                 *
 * Implementation of cpp_code for the instructions *
 *                                                 *
 ***************************************************/

std::string Sequence::cpp_code(const std::string& indent, const Program& prog) const {
  std::string s = "";
  for(Instruction* instruction : instructions) {
   
    s += instruction->cpp_code(indent, prog); 
  }
  return s;
}

std::string Assignment::cpp_code(const std::string& indent, const Program& prog) const {
  
  return indent + variable + " = " + value->cpp_code(prog) + ";\n";
}

std::string Write::cpp_code(const std::string& indent, const Program& prog) const {
    std::string code = indent + "std::cout";
    for (const Expression* arg : arguments) {
        code += " << " + arg->cpp_code(prog);
    }
    code += ";\n";
    return code;
}

std::string Read::cpp_code(const std::string& indent, const Program& prog) const {
    return indent + "std::getline(std::cin, " + variable + ");\n";
}

std::string If::cpp_code(const std::string& indent, const Program& prog) const 
{
    std::string code;
    code += indent + "if (" + condition->cpp_code(prog) + ") {\n";
    code += thenBranch->cpp_code(indent + "    ", prog) + "\n";
    code += indent + "}";
    for (const auto& elseIf : elseIfs) 
    {
        code += " else if (" + elseIf.first->cpp_code(prog) + ") {\n";
        code += elseIf.second->cpp_code(indent + "    ", prog) + "\n";
        code += indent + "}";
    }
    if (elseBranch) 
    {
        code += " else {\n";
        code += elseBranch->cpp_code(indent + "    ", prog) + "\n";
        code += indent + "}";
    }
    return code;
}

std::string While::cpp_code(const std::string& indent, const Program& prog) const 
{
  return
    indent + "while(" + condition->cpp_code(prog) + ") {\n" + 
                body->cpp_code("  " + indent, prog) + 
    indent + "}\n";
}

std::string For::cpp_code(const std::string& indent, const Program& prog) const 
{
    std::string boucle_var_nom = loop_var;  
    std::string code =
        indent + "for(int " + boucle_var_nom + " = " + start->cpp_code(prog) + "; " + 
        boucle_var_nom + " < " + end->cpp_code(prog) + "; " +                         
        boucle_var_nom + " += " + step->cpp_code(prog) + ") {\n" +                    
        body->cpp_code("  " + indent, prog) +                                      
        indent + "}\n";                                                      

    return code;
}

std::string ArrayCreation::cpp_code(const Program& prog) const 
{
    if (dimensions.empty()) return "aucune dimension";
    std::string base_type;
    if (array_type.kind == algo_types::ARRAY && !array_type.parameters.empty()) 
    {
        base_type = array_type.parameters[0].to_cpp_type();
    } 
    else 
    {
        base_type = array_type.to_cpp_type();
    }
    
    std::string code = base_type;
    for (int i = dimensions.size() - 1; i >= 0; --i) 
    {
        code = "std::vector<" + code + ">(" + dimensions[i]->cpp_code(prog) + ")";
    }

    return code;
}

std::string ArrayAccess::cpp_code(const Program& prog) const 
{
    std::cerr << "ArrayAccess::cpp_code used on: " << array->cpp_code(prog) << "\n";
    std::cerr << "number of the index used " << indices.size() << "\n";
    std::string access_code = array->cpp_code(prog);
    std::string access_path = array->cpp_code(prog);
    for (size_t depth = 0; depth < indices.size(); ++depth) 
    {
        std::string idx = indices[depth]->cpp_code(prog);
        std::cerr << "Index " << depth << ": " << idx << "\n";
        access_path += "[" + idx + "]";
        std::string wrapped =
            "([&]() -> auto { "
            "if ((" + idx + ") < 0 || (" + idx + ") >= " + access_code + ".size()) "
            "throw std::out_of_range(\"Index non valide pour " + access_path + "\"); "
            "return " + access_code + "[" + idx + "]; })()";

        access_code = wrapped;
    }
    return access_code;
}

std::string ArrayAssignment::cpp_code(const std::string& indent, const Program& prog) const 
{
    std::string lhs = array->cpp_code(prog);
    for (Expression* e : indices) 
    {
        lhs += "[" + e->cpp_code(prog) + "]";
    }
    if (auto arrInit = dynamic_cast<ArrayCreation*>(value)) 
    {
        const auto& dims = arrInit->dimensions;
        std::string baseType = arrInit->array_type.to_cpp_type();
        size_t accessDepth = indices.size();
        size_t neededDepth = dims.size() - accessDepth;
        std::string ctor = baseType;
        if (neededDepth == 0 && !dims.empty()) 
        {
            ctor = "std::vector<" + baseType + ">(" + dims.back()->cpp_code(prog) + ")";
        } 
        else 
        {
            for (int i = static_cast<int>(neededDepth) - 1; i >= 0; --i) 
            {
                std::string dimCode = dims[i]->cpp_code(prog);
                ctor = "std::vector<" + ctor + ">(" + dimCode + ")";
            }
        }
        return indent + lhs + " = " + ctor + ";\n";
    }
    return indent + lhs + " = " + value->cpp_code(prog) + ";\n";
}

std::string ForEach::cpp_code(const std::string& indent, const Program& prog) const  
{
    std::ostringstream oss;
    oss << indent << "for (auto " << loop_var << " : " << array_name << ") {\n";
    oss << body->cpp_code(indent + "  ", prog);
    oss << indent << "}\n";
    return oss.str();
}

std::string FunctionDefinition::cpp_code(const std::string& indent, const Program& prog) const 
{
 
    Program& mutable_prog = const_cast<Program&>(prog);
  
    std::map<std::string, algo_types> old_types;

    for (const auto& param : params) {
        if(mutable_prog.symtab.count(param.name)) {
            old_types[param.name] = mutable_prog.symtab[param.name];
        }
        mutable_prog.symtab[param.name] = param.type;
    }

    for (auto instr : body->instructions) {
        Declaration* decl = dynamic_cast<Declaration*>(instr);
        if (decl) {
            if(mutable_prog.symtab.count(decl->variable_name)) {
                old_types[decl->variable_name] = mutable_prog.symtab[decl->variable_name];
            }
            mutable_prog.symtab[decl->variable_name] = decl->type;
        }
    }

    
    std::ostringstream out;
    out << indent << return_type.to_cpp_type() << " " << name << "(";
    for (size_t i = 0; i < params.size(); ++i) {
        out << params[i].type.to_cpp_type() << " " << params[i].name;
        if (i + 1 < params.size()) out << ", ";
    }
    out << ") {\n";
    
    //génération du corps, qui permet de trouver type locale
    out << body->cpp_code(indent + "  ", prog);
    out << indent << "}\n";

 
    //retirer les param
    for (const auto& param : params) {
        mutable_prog.symtab.erase(param.name);
    }
    // retirer les variables locale
    for (auto instr : body->instructions) {
        if (Declaration* decl= dynamic_cast<Declaration*>(instr)) {
            mutable_prog.symtab.erase(decl->variable_name);
        }
    }
    //réinserer des ancien types caché
    mutable_prog.symtab.insert(old_types.begin(), old_types.end());

    return out.str();
}

std::string ProcedureDefinition::cpp_code(const std::string& indent,const Program& prog) const 
{
    //on accède à la table des symboles pour enregistrer la portée locale
    //on utilise const_cast car la génération de code nécessite de modifier temporairement l'etat de la table
    Program& mutable_prog = const_cast<Program&>(prog);
    
    // Sauvegarde des types existants pour gérer le masquage 
    //au cas ou une variable locale porte le meme nom qu'une variable globale.
    std::map<std::string, algo_types> old_types;

    // 1. ENREGISTREMENT DES PARAMÈTRES : Ajoute les arguments de la procédure à la table
    for (const auto& param : params) {
        if(mutable_prog.symtab.count(param.name)) {
            old_types[param.name] = mutable_prog.symtab[param.name];
        }
        mutable_prog.symtab[param.name] = param.type;
    }

    //le parseur stocke les variables locales dans le bloc VARIABLES à l'intérieur de 'body'
    for (auto instr : body->instructions) {
        if (Declaration* decl = dynamic_cast<Declaration*>(instr)) {
            if(mutable_prog.symtab.count(decl->variable_name)) {
                old_types[decl->variable_name] = mutable_prog.symtab[decl->variable_name];
            }
            mutable_prog.symtab[decl->variable_name] = decl->type;
        }
    }

    //GÉNÉRATION DU CODE
    std::ostringstream out;
    out << indent << "void " << name << "(";
    for (size_t i = 0; i < params.size(); ++i) {
        out << params[i].type.to_cpp_type() << " " << params[i].name;
        if (i + 1 < params.size()) out << ", ";
    }
    out << ") {\n";
    
    //le corps peut utiliser la table des symboles pour l'inférence de type
    out << body->cpp_code(indent+ "  ", prog);
    out << indent << "}\n";

    // Supprime les paramètres de la portée actuelle
    for (const auto& param : params) {
        mutable_prog.symtab.erase(param.name);
    }
    //supprime les variables locales
    for (auto instr : body->instructions) {
        if (Declaration* decl = dynamic_cast<Declaration*>(instr)) {
            mutable_prog.symtab.erase(decl->variable_name);
        }
    }
    // restaure les variables globales qui auraient été masquées
    mutable_prog.symtab.insert(old_types.begin(), old_types.end());

    return out.str();
}

std::string Return::cpp_code(const std::string& indent, const Program& prog) const 
{
    return indent + "return " + value->cpp_code(prog) + ";\n";
}

std::string FunctionCall::cpp_code(const Program& prog) const 
{
    std::string code = name + "(";
    for (size_t i = 0; i < arguments.size(); ++i) 
    {
        if (i > 0) code += ", ";
        code += arguments[i]->cpp_code(prog);
    }
    code += ")";
    return code;
}

std::string ProcedureCall::cpp_code(const std::string& indent, const Program& prog) const  
{
    std::string code = name + "(";
    for (size_t i = 0; i < arguments.size(); ++i) 
    {
        if (i > 0) code += ", ";
        code += arguments[i]->cpp_code(prog);
    }
    code += ");";
    return code;
}

/***************************************************
 * *
 * Implementation of cpp_code for the main program *
 * *
 ***************************************************/

std::string Program::cpp_code() const 
{
    std::ostringstream out;

    // bibliothèques qu'on a besoin
    out << "#include <iostream>\n";
    out << "#include <string>\n";
    out << "#include <vector>\n";
    out << "#include <stdexcept>\n\n";

    for (const Instruction* func : functions) 
    {
        // Pass the program context (*this) to function definitions
        out << func->cpp_code("", *this) << "\n";
    }

    out << "int main() {\n";
    for (const Declaration* declaration : declarations) 
    {
        
        out << declaration->cpp_code("  ", *this); 
    }

   
    out << body->cpp_code("  ", *this);

    out << "  return 0;\n";
    out << "}\n";
    return out.str();
}
