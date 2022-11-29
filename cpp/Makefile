CC = g++
LANG_STD = -std=c++17
COMPILER_FLAGS = -Wall -Wfatal-errors
INCLUDE_PATH = -I"./headers/"
SRC_FILES = ./src/*.cpp
LINKER_FLAGS = ""
OBJ_NAME = chamada 

build:
	$(CC) $(COMPILER_FLAGS) $(LANG_STD) $(INCLUDE_PATH) $(SRC_FILES) -o $(OBJ_NAME)
	mv $(OBJ_NAME) ./bin

run:
	./bin/$(OBJ_NAME)

clean:
	rm ./bin/$(OBJ_NAME)
	
index:
	bear --	$(CC) $(COMPILER_FLAGS) $(LANG_STD) $(INCLUDE_PATH) $(SRC_FILES)


