#include "vector_sorter.hpp"
#include "evaluator.hpp"
#include "doubly_linked_list.hpp"

int main() {
    evaluator evaluator;
    evaluator.ingest("evaluation_cases.txt");
    evaluator.quick_comparison();
    evaluator.insertion_comparison();
    evaluator.merge_comparison();
    evaluator.evaluate();
}