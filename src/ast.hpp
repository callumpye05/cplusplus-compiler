#ifndef AST_HPP_DEFINED
#define AST_HPP_DEFINED

/**
 * \file ast.hpp
 * \brief Header file containing the declarations of the abstract syntax tree.
 * \author Callum PYE 485K 
 * \version 2
 * \date 25-04-2025
 */

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>

struct Program;

// The set of types supported in an algo program
struct algo_types {

  enum type_kind {
    BOOLEAN,
    INTEGER,
    CHARACTER,
    STRING,
    ARRAY,
    ERROR
  };

  type_kind kind;
  std::vector<algo_types> parameters;
  algo_types() : kind(ERROR), parameters() {}

  algo_types(type_kind kind) : kind(kind), parameters() {}
  algo_types(type_kind kind, std::initializer_list<algo_types> parameters) : kind(kind), parameters(parameters) {}
  
  bool operator==(const algo_types& other) const {
    if (kind != other.kind) return false;
    if (parameters.size() != other.parameters.size()) return false;
    for(size_t i = 0; i<parameters.size(); i++)
      if(!(parameters[i] == other.parameters[i]))
	return false;
    return true;
  }

  bool operator!=(const algo_types& other) const {
    return !(*this == other);
  }
  
  std::string to_string() const {
        switch(kind) {
            case BOOLEAN:   return "booléen";
            case INTEGER:   return "entier";
            case CHARACTER: return "caractère";
            case STRING:    return "chaîne";
            case ARRAY:
                if (parameters.empty()) return "tableau de ?";
                return "tableau de " + parameters[0].to_string();
            case ERROR:     return "erreur";
            default:        return "inconnu";
        }
    }

    algo_types get_base_type() const {
        if (kind != ARRAY || parameters.empty()) 
            return *this;
        return parameters[0].get_base_type();
    }
    
    size_t get_array_depth() const {
        if (kind != ARRAY) return 0;
        if (parameters.empty()) return 1;
        return 1 + parameters[0].get_array_depth();
    }
    
    std::string to_cpp_type() const {
  switch(kind) {
    case BOOLEAN:   return "bool";
    case INTEGER:   return "int";
    case CHARACTER: return "char";
    case STRING:    return "std::string";
    case ARRAY:
      if (parameters.empty()) return "std::vector<int>";
      return "std::vector<" + parameters[0].to_cpp_type() + ">";
    default: return "/*unknown*/";
  }
}
};



/*********************************
 *                               *
 * Definition of the Expressions *
 *                               *
 *********************************/



// Abstract class (interface) that represents the expressions of an algo program
class Expression {
protected:
  Expression() = default;
public:
  virtual ~Expression() = default;

  virtual std::string cpp_code(const Program& prog) const { return ""; }
  virtual algo_types infer_type(const Program&) const {return algo_types::ERROR;}
  virtual bool validate(const Program&) const { return true; }
};



/*
 * Represents a literal value of an algo program, i.e. a value represented by a string in the program. 
 * Supported literals are:
 *  - booleans <true> and <false>
 *  - natural integers represented by a sequence of didgits, e.g. <27>
 *  - character within single quotes, e.g. <'a'>
 *  - string within double quotes, e.g. <"hello world!">
 */
struct Literal : public Expression {
  const algo_types type;
  const std::string literal;
  
  Literal(algo_types type, const std::string& literal)
    : type(type), literal(literal) {}

  

  
  std::string cpp_code(const Program& prog) const override;
  algo_types infer_type(const Program&) const override;
};

/*
 * Un identifiant -> nom de variable dnas le programme
 */
struct Identifier : public Expression {
  const std::string name;

  Identifier(const std::string& name)
    : name(name) {}

  
  std::string cpp_code(const Program& prog) const override;
  algo_types infer_type(const Program&) const override;
};


/*
 * Represente une opération unaire
 * 
 * Syntaxe : oper(argument)
 */
struct UnaryOperation : public Expression {
  enum operators { AST_MOINS, AST_LONGUEUR, AST_NON, AST_LONGUEURV };
  
  const operators oper;
  const Expression* argument;
  UnaryOperation(operators oper, const Expression* argument)
    : oper(oper), argument(argument) {}

  ~UnaryOperation() override {
    if(argument) delete argument;
  }

  std::string cpp_code(const Program& prog) const override;
  algo_types infer_type(const Program&) const override;
};


/*
 * Represente operation binaire 
 * syntaxe : left oper right
 * ou: left[right] 
 */
struct BinaryOperation : public Expression {

  enum operators {
    AST_PLUS, AST_MOINS, AST_FOIS, AST_OU, AST_ET, AST_EGAL, AST_INFERIEUR, AST_INDICE
  };

  const operators oper;
  const Expression* left;
  const Expression* right;
  BinaryOperation(operators oper, const Expression* left, const Expression* right)
    : oper(oper), left(left), right(right) {}

  ~BinaryOperation() override {
    if(left) delete left;
    if(right) delete right;
  }
  std::string cpp_code(const Program& prog) const override;
  algo_types infer_type(const Program&) const override;
  
};


/**********************************
 *                                *
 * Definition des instructions    *
 *                                *
 **********************************/



