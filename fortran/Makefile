F90 = gfortran
OBJ = obj
BIN = bench

BIN:
	$(F90) -J$(OBJ) -O3 -c src/util/util.f90 -o $(OBJ)/util.o
	$(F90) -J$(OBJ) -I$(OBJ) -O3 -c src/core/core.f90 -o $(OBJ)/core.o
	$(F90) -I$(OBJ) -O3 -c src/main.f90 -o $(OBJ)/main.o
	$(F90) -I$(OBJ) $(OBJ)/util.o $(OBJ)/core.o $(OBJ)/main.o -o bench

.PHONY: clean
clean:
	@rm $(OBJ)/*
	@rm bench
