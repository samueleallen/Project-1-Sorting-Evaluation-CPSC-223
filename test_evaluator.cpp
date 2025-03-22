#include <iostream>
#include <cassert>
#include "Evaluator.hpp"

void test_ingest() {
    Evaluator evaluator;
    evaluator.ingest("evaluation_cases.txt");

    for (const auto& test_case : evaluator.getTestCases()) {
        if (!test_case.empty()) {
            std::cout << "First element of test case: " << test_case[0] << std::endl;
        }
    }
}

int main() {
    test_ingest();

    return 0;
}
