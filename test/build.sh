c++ -O3 -Wall -shared -std=c++17 -fPIC $(python3 -m pybind11 --includes) test_gphl.cpp -o graphlib.so
