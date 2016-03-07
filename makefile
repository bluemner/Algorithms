SOURCE_FILES = main.cpp
COMPILER = g++
FLAGS =-w -ggdb
OUTPUT_FILE = bin/run.o
all: $(SOURCE_FILES)
	$(COMPILER) $(FLAGS) $(SOURCE_FILES) -o $(OUTPUT_FILE)
thread: test1.cpp
	$(COMPILER) $(FLAGS) -std=c++11 -pthread test1.cpp -o bin/test1.o
