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

# GoogleTest Stuff
GTEST_DIR = $(TOP_DIR)/dep/googletest

TESTINCLUDEDIR = -I$(TOP_DIR)
TESTLIBS =  -pthread \
			-isystem $(GTEST_DIR)/include libgtest.a

CXX_FLAGS := -Wall -Wextra -pedantic --std=c++11 -g
TEST_FLAGS := -Wall -Wextra -pedantic --std=c++11 -g \
			  $(TESTINCLUDEDIR) $(TESTLIBS)

#############################################################################
## Add all new targets below this line

all: router RPC

router: router-sim.cpp
	g++ router-sim.cpp -o router $(CXX_FLAGS)

RPC: RPC.cpp
	g++ RPC.cpp -o RPC $(CXX_FLAGS)
	
## Do not edit after this line
##############################################################################

### TESTCASE BUILD TARGETS

DEP_FOLLOW = ar -rv libgtest.a gtest-all.o

deps: 
	g++ -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) \
	-pthread -c $(GTEST_DIR)/src/gtest-all.cc
	$(DEP_FOLLOW)

tests: deps $(TEST_EXECUTABLES)

test: deps $(TEST_SINGLE_EXECUTABLE)
	@echo "Test case: " $(value TESTCASE)

run-test: deps $(TEST_SINGLE_EXECUTABLE)
	@echo "Test case: " $(value TESTCASE)
	cd ./tests/
	$(TEST_SINGLE_EXECUTABLE)
	cd ../

$(TEST_SINGLE_EXECUTABLE): $(TEST_SINGLE_FILE)
	$(CXX) -o $@ $^ $(TEST_FLAGS)

tests/%.out: tests/%.cpp
	$(CXX) -o $@ $^ $(TEST_FLAGS)

##############################################################################

### CLEAN RULES
.PHONY: clean-build clean-tests clean-deps clean

clean-build:
	-rm router RPC

clean-tests:
	-rm tests/*.out

clean-deps:
	-rm -r libgtest.a gtest-all.o

clean: clean-tests clean-deps clean-build
