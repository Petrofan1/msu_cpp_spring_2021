CC=g++ -std=c++17
FLAGS=-Wall -Werror -fsanitize=address -Wextra

all: serializer.o tests.o
	$(CC) $(FLAGS) serializer.o tests.o -o serializer

serializer.o: serializer.cpp
	$(CC) $(FLAGS) serializer.cpp -c

tests.o: tests.cpp
	$(CC) $(FLAGS) tests.cpp -c

test: serializer.o tests.o
	$(CC) $(FLAGS) serializer.o tests.o -o test
	./test