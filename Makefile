EXAMPLES=examples

SRC_DIR := src
OBJ_DIR := obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: create_path turingSimulator

turingSimulator: $(OBJ_FILES)
	g++ -g $(LDFLAGS) -o $@ $^ -I $(SRC_DIR) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ -g $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $< -I $(SRC_DIR)

create_path:
	mkdir -p $(OBJ_DIR)

clear:
	rm -f turingSimulator
	rm -f -r $(OBJ_DIR)

example:
	./turingSimulator -in $(EXAMPLES)/example1.txt 