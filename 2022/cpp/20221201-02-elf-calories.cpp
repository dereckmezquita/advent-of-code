#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <chrono>
#include <algorithm>
#include <sstream>

std::string file = "../../data/20221201-calories-per-elf.txt";

int version2() {
    std::ifstream inputFile(file);
    if (!inputFile) {
        std::cerr << "Unable to open file: " << file << std::endl;
        return 1;
    }

    std::vector<int> elves;
    int currentElf = 0;
    std::string line;
    while (getline(inputFile, line)) {
        // each elf is a group of numbers over multiple lines; each elf separated by an empty line
        // we want to calculate the sum of each elf and then find the max sum
        if (line.empty()) {
            elves.push_back(currentElf);
            currentElf = 0;
        } else {
            currentElf += std::stoi(line);
        }
    }

    // int maxCalories = *std::max_element(elves.begin(), elves.end());
    // sort in descending order
    std::sort(elves.begin(), elves.end(), std::greater<>());
    int totalCalories = elves[0] + elves[1] + elves[2];

    std::cout << "Total calories carried by top 3 Elves: " << totalCalories << std::endl;

    return 0;
}

template <typename Func>
void benchmark(Func func, int num_runs, bool silent = false) {
    std::streambuf* orig_cout = std::cout.rdbuf();
    std::ostringstream dev_null;
    if (silent) {
        std::cout.rdbuf(dev_null.rdbuf());
    }

    std::chrono::duration<double> total_time(0.0);
    for (int j = 0; j < num_runs; ++j) {
        auto start_time = std::chrono::high_resolution_clock::now();
        func();
        auto end_time = std::chrono::high_resolution_clock::now();
        total_time += end_time - start_time;
    }

    std::cout.rdbuf(orig_cout);  // Restore original cout buffer

    double average_time = total_time.count() / num_runs;
    std::cout << "Function took an average of: " << average_time << " seconds" << std::endl;
}

int main() {
    int num_runs = 1;
    benchmark(version2, num_runs, true);
    return 0;
}