#include <iostream>

#include "headers/d2p1.h"
#include "modules/benchmark.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    benchmark(d2p1::hello, 10, true);
    return 0;
}