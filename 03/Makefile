CC=g++ -std=c++17
FLAGS=-Wall -fsanitize=address -Wextra

all: matrix.o tests.o
	$(CC) $(FLAGS) matrix.o tests.o -o matrix

matrix.o: matrix.cpp
	$(CC) $(FLAGS) matrix.cpp -c

tests.o: tests.cpp
	$(CC) $(FLAGS) tests.cpp -c

test: matrix.o tests.o
	$(CC) $(FLAGS) matrix.o tests.o -o test
	./test