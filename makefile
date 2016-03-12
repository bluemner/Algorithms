SOURCE_FILES = main.cpp
COMPILER = g++
FLAGS =-w -ggdb
OUTPUT_FILE = bin/run.o
OUTPUT_DIR = bin/
all: a thread beta dijkstra maxSum
	
a: $(SOURCE_FILES)
	$(COMPILER) $(FLAGS) $(SOURCE_FILES) -o $(OUTPUT_FILE)
thread: test1.cpp
	$(COMPILER) $(FLAGS) -std=c++11 -pthread test1.cpp -o $(OUTPUT_DIR)test1.o
beta: source/beta.cpp headers/beta.h
	$(COMPILER) $(FLAGS) -std=c++11 source/beta.cpp -o $(OUTPUT_DIR)beta.o
dijkstra: source/dijkstra.cpp 
	$(COMPILER) $(FLAGS) -std=c++11 source/dijkstra.cpp -o $(OUTPUT_DIR)dijkstra.o
maxSum: source/maxSum.cpp 
	$(COMPILER) $(FLAGS) -std=c++11 source/maxSum.cpp -o $(OUTPUT_DIR)maxSum.o
