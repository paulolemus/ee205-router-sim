# EE 205 Assignment 3 makefile
CXX := c++

TOP_DIR := $(shell pwd)
TEST_FILES := $(wildcard tests/*.cpp)
TEST_EXECUTABLES := $(TEST_FILES:.cpp=.out)

ifdef TESTCASE
TEST_SINGLE_FILE := $(addprefix tests/, $(addsuffix .cpp, $(TESTCASE)))
TEST_SINGLE_EXECUTABLE := $(addprefix tests/, $(addsuffix .out, $(TESTCASE)))
else
TESTCASE := $(shell echo $$TESTCASE)
TEST_SINGLE_FILE := $(addprefix tests/, $(addsuffix .cpp, $(TESTCASE)))
TEST_SINGLE_EXECUTABLE := $(addprefix tests/, $(addsuffix .out, $(TESTCASE)))
endif

TESTINCLUDEDIR = -I./dep/
TESTLIBS = -lgtest -lpthread

CXX_FLAGS := -Wall -Wextra -pedantic --std=c++11 -g
TEST_FLAGS := -Wall -Wextra -pedantic --std=c++11 -g \
			  $(TESTINCLUDEDIR) $(TESTLIBS)

all: 


main-queue: main-queue.cpp
	g++ main-queue.cpp -o bin/main-queue $(CXX_FLAGS)

tests: $(TEST_EXECUTABLES)

test: $(TEST_SINGLE_EXECUTABLE)
	@echo "Test case: " $(value TESTCASE)

run-test: $(TEST_SINGLE_EXECUTABLE)
	@echo "Test case: " $(value TESTCASE)
	cd ./tests/
	$(TEST_SINGLE_EXECUTABLE)
	cd ../

$(TEST_SINGLE_EXECUTABLE): $(TEST_SINGLE_FILE)
	$(CXX) -o $@ $^ $(TEST_FLAGS)

tests/%.out: tests/%.cpp
	$(CXX) -o $@ $^ $(TEST_FLAGS)

clean-tests:
	rm tests/*.out
