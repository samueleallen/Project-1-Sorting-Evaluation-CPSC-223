#include <iostream>
#include <vector>
#include "vector_sorter.hpp"

VectorSorter::VectorSorter() {
    vec = {};
}

int VectorSorter::partition(std::vector<int>&vec, int start, int end) {
    // if: base cases
    if (vec.size() == 0 || vec.size() == 1) {
        return start;
    }
    else if (vec.size() > 1) {
        int pivot = vec[start];
        int index = start;

        for (int i = start+1; i <= end; i++) {
            // if next element is less than the curr pivot
            if (vec[i] < pivot) {
                index++;
                int temp = vec[index];
                vec[index] = vec[i];
                vec[i] = temp;
            } 
        }
        // update pivot to its correct position
        int temp = vec[start];
        vec[start] = vec[index];
        vec[index] = temp;

        // return index of pivot
        return(index);
    }
    return start;
}

void VectorSorter::quick_sort(std::vector<int>&vec, int start, int end) {
    if (start < end) {
        int piv_index = partition(vec, start, end);

        quick_sort(vec, start, piv_index-1);
        quick_sort(vec, piv_index+1, end);
    }
}

void VectorSorter::insertion_sort(std::vector<int>&vec, int n) {
    for (int i = 1; i < n; i++) {
        int curr = vec[i];
        int prev = i - 1;
        while(prev >= 0 && vec[prev] > curr) {
            vec[prev+1] = vec[prev];
            prev = prev - 1;
        }
        vec[prev+1] = curr;
    }
}

void VectorSorter::print_vector(std::vector<int>&vec, int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}




