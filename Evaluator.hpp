#ifndef EVALUATOR_HPP
#define EVALUATOR_HPP

#include <vector>
#include <string>
#include <chrono>

class Evaluator {
private:
    struct Timer {
        // Struct that holds time for each implementation of the sort
        // Maybe consider including which eval case it is in the struct with a new variable? I dont really know  -Sam
        double dll_time;
        double vector_time;
    };
    
    std::vector<std::vector<int>> test_cases; // 2D vector to hold three different testing blocks
    std::vector<Timer> merge_results;
    std::vector<Timer> quick_results;
    std::vector<Timer> insertion_results;
    
public:
    const std::vector<std::vector<int>>& getTestCases() const;
    void ingest(const std::string& filename);
    void merge_comparison();
    void quick_comparison();
    void insertion_comparison();
    void evaulate();
    Evaluator();
    
};


#endif 