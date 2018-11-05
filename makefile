CFLAGS = -O
CC = g++

driver: driver.o
	$(CC) $(CFLAGS) -o driver driver.o input_node.o --std=c++11

driver.o: input_node.o driver.cpp
	$(CC) $(CFLAGS) -c driver.cpp --std=c++11

input_node.o: input_node.h input_node.cpp
	$(CC) $(CFLAGS) -c input_node.cpp --std=c++11

run:
	./driver

clean:
	rm -f core *.o
