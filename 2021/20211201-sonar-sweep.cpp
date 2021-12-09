
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::string file_name = "./data/20211201-sonar-sweep.txt";
    std::ifstream file(file_name);

    if(!file) {
        std::cerr << "File not found: " << file_name << std::endl;
        return 1;
    }

    int x;
    std::vector<int> sonar;
    while(file >> x) {
        sonar.push_back(x);
    }

    // part one
    int sum = 0;
    for(int i = 0; i < sonar.size(); i++) {
        sum += sonar[i] < sonar[i + 1];
    }

    std::cout << "Part 1: " << sum << std::endl;

    // part two
    sum = 0;
    std::vector<int> results;
    for(int i = 0; i < sonar.size(); i++) {
        results.push_back(sonar[i] + sonar[i + 2] + sonar[i + 1]);
    }

    for(int i = 0; i < results.size(); i++) {
        sum += results[i] < results[i + 1];
    }

    std::cout << "Part 2: " << sum << std::endl;
    
    file.close();
    return 0;
}
