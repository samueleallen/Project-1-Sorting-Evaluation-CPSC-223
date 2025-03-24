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

void VectorSorter::merge_sort(std::vector<int>& arr){                    // Merge Sort Helper function
    merge_sort(arr, 0, arr.size()-1);
}
void VectorSorter::merge_sort(std::vector<int>& arr, int left, int right){
        if (left >= right) // Once both the left and right index are the same, move onto the next step
        return;
    
    int mid = left + (right - left) / 2; // Calculates midpoint (for division of sub-arrays)
    merge_sort(arr, left, mid); // Merges/Sorts the left sub-array
    merge_sort(arr, mid + 1, right); // Merges/Sorts the right sub-array
    merge(arr, left, mid, right); // Merges the two sub-arrays into a sorted array
    
}
void VectorSorter::merge(std::vector<int>& arr, int left, int mid, int right){
    // Create two temp vectors for each sub-array
    std::vector<int> subleft,subright;
    for(int copy_iter = left; copy_iter <= mid;  copy_iter++){ // adds each element from the left sub-array into the the "subleft" vector  
        subleft.push_back(arr[copy_iter]);
    }
    for(int copy_iter = mid+1; copy_iter <= right; copy_iter++){ // adds each element from the right sub-array into the the "subright" vector
        subright.push_back(arr[copy_iter]);
    }
   
    int right_index = 0; // iterators to keep track of indexes when comparing values
    int left_index = 0;
    int  data_iter = left;

    while(left_index < subleft.size() && right_index < subright.size()){ // Iterates until one of the two sub-arrays is empty
        if(subleft[left_index] < subright[right_index]){ 
            // Compares the two values and places the lowest value into the sorted array
            arr[data_iter] = subleft[left_index];                       
            left_index++;
        }
        else{
            arr[data_iter] = subright[right_index];
            right_index++;
        }
        data_iter++;
    }
    while(left_index<subleft.size()){ // Adds on the leftover sorted values
        arr[data_iter]=subleft[left_index];
        left_index++;
        data_iter++;
    }
    while(right_index<subright.size()){ // Adds on the leftover sorted values
        arr[data_iter]=subright[right_index];
        right_index++;
        data_iter++;
    }
}




