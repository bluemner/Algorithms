SOURCE_FILES = main.cpp
COMPILER = g++
FLAGS =-w -ggdb -std=c++11 -fsanitize=address
OUTPUT_FILE = bin/run.o
OUTPUT_DIR = bin/
SOURCE_DIR = source/

all: cloth palindrome matrixSub dict huffman h1 h2 maxSizeSqaureSubMartrix matrixChain smallestSubsetSumGraterThanTreshold smallestSumNearThreshold thread beta dijkstra maxSum smallestSumNearThreshold a  
	
dict: $(SOURCE_DIR)dictionary.cpp
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)dictiosourcenary.cpp -o $(OUTPUT_DIR)dictionary.o
cloth: $(SOURCE_DIR)cloth.cpp
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)cloth.cpp -o $(OUTPUT_DIR)cloth.o
a: $(SOURCE_FILES)
	$(COMPILER) $(FLAGS) $(SOURCE_FILES) -o $(OUTPUT_FILE)
thread: test1.cpp
	$(COMPILER) $(FLAGS) -pthread test1.cpp -o $(OUTPUT_DIR)test1.o
beta: $(SOURCE_DIR)beta.cpp heade)rs/beta.h
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
matrixSub: $(SOURCE_DIR)matrixSub.cpp
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)matrixSub.cpp -o $(OUTPUT_DIR)matrixSub.o
maxSizeSqaureSubMartrix: $(SOURCE_DIR)maxSizeSqaureSubMartrix.cpp
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)maxSizeSqaureSubMartrix.cpp -o $(OUTPUT_DIR)maxSizeSqaureSubMartrix.o
h1: $(SOURCE_DIR)h1.cpp 
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)h1.cpp -o $(OUTPUT_DIR)h1.o
h2: $(SOURCE_DIR)h2.cpp 
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)h2.cpp -o $(OUTPUT_DIR)h2.o
huffman: $(SOURCE_DIR)huffman.cpp 
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)huffman.cpp -o $(OUTPUT_DIR)huffman.o
palindrome: $(SOURCE_DIR)palindrome.cpp
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)palindrome.cpp -o $(OUTPUT_DIR)palindrome.o
divisor: $(SOURCE_DIR)divisor.cpp
	$(COMPILER) $(FLAGS) $(SOURCE_DIR)divisor.cpp -o $(OUTPUT_DIR)divisor.o
