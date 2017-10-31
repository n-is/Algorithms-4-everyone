#
# -*- Makefile -*-
#
# Created      : 10/31/2017 22:41:57
# Author       : n-is
# email        : 073bex422.nischal@pcampus.edu.np
#

TARGET = String
TEST_TARGETS = \
		tests/bin/test_main \
		tests/bin/test_constructors \
		tests/bin/test_ops \

CC = gcc

CXX = g++
CXXFLAGS =  -Wall -g -std=c++14 -O1

CXXSRC = codes/String.cpp

TESTSRC = \
	tests/test_main.cpp \
	tests/test_constructors.cpp \
	tests/test_ops.cpp

OBJ = $(CXXSRC:.cpp=.o)
DEP = $(OBJ:.o=.d)

TESTOBJ = $(TESTSRC:.cpp=.o)
TESTDEP = $(TESTOBJ:.o=.d)

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@
	@ echo "\n\t\tAll Done. Thank You\n"

%.d : %.cpp
	$(CPP) $< -MM -MT $(@:.d=.o) >$@

-include $(DEP)
-include $(TESTDEP)

.PHONY : clean CleanDep makeDebug syntax

syntax :
	$(CXX) $(CXXFLAGS) -fsyntax-only $(CXXSRC)
	@ echo "\n\t\tSyntax Checked\n"

clean :
	rm -f $(OBJ) $(TARGET)
	rm -f $(TESTOBJ) $(TEST_TARGETS) $(TESTDEP)
	@ echo "\n\t\tEverything Cleaned Up\n"

cleanDep :
	rm -f $(DEP)
	@ echo "\n\t\tDependencies Cleaned Up\n"

cleanTest :
	rm -f $(TESTOBJ) $(TEST_TARGETS) $(TESTDEP)
	@ echo "\n\t\tTests Cleaned Up\n"

makeDebug :
	@ echo $(CXXSRC)
	@ echo $(OBJ)
	@ echo $(DEP)

test : $(TEST_TARGETS)

$(TEST_TARGETS) : $(TESTOBJ) $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

runTest : 
	./tests/bin/test_main
	./tests/bin/test_constructors
	./tests/bin/test_ops