// classe abstraite qui represente les instruciton du programme
class Instruction {
protected:
  Instruction() = default;
public:
  virtual ~Instruction() = default;
  virtual std::string cpp_code(const std::string& indent, const Program& prog) const { return ""; }
  virtual bool validate(const Program&) const {return true;}
};


/*
 * represente déclaration de variable
 * Syntaxe : variable_name : type
 */
struct Declaration : public Instruction {
  const std::string variable_name;
  const algo_types type;
  Declaration(const std::string& variable_name, algo_types type)
    : variable_name(variable_name), type(type) {}


  std::string cpp_code(const std::string& indent, const Program& prog) const override;

};


/*
 * Represente une séquence d'instruction dans un programme
 * Syntaxe : instructions[1] ... instructions[n]
 */
struct Sequence : public Instruction {
  
  std::vector<Instruction*> instructions;
  Sequence() {}
  ~Sequence() override {
    for(Instruction* instruction : instructions) delete instruction;
  }
  
  std::string cpp_code(const std::string& indent, const Program& prog) const override;
  bool validate(const Program&) const override;
  
};



/*
 * Représente affectation de variable
 * Syntaxe : variable <- valeur;
 */
struct Assignment : public Instruction {

  const std::string variable;
  const Expression* value;

  Assignment(const std::string& variable, const Expression* value)
    : variable(variable), value(value) {}

  ~Assignment() override {
    if(value) delete value;
  }
  std::string cpp_code(const std::string& indent, const Program& prog) const override;
  bool validate(const Program&) const override;

};


/*
 * represente un appel a la procédure lire
 * Syntaxe : lire variable;
 */
struct Read : public Instruction {

  const std::string variable;
  Read(const std::string& variable)
    : variable(variable) {}

  
  std::string cpp_code(const std::string& indent, const Program& prog) const override;
  bool validate(const Program&) const override;

};

/*
 * représente un appel à la procédure écrire
 * Syntaxe : écrire(argument);
 */
struct Write : public Instruction {
  std::vector<Expression*> arguments;
  Write(const std::vector<Expression*>& args)
    : arguments(args) {}

  ~Write() override {
    for (Expression* arg : arguments) {
            if (arg) delete arg; 
        }
  }
  std::string cpp_code(const std::string& indent, const Program& prog) const override;

};




/*
 * Represente un conditionnel 
 * Syntaxe : 
 * si condition alors
 *   thenBranch
 * sinon 
 *   elseBranch
 * fin si
 */
struct If : public Instruction {

  const Expression* condition;
  const Instruction* thenBranch;
  std::vector<std::pair<const Expression*, const Instruction*>> elseIfs;
  const Instruction* elseBranch;
  

   If(const Expression* condition, const Instruction* thenBranch)
        : condition(condition), thenBranch(thenBranch), elseBranch(nullptr) {
            elseIfs = {}; 
        }
   If(const Expression* condition, const Instruction* thenBranch, const Instruction* elseBranch)
        : condition(condition),thenBranch(thenBranch), elseBranch(elseBranch) {
            elseIfs ={};  
        }
   If(const Expression* condition, const Instruction* thenBranch, 
       std::vector<std::pair<const Expression*, const Instruction*>> elseIfs, 
       const Instruction* elseBranch)
        : condition(condition), thenBranch(thenBranch), 
          elseIfs(elseIfs), elseBranch(elseBranch) {}
  
  ~If() override {
  if (condition) delete condition;
        if (thenBranch) delete thenBranch;
        for (const auto& elseIf : elseIfs) {
            if (elseIf.first) delete elseIf.first;   
            if (elseIf.second) delete elseIf.second;
        }
        if (elseBranch) delete elseBranch;
  }
  std::string cpp_code(const std::string& indent, const Program& prog) const override;
  bool validate(const Program& prog) const override;

};

/*
 * Boucle tant que 
 */
struct While : public Instruction {
  
  const Expression* condition;
  const Instruction* body;
  While(const Expression* condition, const Instruction* body)
    : condition(condition), body(body) {}

  ~While() override {
      if(condition) delete condition;
      if(body) delete body;
  }
  std::string cpp_code(const std::string& indent, const Program& prog) const override;
  bool validate(const Program& prog) const override;

};

struct For: public Instruction {
    const std::string loop_var; 
    const Expression* start; 
    const Expression* end;
    const Expression* step;
    const Instruction* body;
    
    For(const std::string loop_var , const Expression* start , const Expression* end ,const Expression* step, const Instruction* body)
        : loop_var(loop_var) ,start(start) ,end(end), step(step) , body(body) {}
        
    ~For() override {
        if(start) delete start;
        if(end) delete end;
        if(step) delete step;
        if(body) delete body;
    }   
    std::string cpp_code(const std::string& indent, const Program& prog) const override;
    bool validate(const Program& prog) const override;
};

struct ArrayCreation : public Expression{
    algo_types array_type;
    std::vector<Expression*> dimensions;  
    
    ArrayCreation(const algo_types& arr_type, std::vector<Expression*> dims)
        : array_type(arr_type), dimensions(dims) {}
    
