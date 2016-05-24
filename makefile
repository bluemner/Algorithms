SOURCE_FILES = main.cpp
COMPILER = g++
FLAGS =-w -ggdb -std=c++11
OUTPUT_FILE = bin/run.o
OUTPUT_DIR = bin/
SOURCE_DIR = source/
all:matrixChain smallestSubsetSumGraterThanTreshold smallestSumNearThreshold thread beta dijkstra maxSum smallestSumNearThreshold a
	
a: $(SOURCE_FILES)
	$(COMPILER) $(FLAGS) $(SOURCE_FILES) -o $(OUTPUT_FILE)
thread: test1.cpp
	$(COMPILER) $(FLAGS) -pthread test1.cpp -o $(OUTPUT_DIR)test1.o
beta: $(SOURCE_DIR)beta.cpp headers/beta.h
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)beta.cpp -o $(OUTPUT_DIR)beta.o
dijkstra: $(SOURCE_DIR)dijkstra.cpp $(SOURCE_DIR)graph.cpp
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)graph.cpp $(SOURCE_DIR)dijkstra.cpp -o $(OUTPUT_DIR)dijkstra.o
maxSum: $(SOURCE_DIR)maxSum.cpp 
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)maxSum.cpp -o $(OUTPUT_DIR)maxSum.o
graph: $(SOURCE_DIR)graph.cpp 
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)graph.cpp -o $(OUTPUT_DIR)graph.o
smallestSumNearThreshold: $(SOURCE_DIR)smallestSumNearThreshold.cpp
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)smallestSumNearThreshold.cpp -o $(OUTPUT_DIR)smallestSumNearThreshold.o
smallestSubsetSumGraterThanTreshold: $(SOURCE_DIR)smallestSubsetSumGraterThanTreshold.cpp
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)smallestSubsetSumGraterThanTreshold.cpp -o $(OUTPUT_DIR)smallestSubsetSumGraterThanTreshold.o
matrixChain: $(SOURCE_DIR)matrixChain.cpp
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)matrixChain.cpp -o $(OUTPUT_DIR)matrixChain.o
