CC = g++
STD = c++17
FLAGS = -c -g -Wall -pedantic -Werror -I .
OBJ = main.o
DEP = main.cpp
TGT = main

$(TGT): $(OBJ)
	$(CC) -o $(TGT) $(OBJ)

$(OBJ): $(DEP)
	$(CC) -std=$(STD) $(FLAGS) -o $(OBJ) main.cpp

clean:
	rm -f $(TGT) $(OBJ)
