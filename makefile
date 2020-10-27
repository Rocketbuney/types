CC=g++
CXXFLAGS=-Wall -ansi -I./include/ -c
BIN_DIR=bin/
LIB_DIR=lib/

$(LIB_DIR)types.a: $(BIN_DIR)linear_list.o
	ar -rc $@ $(BIN_DIR)*.o

$(BIN_DIR)linear_list.o: include/types.h include/list.h src/linear_list.cpp | directories
	$(CC) $(CXXFLAGS) src/linear_list.cpp -o $@

directories: 
	mkdir -p $(BIN_DIR)
	mkdir -p $(LIB_DIR)
