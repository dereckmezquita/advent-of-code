#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>

int main() {
    std::ifstream inputFile("../../data/20221201-calories-per-elf.txt");
    if (!inputFile) {
        std::cerr << "Unable to open file example.txt" << std::endl;
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

        std::cout << "Elf total calories: " << std::to_string(sum) << std::endl;
    }

    int maxCalories = *std::max_element(elvesTotalCalories.begin(), elvesTotalCalories.end());

    std::cout << "Elf max calories: " << maxCalories << std::endl;

    return 0;
}