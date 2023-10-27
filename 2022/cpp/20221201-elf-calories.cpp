#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <chrono>

std::string file = "../../data/20221201-calories-per-elf.txt";

int version1() {
    std::ifstream inputFile(file);
    if (!inputFile) {
        std::cerr << "Unable to open file: " << file << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> elves;
    std::vector<int> currentElf;
    std::string line;
    while (getline(inputFile, line)) {
        if (line.empty()) { // empty line indicates end of a group
            if (!currentElf.empty()) { // don't add empty groups
                elves.push_back(currentElf);
                currentElf.clear();
            }
        } else {
            currentElf.push_back(std::stoi(line)); // convert string to int
        }
    }

    if (!currentElf.empty()) { // add last group if file doesn't end with an empty line
        elves.push_back(currentElf);
    }

    inputFile.close();

    std::vector<int> elvesTotalCalories;
    for (size_t i = 0; i < elves.size(); ++i) {
        int sum = std::accumulate(elves[i].begin(), elves[i].end(), 0);

        elvesTotalCalories.push_back(sum);
    }

    int maxCalories = *std::max_element(elvesTotalCalories.begin(), elvesTotalCalories.end());

    // std::cout << "Elf max calories: " << maxCalories << std::endl;

    return 0;
}

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

    int maxCalories = *std::max_element(elves.begin(), elves.end());
    // std::cout << "Elf max calories: " << maxCalories << std::endl;

    return 0;
}

void benchmark(const std::vector<std::function<int()>>& functions, int num_runs) {
    for (int i = 0; i < functions.size(); ++i) {
        auto& func = functions[i];
        std::chrono::duration<double> total_time(0.0);

        for (int j = 0; j < num_runs; ++j) {
            auto start_time = std::chrono::high_resolution_clock::now();
            func();
            auto end_time = std::chrono::high_resolution_clock::now();
            total_time += end_time - start_time;

            auto current_run_time = end_time - start_time;

            std::cout << "This run took: " << current_run_time.count() << " seconds" << std::endl;
        }

        double average_time = total_time.count() / num_runs;
        std::cout << "Function " << i + 1 << " average time: " << average_time << " seconds" << std::endl;
    }
}

int main() {
    std::vector<std::function<int()>> functions = {version1, version2};
    int num_runs = 20;
    benchmark(functions, num_runs);
    return 0;
}