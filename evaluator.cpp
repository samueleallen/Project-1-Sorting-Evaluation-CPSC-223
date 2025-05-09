#include "evaluator.hpp"
#include "doubly_linked_list.hpp"
#include "vector_sorter.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

evaluator::evaluator() {}

/*
 Ingests the contents of the file and stores it into test_cases 2D vector. 
 First row of test_cases holds integers of 4-digits
 Second row of test_cases holds integers of 5-digits
 Third row of test_cases holds integers of 6-digits
*/
void evaluator::ingest(const std::string& filename) {
    /*
    As a reference: There are three blocks of 4 lines in the evaluation_cases.txt file where the first block is 100 four digit ints on each line, next block is 1000 four digit ints on each line, etc.
    In the announcement, it says 1000 ints, 10000 ints, and 100000 ints per line but that isn't right so don't worry when test_cases has rows of 400, 4000, and 40000 elements - Sam
    */
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

    // Add the three groups to test_cases
    if (!group1.empty()) test_cases.push_back(group1);
    if (!group2.empty()) test_cases.push_back(group2);
    if (!group3.empty()) test_cases.push_back(group3);

    file.close();
}

void evaluator::quick_comparison() {
    if (test_cases.empty()) {
        std::cout << "Error: test cases vector is empty";
        return;
    }
    
    // Resize quick_results vector to same as test_cases
    quick_results.resize(test_cases.size());

    // For loop goes through each testing block/group
    for (int i = 0; i < 3; ++i) {
        int num_of_digits = i+4; // starts at 4 digits, goes to six

        // DLL quick sort
        DoublyLinkedList dll;
        // Push back each number in our test_cases row.
        for (int num : test_cases[i]) {
            dll.push_back(num);
        }

        // Get times before and after quick_sort call to measure how long it took
        auto dll_start = std::chrono::high_resolution_clock::now();
        dll.quick_sort();
        auto dll_end = std::chrono::high_resolution_clock::now();

        // Get number of ms as a double
        duration<double, std::milli> ms_double = dll_end - dll_start;

        // Store milliseconds into quick_results array
        quick_results[i].dll_time = ms_double.count();

        // Vector quick sort
        std::vector<int> v = test_cases[i];
        auto v_start = std::chrono::high_resolution_clock::now();
        VectorSorter::quick_sort(v, 0, v.size() - 1);
        auto v_end = std::chrono::high_resolution_clock::now();

        // Get number of ms as a double
        duration<double, std::milli> ms_double_quicksort = v_end - v_start;

        // Store milliseconds into quick_results array
        quick_results[i].vector_time = ms_double_quicksort.count();
    }
    return;
}

void evaluator::insertion_comparison() {
    /*
    Function to compare the results of insertion sort on a dll vs vector
    */
    if (test_cases.empty()) {
        std::cout << "Error: test cases vector is empty";
        return;
    }
    
    // Resize quick_results vector to same as test_cases
    insertion_results.resize(test_cases.size());

    // For loop goes through each testing block/group
    for (int i = 0; i < 3; ++i) {
        int num_of_digits = i+4; // starts at 4 digits, goes to six

        // DLL quick sort
        DoublyLinkedList dll;
        // Push back each number in our test_cases row.
        for (int num : test_cases[i]) {
            dll.push_back(num);
        }

        // Get times before and after insertion_sort call to measure how long it took
        auto dll_start = std::chrono::high_resolution_clock::now();
        dll.insertion_sort();
        auto dll_end = std::chrono::high_resolution_clock::now();

        // Get number of ms as a double
        duration<double, std::milli> ms_double = dll_end - dll_start;

        // Store milliseconds into insertion_results array
        insertion_results[i].dll_time = ms_double.count();

        // Vector insertion sort
        std::vector<int> v = test_cases[i];
        auto v_start = std::chrono::high_resolution_clock::now();
        VectorSorter::insertion_sort(v, v.size());
        auto v_end = std::chrono::high_resolution_clock::now();

        // Get number of ms as a double
        duration<double, std::milli> ms_double_insertion = v_end - v_start;

        // Store milliseconds into insertion_results array
        insertion_results[i].vector_time = ms_double_insertion.count();
    }
    return;
}

void evaluator::merge_comparison() {
    /*
    Function to compare the results of merge sort on a dll vs vector
    */
    if (test_cases.empty()) {
        std::cout << "Error: test cases vector is empty";
        return;
    }
    
    // Resize merge_results vector to same as test_cases
    merge_results.resize(test_cases.size());

    // For loop goes through each testing block/group
    for (int i = 0; i < 3; ++i) {
        int num_of_digits = i+4; // starts at 4 digits, goes to six

        // DLL merge sort
        DoublyLinkedList dll;
        // Push back each number in our test_cases row.
        for (int num : test_cases[i]) {
            dll.push_back(num);
        }

        // Get times before and after merge_sort call to measure how long it took
        auto dll_start = std::chrono::high_resolution_clock::now();
        dll.merge_sort();
        auto dll_end = std::chrono::high_resolution_clock::now();

        // Get number of ms as a double
        duration<double, std::milli> ms_double = dll_end - dll_start;

        // Store milliseconds into merge_results array
        merge_results[i].dll_time = ms_double.count();

        // Vector merge sort
        std::vector<int> v = test_cases[i];
        auto v_start = std::chrono::high_resolution_clock::now();
        VectorSorter::merge_sort(v);
        auto v_end = std::chrono::high_resolution_clock::now();

        // Get number of ms as a double
        duration<double, std::milli> ms_double_mergesort = v_end - v_start;

        // Store milliseconds into merge_results array
        merge_results[i].vector_time = ms_double_mergesort.count();
    }
    return;
}

void evaluator::evaluate() {
    /*
    Function to pretty print a table of each of the sort results
    */

    // Print headers
    std::cout << std::left << std::setw(20) << "Algorithm" << std::setw(20) << "Number of Digits" << std::setw(20) << "DLL TIme (ms)" << std::setw(20) << "Vector Time (ms)\n" << std::string(85, '-') << std::endl;
    // Print rows
    for (int i = 0; i < 3; ++i) {
        std::cout << std::setw(20) << "Quick Sort: " << std::setw(20) << i+4 << std::setw(20) << quick_results[i].dll_time << std::setw(20) << quick_results[i].vector_time << std::endl;
        std::cout << std::setw(20) << "Insertion Sort: " << std::setw(20) << i+4 << std::setw(20) << insertion_results[i].dll_time << std::setw(20) << insertion_results[i].vector_time << std::endl;
        std::cout << std::setw(20) << "Merge Sort: " << std::setw(20) << i+4 << std::setw(20) << merge_results[i].dll_time << std::setw(20) << merge_results[i].vector_time << std::endl;
    }
    std::cout << std::left << std::string(85, '-') << "\n";
}
    