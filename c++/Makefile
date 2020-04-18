#!/usr/bin/make

CXXFLAGS += -Wall -Werror -std=c++2a -O3 -fPIC

PYTHON_EXTENSION_SUFFIX = $(shell python3.7-config --extension-suffix)
PES = $(PYTHON_EXTENSION_SUFFIX)

CXX_PROG_SOURCES = collatz++.cc
CXX_PROG_OBJECTS = $(patsubst %.cc,%.o,$(CXX_PROG_SOURCES))
CXX_PROGRAMS = $(patsubst %.cc,%,$(CXX_PROG_SOURCES))

CXX_SOURCES = $(wildcard collatz/*.cc)
CXX_NOT_LIB_SOURCES = $(CXX_PROG_SOURCES) collatz/collatzpp.cc
CXX_LIB_SOURCES = $(filter-out $(CXX_NOT_LIB_SOURCES),$(CXX_SOURCES))
CXX_LIB_OBJECTS = $(patsubst %.cc,%.o,$(CXX_LIB_SOURCES))

PROGRAMS = $(CXX_PROGRAMS)
STATIC_LIB = libcollatz.a
DYNAMIC_LIB = libcollatz.so.1

PYTHON_BINDING_LIB = collatz/collatzpp$(PES)

SODIR = $(dir $(abspath $@))

all: $(PROGRAMS) $(DYNAMIC_LIB) $(PYTHON_BINDING_LIB)

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

$(PYTHON_BINDING_LIB):
$(PYTHON_BINDING_LIB): CXXFLAGS += -O3 -Wall -Werror -shared -std=c++2a -fPIC $(shell python3 -m pybind11 --includes) -I /usr/include/python3.7 -I . -I collatz
$(PYTHON_BINDING_LIB): LDFLAGS += -L. -lcollatz -Wl,-rpath,.

%$(PES): %.cc $(DYNAMIC_LIB)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f $(CXX_LIB_OBJECTS) $(CXX_PROG_OBJECTS) $(PROGRAMS) $(STATIC_LIB) $(DYNAMIC_LIB) $(PYTHON_BINDING_LIB)

.PHONY: clean
