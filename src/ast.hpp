#ifndef AST_HPP_DEFINED
#define AST_HPP_DEFINED

/**
 * \file ast.hpp
 * \brief Header file containing the declarations of the abstract syntax tree.
 * \author Matthieu Perrin 
 * \version 1
 * \date 17-02-2025
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

	

    // Add this method to get the base type (for nested arrays)
    algo_types get_base_type() const {
        if (kind != ARRAY || parameters.empty()) 
            return *this;
        return parameters[0].get_base_type();
    }

    // Add this method to get array dimensions
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
      if (parameters.empty()) return "std::vector<int>"; // default fallback
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

  virtual std::string cpp_code() const {return "";}
  virtual algo_types infer_type(const Program&) const {return algo_types::ERROR;}
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

  ~Literal() override = default;

  std::string cpp_code() const override;
  algo_types infer_type(const Program&) const override;

};

/*
 * Represents an identifier, i.e. a variable name of an algo program
 */
struct Identifier : public Expression {

  const std::string name;

  Identifier(const std::string& name)
    : name(name) {}

  ~Identifier() override = default;

  std::string cpp_code() const override;
  algo_types infer_type(const Program&) const override;
    
};


/*
 * Represents a unary operation an algo program
 * The accepted operators are provided in the operators enumeration  
 * Syntax : 
 *   oper(argument)
 */
struct UnaryOperation : public Expression {

  enum operators {
    MOINS, LONGUEUR, NON
  };
  
  const operators oper;
  const Expression* argument;
  
  UnaryOperation(operators oper, const Expression* argument)
    : oper(oper), argument(argument) {}

  ~UnaryOperation() override {
    if(argument) delete argument;
  }

  std::string cpp_code() const override;
  algo_types infer_type(const Program&) const override;
  
};



/*
 * Represents a binary operation an algo program
 * The accepted operators are provided in the operators enumeration  
 * Syntax : 
 *   left oper right
 * Or :
 *   left[right] 
 */
struct BinaryOperation : public Expression {

  enum operators {
    PLUS, MOINS, FOIS, OU, ET, EGAL, INFERIEUR, INDICE
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

  std::string cpp_code() const override;
  algo_types infer_type(const Program&) const override;
  
};


/**********************************
 *                                *
 * Definition of the instructions *
 *                                *
 **********************************/



// Abstract class (interface) that represents the instructions of an algo program
class Instruction {
protected:
  Instruction() = default;
public:
  virtual ~Instruction() = default;

  virtual std::string cpp_code(const std::string&) const {return "";}
  virtual bool validate(const Program&) const {return true;}
};


/*
 * Represents a variable declaration
 * Syntax : 
 * variable_name : type
 */
struct Declaration : public Instruction {
  
  const std::string variable_name;
  const algo_types type;

  Declaration(const std::string& variable_name, algo_types type)
    : variable_name(variable_name), type(type) {}

  ~Declaration() override = default;

  std::string cpp_code(const std::string&) const override;

};


/*
 * Represents a sequence of instructions in an algo program
 * Syntax : 
 * instructions[1]
 * ...
 * instructions[n]
 */
struct Sequence : public Instruction {
  
  std::vector<Instruction*> instructions;

  Sequence() {}

  ~Sequence() override {
    for(Instruction* instruction : instructions) delete instruction;
  }
  
  std::string cpp_code(const std::string&) const override;
  bool validate(const Program&) const override;
  
};



/*
 * Represents a variable assignment in an algo program
 * Syntax : 
 * variable <- value;
 */
struct Assignment : public Instruction {

  const std::string variable;
  const Expression* value;

  Assignment(const std::string& variable, const Expression* value)
    : variable(variable), value(value) {}

  ~Assignment() override {
    if(value) delete value;
  }
  
  std::string cpp_code(const std::string&) const override;
  bool validate(const Program&) const override;

};



/*
 * Represents a call of an algo program to the procedure lire
 * Syntax : 
 * lire variable;
 */
struct Read : public Instruction {

  const std::string variable;

  Read(const std::string& variable)
    : variable(variable) {}

  ~Read() override = default;
  
  std::string cpp_code(const std::string&) const override;
  bool validate(const Program&) const override;

};

/*
 * Represents a call of an algo program to the procedure écrire
 * Syntax : 
 * écrire(argument);
 */
struct Write : public Instruction {
  std::vector<Expression*> arguments;
  
  Write(const std::vector<Expression*>& args)
    : arguments(args) {}

  ~Write() override {
    for (Expression* arg : arguments) {
            if (arg) delete arg;  // Delete each argument
        }
  }
  
  std::string cpp_code(const std::string&) const override;

};




/*
 * Represents a conditional structure of an algo program
 * Syntax : 
 * si condition alors
 *   thenBranch
 * sinon 
 *   elseBranch
 * fin si
 */
struct If : public Instruction {

