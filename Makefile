SRC=src
MAIN=turingSimulator
EXAMPLES=examples

SRC_DIR := src
OBJ_DIR := src
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: $(OBJ_FILES)
	g++ $(LDFLAGS) -o $@ $^ -I $(SRC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $< -I $(SRC)

clear:
	#rm $(MAIN)
	rm $(SRC)/*.o