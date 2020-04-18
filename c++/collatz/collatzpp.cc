#include <pybind11/pybind11.h>
#include <collatz.hh>

// I got this working only if the dynamic library file compiled from this source
// has the same name as the module - collatzpp.
PYBIND11_MODULE(collatzpp, m) {
    m.doc() = "Collatz-related functions";
    m.def("find_winner", &find_winner2, "A function that finds from a range the number that has the greatest Collatz count");
    m.def("collatz", &collatz, "The Collatz function");
    m.def("collatz_count", &collatz_count, "A function that counts the number of times the Collatz function has to be applied to get to 1");
}
