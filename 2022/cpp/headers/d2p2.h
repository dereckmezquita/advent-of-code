#ifndef CPP_D2P2_H
#define CPP_D2P2_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <chrono>
#include <map>

std::string file = "../../data/20221202-rock-paper-scissors.txt";

namespace d2p2 {
    void run() {
        std::ifstream infile(file);

        // Map to hold the scores for all possible combinations
        std::map<std::string, int> scores = {
                {"A X", 3 + 0}, {"A Y", 1 + 3}, {"A Z", 2 + 6},
                {"B X", 1 + 0}, {"B Y", 2 + 3}, {"B Z", 3 + 6},
                {"C X", 2 + 0}, {"C Y", 3 + 3}, {"C Z", 1 + 6}
        };

        std::string line;
        int totalScore = 0;

        // Process each line in the input file
        while (std::getline(infile, line)) {
            totalScore += scores[line];
        }

        std::cout << "Total Score: " << totalScore << std::endl;
    }
}

#endif //CPP_D2P2_H
