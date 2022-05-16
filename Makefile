CC=g++
CFLAGS =-c -Wall
CXX = clang++

hello: main.o
	$(CC) main.o -o hello

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

unit_test: unit_test_driver.o
	$(CXX) unit_test_driver.o

clean:
	rm -rf *.o hello