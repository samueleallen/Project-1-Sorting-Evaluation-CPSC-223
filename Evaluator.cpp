#include "Evaluator.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

Evaluator::Evaluator() {}

// Getter function to access the test_cases
const std::vector<std::vector<int>>& Evaluator::getTestCases() const {
    return test_cases;
}

/*
 Ingests the contents of the file and stores it into test_cases 2D vector. 
 First row of test_cases holds integers of 4-digits
 Second row of test_cases holds integers of 5-digits
 Third row of test_cases holds integers of 6-digits
*/
void Evaluator::ingest(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file for reading";
        return;
    }

    test_cases.clear(); // clear any data from potential previous function calls

    // Create temp variables to hold each of our testing groups
    std::vector<int> group1, group2, group3;

    int lineCount = 0;
    std::string line;

    // Read file line by line
    while (std::getline(file, line)) {
        int number;

        // Convert it to an istringstream object so we can get individual numbers from the line easier
        std::istringstream lineStream(line);

        // Read each number from the current line
        while (lineStream >> number) {
            // Group the numbers based on the number of digits
            if (number >= 1000 && number < 10000) {
                // 4-digit numbers go to group1
                group1.push_back(number);
            } else if (number >= 10000 && number < 100000) {
                // 5-digit numbers go to group2
                group2.push_back(number);
            } else if (number >= 100000) {
                // 6-digit numbers go to group3
                group3.push_back(number);
            }
        }
    }

    // Add the three groups to test_cases if they are not empty
    if (!group1.empty()) test_cases.push_back(group1);
    if (!group2.empty()) test_cases.push_back(group2);
    if (!group3.empty()) test_cases.push_back(group3);

    file.close();
}

    