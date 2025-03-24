#ifndef VECTOR_SORTER_HPP
#define VECTOR_SORTER_HPP
#include <vector>


class VectorSorter {
    private:
    std::vector<int> vec;
    static void merge(std::vector<int>& arr, int left, int mid, int right);
    static void merge_sort(std::vector<int>& arr, int left, int right);

    public:
        VectorSorter();
        // Merge Sort
        static void merge_sort(std::vector<int>& arr);
        // Other Sorts
        static void quick_sort(std::vector<int>&, int start, int end);
        static int partition(std::vector<int>&, int start, int end);
        static void insertion_sort(std::vector<int>&, int index);
        static void print_vector(std::vector<int>&, int n);

};
 
#endif