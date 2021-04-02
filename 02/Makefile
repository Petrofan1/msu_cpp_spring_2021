CC=g++ -std=c++17
FLAGS=-Wall -fsanitize=address -Wextra

all: parser.o tests.o
	$(CC) $(FLAGS) parser.o tests.o -o parser

parser.o: parser.cpp
	$(CC) $(FLAGS) parser.cpp -c

tests.o: tests.cpp
	$(CC) $(FLAGS) tests.cpp -c

test: parser.o tests.o
	$(CC) $(FLAGS) parser.o tests.o -o test
	./test