  const Expression*  condition;
  const Instruction* thenBranch;
  std::vector<std::pair<const Expression*, const Instruction*>> elseIfs;
  const Instruction* elseBranch;
  
  
	//Juste le si normale
	 If(const Expression* condition, const Instruction* thenBranch)
        : condition(condition), thenBranch(thenBranch), elseBranch(nullptr) {
            elseIfs = {};  // Initialise elseIfs comme une liste vide
        }
	
	//un si sinon
   If(const Expression* condition, const Instruction* thenBranch, const Instruction* elseBranch)
        : condition(condition), thenBranch(thenBranch), elseBranch(elseBranch) {
            elseIfs = {};  // Initialise elseIfs comme une liste vide
        }
	// un si sinon si 
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
  std::string cpp_code(const std::string&) const override;
  bool validate(const Program&) const override;

};



/*
 * Represents a while loop of an algo program
 * Syntax : 
 * tant que condition faire
 *   body
 * fin tant que
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

  std::string cpp_code(const std::string&) const override;
  bool validate(const Program&) const override;

};

struct For: public Instruction {
	const std::string loop_var; 
    const Expression* start;
    const Expression* end;
    const Expression* step;
    const Instruction* body;
    
    For(const std::string loop_var , const Expression* start , const Expression* end , const Expression* step, const Instruction* body)
		: loop_var(loop_var) , start(start) , end(end), step(step) , body(body) {}
		
	~For() override {
		if(start) delete start;
		if(end) delete end;
		if(step) delete step;
		if(body) delete body;
	}	
	std::string cpp_code(const std::string&) const override;
	bool validate(const Program&) const override;
};

struct ArrayCreation : public Expression {
    algo_types array_type;
    std::vector<Expression*> dimensions;  
    
    
    
   ArrayCreation(const algo_types& arr_type, std::vector<Expression*> dims)
        : array_type(arr_type), dimensions(dims) {}
    
    ~ArrayCreation() override {
        for (auto dim : dimensions) delete dim;
    }
    
    std::string cpp_code() const override;
    algo_types infer_type(const Program&) const override;
};

// Pour l'accès aux tableaux
struct ArrayAccess : public Expression {
    Expression* array;
    std::vector<Expression*> indices;  // Multiple indices for nested arrays
    
    ArrayAccess(Expression* arr, std::vector<Expression*> idx)
        : array(arr), indices(idx) {}
    
    ~ArrayAccess() override {
        delete array;
        for (auto idx : indices) delete idx;
    }
    
    std::string cpp_code() const override;
    algo_types infer_type(const Program&) const override;
};

struct ArrayAssignment : public Instruction {
    Expression* array;
    std::vector<Expression*> indices;
    Expression* value;
    
    ArrayAssignment(Expression* arr, std::vector<Expression*> idx, Expression* val)
        : array(arr), indices(idx), value(val) {}
    
    ~ArrayAssignment() override {
        delete array;
        for (auto idx : indices) delete idx;
        delete value;
    }
    
    std::string cpp_code(const std::string& indent) const override;
	bool validate(const Program&) const override;
};


// Pour la longueur des tableaux
struct ArrayLength : public UnaryOperation {
    ArrayLength(Expression* tableau) : UnaryOperation(LONGUEUR, tableau) {}
    algo_types infer_type(const Program&) const override;
};


/**********************************
 *                                *
 * Definition of the main program *
 *                                *
 **********************************/

#include <map>
#include <string>
#include <vector>
#include "ast.hpp"  // for Declaration, Instruction, algo_types

struct Program {
  // your existing fields
  const std::vector<Declaration*> declarations;
  const Instruction*      body;

  // new symbol‑table mapping var names → their declared types
  std::map<std::string,algo_types> symtab;

  // ctor: build symtab
  Program(const std::vector<Declaration*>& decls,
          Instruction* b)
    : declarations(decls), body(b)
  {
    for (auto* d : declarations) {
  symtab.emplace(d->variable_name, d->type);
	}
  }

  // dtor stays the same
  ~Program() {
    for (auto* d : declarations) delete d;
    if (body) delete body;
  }

  // your existing methods
  std::string cpp_code() const;
  bool validate() const;

  // helper: given a variable name, return its declared algo_type
  // you can call this from your parser or from Assignment/ArrayCreation
  algo_types lookup_type(const std::string& var) const {
    auto it = symtab.find(var);
    if (it == symtab.end()) {
      std::cerr << "Erreur interne : variable non déclarée « " << var << " »\n";
      return algo_types(algo_types::ERROR);
    }
    return it->second;
  }

  // (optionally) repurpose infer_type(string) to be identical:
  algo_types infer_type(const std::string& variable) const;
};




#endif // AST_HPP_DEFINED
