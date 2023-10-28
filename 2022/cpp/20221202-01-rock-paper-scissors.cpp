#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <chrono>
#include <map>
#include <sstream>

std::string file = "../../data/20221202-rock-paper-scissors.txt";

// A, X - ROCK
// B, Y - PAPER
// C, Z - SCISSORS

std::map<std::string, int> mapping = {
    {"A", 0}, {"X", 0},
    {"B", 1}, {"Y", 1},
    {"C", 2}, {"Z", 2}
};

int resultMatrix[3][3] = {
    {0, -1, 1},
    {1, 0, -1},
    {-1, 1, 0}
};

std::string getHumanReadable(int move) {
    switch (move) {
        case 0:
            return "ROCK";
        case 1:
            return "PAPER";
        case 2:
            return "SCISSORS";
        default:
            return "INVALID";
    }
}

int getScore(int move1, int move2) {
    return resultMatrix[move1][move2];
}

int version1() {
    std::ifstream inputFile(file);
    if (!inputFile) {
        std::cerr << "Unable to open file: " << file << std::endl;
        return 1;
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
            totalScore += result;
            std::cout <<
                "Opp: " << getHumanReadable(v1) << std::endl <<
                "Me:  " << getHumanReadable(v2) << std::endl <<
                "Result: " << result << std::endl << std::endl;
        }
    }

    std::cout << "Total score: " << totalScore << std::endl;

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

    std::cout.rdbuf(orig_cout);

    double average_time = total_time.count() / num_runs;
    std::cout << "Function took an average of: " << average_time << " seconds" << std::endl;
}


int main() {
    int num_runs = 20;
    benchmark(version1, num_runs);
    return 0;
}