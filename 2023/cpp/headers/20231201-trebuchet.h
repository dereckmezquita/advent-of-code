
#ifndef CPP_20231201_TREBUCHET_H
#define CPP_20231201_TREBUCHET_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <chrono>
#include <map>

std::string file = "../../data/20231201-trebuchet.txt";

namespace p1 {
    void main() {
        std::ifstream inputFile(file);
        if (!inputFile) {
            std::cerr << "Unable to open file: " << file << std::endl;
            return;
        }

        std::string line;
        int sum = 0;
        while (getline(inputFile, line)) {
            std::vector<char> digits;

            for (char ch : line) {
                if (std::isdigit(ch)) {
                    digits.push_back(ch);
                }
            }

            if (!digits.empty()) {
                int first = digits.front() - '0';
                int last = digits.back() - '0';
                int number = first * 10 + last;

                sum += number;
            }
        }

        std::cout << sum << std::endl;
    }
}

namespace p2 {
    void main() {
        std::ifstream inputFile(file);
        if (!inputFile) {
            std::cerr << "Unable to open file: " << file << std::endl;
            return;
        }

        std::string line;
        int sum = 0;
        while (getline(inputFile, line)) {
            std::vector<char> digits;

            for (char ch : line) {
                if (std::isdigit(ch)) {
                    digits.push_back(ch);
                }
            }

            if (!digits.empty()) {
                int first = digits.front() - '0';
                int last = digits.back() - '0';
                int number = first * 10 + last;

                sum += number;
            }
        }

        std::cout << sum << std::endl;
    }
}

#endif //CPP_20231201_TREBUCHET_H
