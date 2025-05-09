#ifndef evaluator_HPP
#define evaluator_HPP

#include <vector>
#include <string>
#include <chrono>

class evaluator {
private:
    struct Timer {
        // Struct that holds time for each implementation of the sort
        double dll_time;
        double vector_time;
    };
    
    std::vector<std::vector<int>> test_cases; // 2D vector to hold three different testing blocks.
    std::vector<Timer> merge_results;
    std::vector<Timer> quick_results;
    std::vector<Timer> insertion_results;
    
public:
    void ingest(const std::string& filename);
    void merge_comparison();
    void quick_comparison();
    void insertion_comparison();
    void evaluate();
    evaluator();
    const std::vector<std::vector<int>>& get_test_cases() const {return test_cases;};
    const std::vector<Timer>& get_merge_results() const {return merge_results;};
    const std::vector<Timer>& get_quick_results() const {return quick_results;};
    const std::vector<Timer>& get_insertion_results() const {return insertion_results;};
    void set_test_cases(const std::vector<std::vector<int>>& new_test_cases) {test_cases = new_test_cases;};

};

#endif 