#include <iostream>

#include "headers/d2p2.h"
#include "modules/benchmark.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    benchmark(d2p2::run, 10, false);
    return 0;
}