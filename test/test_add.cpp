#include <pybind11/pybind11.h>

namespace py = pybind11;

int add(int a, int b) {
    return a + b;
}

PYBIND11_MODULE(addition, m) {
    m.doc() = "CPP to Python integration test.";

    m.def("add", &add, "A simple function to add two numbers.");
}
