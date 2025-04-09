CXX = g++
LEX = flex
YACC = bison

CXXFLAGS = -W -Wall -Wextra -g -Isrc -MMD -MP
LDFLAGS = -ll -lm

SRC_DIR = src
OBJ_DIR = build/obj
GEN_DIR = build/gen

LEXER = lexer
PARSER = parser

TARGET = algo

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(OBJECTS:.o=.d) $(GENERATED_OBJECTS:.o=.d)

.PHONY: all clean cleanall

all: $(TARGET)

# Generate lexer and parser

$(GEN_DIR)/$(LEXER).cpp: $(SRC_DIR)/$(LEXER).lxx
	$(LEX) -o$(GEN_DIR)/$(LEXER).cpp $(SRC_DIR)/$(LEXER).lxx

$(GEN_DIR)/$(PARSER).cpp: $(SRC_DIR)/$(PARSER).yxx
	$(YACC) --output=$(GEN_DIR)/$(PARSER).cpp --defines=$(GEN_DIR)/$(PARSER).hpp $(SRC_DIR)/$(PARSER).yxx

# Compile c++ files
$(OBJ_DIR)/$(LEXER).o: $(GEN_DIR)/$(LEXER).cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/$(PARSER).o: $(GEN_DIR)/$(PARSER).cpp
	$(CXX) $(CXXFLAGS) -Wno-free-nonheap-object -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link executable
$(TARGET): $(OBJ_DIR)/$(PARSER).o $(OBJ_DIR)/$(LEXER).o $(OBJECTS)
	$(CXX) $(OBJECTS) $(OBJ_DIR)/$(LEXER).o $(OBJ_DIR)/$(PARSER).o -o $@

-include $(DEPS)

# Delete generated files
clean:
	rm -f $(OBJ_DIR)/*
	rm -f $(GEN_DIR)/*

cleanall: clean
	rm -f $(TARGET)
