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

struct Program;

// The set of types supported in an algo program
enum class algo_types {
  BOOLEAN,
  INTEGER,
  CHARACTER,
  STRING,
  ARRAY,
  ERROR
};


struct ArrayType;

// A variant type that can represent both base types and array types
using algo_types = std::variant<base_types, ArrayType>;

// Represents an array type with its element type
struct ArrayType {
  algo_types element_type;
  
  ArrayType(algo_types element_type) : element_type(std::move(element_type)) {}
  
  bool operator==(const ArrayType& other) const {
    return element_type == other.element_type;
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

struct ArrayType : public Expression {
	
		const algo_types type;  //le type du tableau
		
		ArrayType(algo_types type) 
			:type(type){}
		
		 ~ArrayType() override = default;
		 
		 std::string cpp_code() const override;
		 algo_types infer_type(const Program&) {
			 return algo_types::ARRAY;
			 
		 }	
};

struct ArrayCreation : public Expression {
	
	const Expression* taille; // un Tableau a une taille fixe 
	const algo_types type;
	
	ArrayCreation (const Expression* taille , const algo_types type)
		:taille(taille) , type(type) {}
	
	~ArrayCreation() override {
		delete taille;
		
	}
	
	 std::string cpp_code() const override;
	 algo_types infer_type(const Program&) const override;
};

struct ArrayAccess : public Expression {
	const Expression* tableau; //on declare le tableau qu'on souhaite y accéder 
	const Expression* indice; //On accède a un tableau avec son indice 
	
	ArrayAccess ( const Expression* tableau , const Expression* indice) 
		:tableau(tableau) , indice(indice) {}
		
	~ArrayAccess() override {
		delete tableau;
		delete indice;
	}
	std::string cpp_code() const override;
	algo_types infer_type(const Program&) const override;
};

struct ArrayLength : public Expression {
	const Expression* tableau; 
	
	ArrayLength( cnst Expression* tableau) 
		:tableau(tableau) {}
	
	~ArrayLength() override {
		delete tableau;
	}
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


/**********************************
 *                                *
 * Definition of the main program *
 *                                *
 **********************************/

struct Program {

  const std::vector<Declaration*> declarations;
  const Instruction* body;

  Program(const std::vector<Declaration*> &declarations, Instruction* body) : declarations(declarations), body(body) {}

  ~Program() {
    for(Declaration* declaration : declarations)
      delete declaration;
    if(body) delete body;
  }
  
  std::string cpp_code() const;
  algo_types infer_type(const std::string&) const;
  bool validate() const;

};


#endif // AST_HPP_DEFINED
