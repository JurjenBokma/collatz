# collatz
A bit of code to play with Github, Python, C++ and more

Largely following these tutorials:
* https://realpython.com/python-bindings-overview/#pybind11
* https://people.duke.edu/~ccc14/sta-663-2017/12B_C++_Python_pybind11.html

we make C++ functions available to Python.
That speeds the Collatz competition up by around a factor 30.

The C++-used-by-Python example will so far only work on Linux.
Make will run into errors unless at least the following packages (on Debian)
are installed:

* python3-pybind11
* pybind11-dev
* libpython3.7-dev (or newer)
* python3-dev (or newer)
* g++ (a recent version)

When they are, simply calling 'make' should suffice to build the Python module.
