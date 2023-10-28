
#ifndef CPP_D2P1_H
#define CPP_D2P1_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <chrono>
#include <map>

std::string file = "../../data/20221202-rock-paper-scissors.txt";

// A, X - ROCK
// B, Y - PAPER
// C, Z - SCISSORS
std::map<std::string, int> mapping = {
        {"A", 0}, {"X", 0},
        {"B", 1}, {"Y", 1},
        {"C", 2}, {"Z", 2}
};

std::map<std::string, int> shapeMapping = {
        {"X", 1},
        {"Y", 2},
        {"Z", 3}
};

int resultMatrix[3][3] = {
        {3, 0, 6},
        {6, 3, 0},
        {0, 6, 3}
};

int getScore(int move1, int move2) {
    return resultMatrix[move1][move2];
}

namespace d2p1 {
    void run() {
        std::ifstream inputFile(file);
        if (!inputFile) {
            std::cerr << "Unable to open file: " << file << std::endl;
            return;
        }

        int totalScore = 0;
        std::string line;
        while (getline(inputFile, line)) {
            if (line.empty()) {
                break;
            } else {
                int spaceIndex = line.find(' ');
                std::string p1 = line.substr(0, spaceIndex);
                std::string p2 = line.substr(spaceIndex + 1);

                int v1 = mapping[p1];
                int v2 = mapping[p2];
                int result = getScore(v2, v1);

                int shapeScore = shapeMapping[p2];

                totalScore += result + shapeScore;
            }
        }

        std::cout << "Total score: " << totalScore << std::endl;
    }
}

#endif //CPP_D2P1_H