    ~ArrayCreation() override {
        for (auto dim : dimensions) delete dim;
    }
    std::string cpp_code(const Program& prog) const override;
    algo_types infer_type(const Program& prog) const override;
};

// Pour l'accès aux tableaux
struct ArrayAccess : public Expression {
    Expression* array;
    std::vector<Expression*> indices; 
    
    ArrayAccess(Expression* arr, std::vector<Expression*> idx)
        : array(arr), indices(idx) {}
    ~ArrayAccess() override {
        delete array;
        for(auto idx : indices) delete idx;
    }
    std::string cpp_code(const Program& prog) const override;
    algo_types infer_type(const Program& prog) const override;
};

struct ArrayAssignment : public Instruction {
    Expression* array;
    std::vector<Expression*> indices;
    Expression* value;
    
    ArrayAssignment(Expression* arr,std::vector<Expression*> idx, Expression* val)
        : array(arr),indices(idx), value(val) {}
    
    ~ArrayAssignment() override {
        delete array;
        for (auto idx : indices) delete idx;
        delete value;
    }
    
    std::string cpp_code(const std::string& indent, const Program& prog) const override;
    bool validate(const Program& prog) const override;
};


// Pour la longueur des tableaux
struct ArrayLength : public UnaryOperation {
    ArrayLength(Expression* tableau) : UnaryOperation(AST_LONGUEUR, tableau) {}
    algo_types infer_type(const Program& prog) const override;
};

struct ForEach : public Instruction {
    std::string loop_var;
    std::string array_name;
    const Instruction* body;

    ForEach(const std::string& loop_var, const std::string& array_name,const Instruction* body)
        : loop_var(loop_var), array_name(array_name),body(body) {}

    ~ForEach() override {
        if (body) delete body;
    }
    
    std::string cpp_code(const std::string& indent, const Program& prog) const override;
    bool validate(const Program& prog) const override;
};
struct Parameter {
    std::string name;
    algo_types type;
    Parameter(const std::string& n, const algo_types& t) : name(n), type(t) {}
};

struct FunctionDefinition : public Instruction {
    std::string name;
    std::vector<Parameter> params; 
    algo_types return_type;
    Sequence* body;

    FunctionDefinition(const std::string& n, const std::vector<Parameter>& p, const algo_types& r, Sequence* b)
        : name(n), params(p), return_type(r), body(b) {}

    ~FunctionDefinition() override { delete body; }
    std::string cpp_code(const std::string& indent, const Program& prog) const override;
    bool validate(const Program& prog) const override;
};

struct ProcedureDefinition : public Instruction {
    std::string name;
    std::vector<Parameter> params; 
    Sequence* body;

    ProcedureDefinition(const std::string& n, const std::vector<Parameter>& p, Sequence* b)
        : name(n), params(p), body(b) {}

    ~ProcedureDefinition() override { delete body; }
    std::string cpp_code(const std::string& indent, const Program& prog) const override;
    bool validate(const Program& prog) const override;
};

struct Return : public Instruction {
    Expression* value;
    Return(Expression* v) : value(v) {}
    ~Return() override { delete value; }
    
    std::string cpp_code(const std::string& indent, const Program& prog) const override;
    bool validate(const Program& prog) const override;
};

struct FunctionCall : public Expression {
    std::string name;
    std::vector<Expression*> arguments; 

    FunctionCall(const std::string& n,const std::vector<Expression*>& args)
        : name(n), arguments(args) {}

    ~FunctionCall() override {
        for(auto* arg :arguments)
            delete arg;
    }
    std::string cpp_code(const Program& prog) const override; 
};

struct ProcedureCall : public Instruction {
    std::string name;
    std::vector<Expression*> arguments; 
    ProcedureCall(const std::string& n, const std::vector<Expression*>& args)
        : name(n), arguments(args) {}
        
    ~ProcedureCall() override {
        for (auto* expr : arguments) delete expr;
    }
    std::string cpp_code(const std::string& indent, const Program& prog) const override;
};




/**********************************
 * *
 * Definition of the main program *
 * *
 **********************************/

struct Program {
  const std::vector<Declaration*> declarations;
  const Instruction* body;
  std::vector<Instruction*> functions;
  std::map<std::string,algo_types> symtab; //table de symboles

  Program(const std::vector<Declaration*>& decls, Instruction* b)
    : declarations(decls), body(b)
  {
    for (auto* d : declarations) {
      symtab.emplace(d->variable_name, d->type);
    }
  }

  ~Program() {
    for (auto* d : declarations) delete d;
    for (Instruction* f : functions) delete f;
    if (body) delete body;
  }

  // Commence la chaine reucrisve de génération
  std::string cpp_code() const;
  
  bool validate() const;

  //helper méthode pour trouver symbole
  algo_types lookup_type(const std::string& var) const {
    auto it = symtab.find(var);
    if (it == symtab.end()) {
      std::cerr << "Erreur interne : variable non déclarée « " << var << " »\n";
      return algo_types(algo_types::ERROR);
    }
    return it->second;
  }
  algo_types infer_type(const std::string& variable) const;
};



#endif // AST_HPP_DEFINED
