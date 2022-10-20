CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: llrec-test.o llrec.o
	$(CXX) $(CXXFLAGS) -o $@ $^

llrec-test.o: llrec-test.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c llrec-test.cpp

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -o $@ -c llrec.cpp

stack-test: stack-test.cpp stack.h
	$(CXX) $(CXXFLAGS) -o $@ stack-test.cpp

clean:
	rm -f *.o rh llrec-test stack-test *~

valgrind-llrec-test:
	$(VALGRIND) ./llrec-test llrec-test1.txt

valgrind-stack-test:
	$(VALGRIND) ./stack-test

.PHONY: clean valgrind-llrec-test valgrind-stack-test