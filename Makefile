CXX = g++
LEX = flex
YACC = bison

CXXFLAGS = -std=c++11 -W -Wall -Wextra -g -Isrc -I$(GEN_DIR) -MMD -MP
LDFLAGS = -ll -lm

SRC_DIR = src
OBJ_DIR = build/obj
GEN_DIR = build/gen

LEXER = lexer
PARSER = parser

TARGET = algo

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(OBJECTS:.o=.d) $(OBJ_DIR)/$(LEXER).d $(OBJ_DIR)/$(PARSER).d

.PHONY: all clean cleanall

all: $(TARGET)

#génération du lexer et du parser
# mkdir -p pour s'assurer que build/gen existe
$(GEN_DIR)/$(LEXER).cpp: $(SRC_DIR)/$(LEXER).lxx
	@mkdir -p $(GEN_DIR)
	$(LEX) -o$(GEN_DIR)/$(LEXER).cpp $(SRC_DIR)/$(LEXER).lxx

$(GEN_DIR)/$(PARSER).cpp: $(SRC_DIR)/$(PARSER).yxx
	@mkdir -p $(GEN_DIR)
	$(YACC) --output=$(GEN_DIR)/$(PARSER).cpp --defines=$(GEN_DIR)/$(PARSER).hpp $(SRC_DIR)/$(PARSER).yxx

# Compilation des fichiers C++
#mkdir -p pour s'assurer que build/obj existe
$(OBJ_DIR)/$(LEXER).o: $(GEN_DIR)/$(LEXER).cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/$(PARSER).o: $(GEN_DIR)/$(PARSER).cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -Wno-free-nonheap-object -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Lien de l'executable
$(TARGET): $(OBJ_DIR)/$(PARSER).o $(OBJ_DIR)/$(LEXER).o $(OBJECTS)
	$(CXX) $(OBJECTS) $(OBJ_DIR)/$(LEXER).o $(OBJ_DIR)/$(PARSER).o -o $@

-include $(DEPS)

clean:
	rm -rf build/

cleanall: clean
	rm -f $(TARGET)
