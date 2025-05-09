#include <iostream>
#include <cassert>
#include "evaluator.hpp"

bool test_quick_comparison() {
    evaluator evaluator;
    std::vector<std::vector<int>> my_test_case;

    // Fill 2D vector with integers for testing
    my_test_case.push_back({1000, 2000, 3000});
    my_test_case.push_back({40000});
    my_test_case.push_back({70000, 80000, 90000});
    evaluator.set_test_cases(my_test_case);
    evaluator.quick_comparison();

    for (int i = 0; i < 3; ++i) {
        /*
        If our time variable is zero, that means no sort was performed so that is the one thing to test.
        */
        assert(evaluator.get_quick_results()[i].dll_time != 0);
        assert(evaluator.get_quick_results()[i].vector_time != 0);
    }
    return true;
}

bool test_insertion_comparison() {
    evaluator evaluator;
    std::vector<std::vector<int>> my_test_case;

    // Fill 2D vector with integers for testing
    my_test_case.push_back({1000, 2000, 3000});
    my_test_case.push_back({40000});
    my_test_case.push_back({700000, 800000, 900000});
    evaluator.set_test_cases(my_test_case);
    evaluator.insertion_comparison();

    for (int i = 0; i < 3; ++i) {
        /*
        If our time variable is zero, that means no sort was performed so that is the one thing to test.
        */
        assert(evaluator.get_insertion_results()[i].dll_time != 0);
        assert(evaluator.get_insertion_results()[i].vector_time != 0);
    }
    return true;
}

bool test_merge_comparison() {
    evaluator evaluator;
    std::vector<std::vector<int>> my_test_case;

    // Fill 2D vector with integers for testing
    my_test_case.push_back({1000, 2000, 3000});
    my_test_case.push_back({40000});
    my_test_case.push_back({700000, 800000, 900000});
    evaluator.set_test_cases(my_test_case);
    evaluator.merge_comparison();

    for (int i = 0; i < 3; ++i) {
        /*
        If our time variable is zero, that means no sort was performed so that is the one thing to test.
        */
        assert(evaluator.get_merge_results()[i].dll_time != 0);
        assert(evaluator.get_merge_results()[i].vector_time != 0);
    }
    return true;
}


int main() {
    std::cout << "Quick Sort Comparison Test: " <<(test_quick_comparison() ? "Passed" : "Failed") << std::endl;
    std::cout << "Insertion Sort Comparison Test: " <<(test_insertion_comparison() ? "Passed" : "Failed") << std::endl;
    std::cout << "Merge Sort Comparison Test: " <<(test_merge_comparison() ? "Passed" : "Failed") << std::endl;

    return 0;
}
