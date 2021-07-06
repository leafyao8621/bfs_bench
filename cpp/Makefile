CPP = g++
SRC = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
OBJ = $(SRC:.cpp=.o)
BIN = bench

%.o: %.cpp
	$(CPP) -O3 -c $< -o $@

$(BIN): $(OBJ)
	$(CPP) $(OBJ) -o $(BIN)

.PHONY: clean
clean:
	@rm $(OBJ)
	@rm $(BIN)
