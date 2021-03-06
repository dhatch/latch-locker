CXX=g++
OFLAG=-O3
CXXFLAGS=-pthread -g --std=c++0x -I$(CURDIR) $(OFLAG)

DIRS=util lock_managers hashtable tester txn
SOURCES :=
BINS :=
OBJECTS = $(patsubst %.cc, %.o, $(SOURCES))

all:

include $(patsubst %, %/Makefile.inc, $(DIRS))

BINS += test_all
test_all: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: all
all: $(OBJECTS) $(BINS)

.PHONY: clean
clean:
	rm `find . '-name' '*.o'`
	rm -f $(BINS)

.PHONY: test-dbg
test-dbg: OFLAG = -O0
test-dbg: test

.PHONY: test
test: test_all
	./test_all
