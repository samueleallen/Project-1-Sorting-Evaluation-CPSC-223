#ifndef VECTOR_SORTER_HPP
#define VECTOR_SORTER_HPP
#include <vector>


class VectorSorter {
    private:
    std::vector<int> vec;
    void merge(std::vector<int>& arr, int left, int mid, int right);
    void merge_sort(std::vector<int>& arr, int left, int right);

    public:
        VectorSorter();
        // Merge Sort
        void merge_sort(std::vector<int>& arr);
        // Other Sorts
        void quick_sort(std::vector<int>&, int start, int end);
        int partition(std::vector<int>&, int start, int end);
        void insertion_sort(std::vector<int>&, int index);
        void print_vector(std::vector<int>&, int n);

};
 
#endif