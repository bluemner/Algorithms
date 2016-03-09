SOURCE_FILES = main.cpp
COMPILER = g++
FLAGS =-w -ggdb
OUTPUT_FILE = bin/run.o
all: a thread beta dijkstra
	
a: $(SOURCE_FILES)
	$(COMPILER) $(FLAGS) $(SOURCE_FILES) -o $(OUTPUT_FILE)
thread: test1.cpp
	$(COMPILER) $(FLAGS) -std=c++11 -pthread test1.cpp -o bin/test1.o
beta: source/beta.cpp headers/beta.h
	 $(COMPILER) $(FLAGS) -std=c++11 source/beta.cpp -o bin/beta.o
dijkstra: source/dijkstra.cpp 
	 $(COMPILER) $(FLAGS) -std=c++11 source/dijkstra.cpp -o bin/dijkstra.o
