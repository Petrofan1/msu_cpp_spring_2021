CC=g++ -std=c++17
FLAGS=-Wall -Werror -fsanitize=address -Wextra

all: allocator.o tests.o
	$(CC) $(FLAGS) allocator.o tests.o -o allocator

allocator.o: allocator.cpp
	$(CC) $(FLAGS) allocator.cpp -c

tests.o: tests.cpp
	$(CC) $(FLAGS) tests.cpp -c

test: allocator.o tests.o
	$(CC) $(FLAGS) allocator.o tests.o -o test
	./test