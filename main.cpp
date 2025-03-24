#include "vector_sorter.hpp"
#include "Evaluator.hpp"
#include "doubly_linked_list.hpp"

int main() {
    Evaluator evaluator;
    evaluator.ingest("evaluation_cases.txt");
    evaluator.quick_comparison();
    evaluator.insertion_comparison();
    evaluator.merge_comparison();
    evaluator.evaluate();
}