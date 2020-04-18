#!/usr/bin/make

CXXFLAGS += -Wall -Werror -std=c++2a -O3 -fPIC

CXX_PROG_SOURCES = collatz++.cc
CXX_PROG_OBJECTS = $(patsubst %.cc,%.o,$(CXX_PROG_SOURCES))
CXX_PROGRAMS = $(patsubst %.cc,%,$(CXX_PROG_SOURCES))

CXX_SOURCES = $(wildcard collatz/*.cc)
CXX_LIB_SOURCES = $(filter-out $(CXX_PROG_SOURCES),$(CXX_SOURCES))
CXX_LIB_OBJECTS = $(patsubst %.cc,%.o,$(CXX_LIB_SOURCES))

PROGRAMS = $(CXX_PROGRAMS)
STATIC_LIB = libcollatz.a
DYNAMIC_LIB = libcollatz.so.1

all: $(PROGRAMS) $(DYNAMIC_LIB)

$(CXX_LIB_OBJECTS) $(CXX_PROG_OBJECTS): %.o: %.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

$(CXX_PROGRAMS): %: %.o libcollatz.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

collatz++: LDFLAGS += -L. -lcollatz

libcollatz.a: $(CXX_LIB_OBJECTS)
	ar rcs $@ $(filter %.o,$^)

$(DYNAMIC_LIB): $(CXX_LIB_OBJECTS)
	$(CXX) $(CXXFLAGS) -shared -Wl,-soname,$@ -o $@ $(CXX_LIB_OBJECTS)
	strip $@

clean:
	rm -f $(CXX_LIB_OBJECTS) $(CXX_PROG_OBJECTS) $(PROGRAMS) $(STATIC_LIB) $(DYNAMIC_LIB)

.PHONY: clean
