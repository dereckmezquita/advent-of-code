#ifndef CPP_BENCHMARK_H
#define CPP_BENCHMARK_H

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

double median(std::vector<int>& vec);

void benchmark(void (*func)(), int num_runs, bool silent = false);

#endif //CPP_BENCHMARK_H


