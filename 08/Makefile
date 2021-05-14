CC=g++ -std=c++17
FLAGS=-Wall -pthread -fsanitize=address

all: threadpool.o tests.o
	$(CC) $(FLAGS) threadpool.o tests.o -o threadpool

threadpool.o: threadpool.cpp
	$(CC) $(FLAGS) threadpool.cpp -c

tests.o: tests.cpp
	$(CC) $(FLAGS) tests.cpp -c

test: threadpool.o tests.o
	$(CC) $(FLAGS) threadpool.o tests.o -o test
	./test