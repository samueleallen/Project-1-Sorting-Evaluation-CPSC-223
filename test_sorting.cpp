#include <iostream>
#include <cassert>
#include <vector>
#include "doubly_linked_list.hpp"
#include "vector_sorter.hpp"

bool is_sorted(DLLNode* head) {
    // Base case: If list is size one or zero
    if (head == nullptr || head->next == nullptr) {
        return true;
    }
    // Loop through each element ensuring each element is less than the next
    while (head->next != nullptr) {
        if (head->value > head->next->value) {
            return false;
        }
        head = head->next;
    }
    return true;
}

bool test_merge_sort_dll() {
    //Test cases: Empty list, size of 1 list, already sorted, not sorted, & lists with duplicate nums
    DoublyLinkedList l1, l2, l3, l4, l5;

    // List of size 0
    l1.merge_sort();
    assert(is_sorted(l1.get_head()));
    
    // List of size 1
    l2.push_front(1);
    l2.merge_sort();
    assert(is_sorted(l2.get_head()));

    // Already sorted list
    l3.push_front(5);
    l3.push_front(4);
    l3.push_front(3);
    l3.push_front(2);
    l3.push_front(1);
    l3.merge_sort();
    assert(is_sorted(l3.get_head()));

    // Unordered list
    l4.push_front(10);
    l4.push_front(5);
    l4.push_front(13);
    l4.push_front(17);
    l4.push_front(11);
    l4.merge_sort();
    assert(is_sorted(l4.get_head()));

    // // List with duplicate numbers
    l5.push_front(10);
    l5.push_front(10);
    l5.push_front(11);
    l5.push_front(11);
    l5.push_front(11);
    l5.merge_sort();
    assert(is_sorted(l5.get_head()));
    return true;
}

bool test_quick_sort_dll() {
    //Test cases: Empty list, size of 1 list, already sorted, not sorted, & lists with duplicate nums
    DoublyLinkedList l1, l2, l3, l4, l5;

    // List of size 0
    l1.quick_sort();
    assert(is_sorted(l1.get_head()));

    // List of size 1
    l2.push_front(1);
    l2.quick_sort();
    assert(is_sorted(l2.get_head()));

    // Already sorted list
    l3.push_front(5);
    l3.push_front(4);
    l3.push_front(3);
    l3.push_front(2);
    l3.push_front(1);
    l3.quick_sort();
    assert(is_sorted(l3.get_head()));

    // Unordered list
    l4.push_front(10);
    l4.push_front(5);
    l4.push_front(13);
    l4.push_front(17);
    l4.push_front(11);
    l4.quick_sort();
    assert(is_sorted(l4.get_head()));

    // // List with duplicate numbers
    l5.push_front(10);
    l5.push_front(10);
    l5.push_front(11);
    l5.push_front(11);
    l5.push_front(11);
    l5.quick_sort();
    assert(is_sorted(l5.get_head()));

    return true;
}

bool test_insertion_sort_dll() {
    //Test cases: Empty list, size of 1 list, already sorted, not sorted, & lists with duplicate nums
    DoublyLinkedList l1, l2, l3, l4, l5;

    // List of size 0
    DLLNode* head1 = nullptr;
    l1.insertion_sort(head1);
    assert(is_sorted(l1.get_head()));

    // List of size 1
    l2.push_front(1);
    DLLNode* head2 = l2.get_head(); 
    l2.insertion_sort(head2);
    assert(is_sorted(l2.get_head()));

    // Already sorted list
    l3.push_front(5);
    l3.push_front(4);
    l3.push_front(3);
    l3.push_front(2);
    l3.push_front(1);
    DLLNode* head3 = l3.get_head(); 
    l3.insertion_sort(head3);
    assert(is_sorted(l3.get_head()));

    //Unordered list
    l4.push_front(10);
    l4.push_front(5);
    l4.push_front(13);
    l4.push_front(17);
    l4.push_front(11);
    DLLNode* head4 = l4.get_head(); 
    l4.insertion_sort(head4);
    assert(is_sorted(l4.get_head()));

    // List with duplicate numbers
    l5.push_front(10);
    l5.push_front(10);
    l5.push_front(11);
    l5.push_front(11);
    l5.push_front(11);
    DLLNode* head5 = l5.get_head(); 
    l5.insertion_sort(head5);
    assert(is_sorted(l5.get_head()));

    return true;
}

bool test_quick_sort_vec() {
    // test cases: empty, one element, unsorted, sorted, reverse order, duplicates
    VectorSorter v1, v2, v3, v4, v5, v6;

    // empty case
    std::vector<int> vec1;
    assert(vec1.empty());

    // one element
    std::vector<int> vec2 = {5};
    v2.quick_sort(vec2, 0, 0);

    assert(vec2[0] == 5);

    // unsorted
    std::vector<int> vec3 = {5,10,0};
    v3.quick_sort(vec3, 0, vec3.size()-1);
    v3.quick_sort(vec3, 0, vec3.size()-1);

    assert(vec3[0] == 0);
    assert(vec3[1] == 5);
    assert(vec3[2] == 10);

    // sorted
    std::vector<int> vec4 = {5,10,15,20};
    v4.quick_sort(vec4, 0, vec4.size()-1);
    
    assert(vec4[0] == 5);
    assert(vec4[1] == 10);
    assert(vec4[2] == 15);
    assert(vec4[3] == 20);

    // reverse order
    std::vector<int> vec5 = {25,20,10,5,0};
    v5.quick_sort(vec5, 0, vec5.size()-1);
    
    assert(vec5[0] == 0);
    assert(vec5[1] == 5);
    assert(vec5[2] == 10);
    assert(vec5[3] == 20);
    assert(vec5[4] == 25);

    // duplicates
    std::vector<int> vec6 = {25,20,10,5,10,20};
    v6.quick_sort(vec6, 0, vec6.size()-1);
    
    assert(vec6[0] == 5);
    assert(vec6[1] == 10);
    assert(vec6[2] == 10);
    assert(vec6[3] == 20);
    assert(vec6[4] == 20);
    assert(vec6[5] == 25);

    return true;
}

bool test_insertion_sort_vec() {
    // test cases: empty, one element, unsorted, sorted, reverse order, duplicates
    VectorSorter v1, v2, v3, v4, v5, v6;

    // empty
    std::vector<int> vec1;
    v1.insertion_sort(vec1, vec1.size());

    assert(vec1.empty());

    // one element
    std::vector<int> vec2 = {5};
    v2.insertion_sort(vec2, vec2.size());

    assert(vec2.size() == 1);
    assert(vec2[0] == 5);

    // unsorted
    std::vector<int> vec3 = {5,0,10,25};
    v3.insertion_sort(vec3, vec3.size());

    assert(vec3.size() == 4);
    assert(vec3[0] == 0);
    assert(vec3[1] == 5);
    assert(vec3[2] == 10);
    assert(vec3[3] == 25);

    // sorted
    std::vector<int> vec4 = {0,10,20,25,30,45};
    v4.insertion_sort(vec4, vec4.size());

    assert(vec4.size() == 6);
    assert(vec4[0] == 0);
    assert(vec4[1] == 10);
    assert(vec4[2] == 20);
    assert(vec4[3] == 25);
    assert(vec4[4] == 30);
    assert(vec4[5] == 45);

    // reverse order
    std::vector<int> vec5 = {30,20,10,0};
    v5.insertion_sort(vec5, vec5.size());

    assert(vec5.size() == 4);
    assert(vec5[0] == 0);
    assert(vec5[1] == 10);
    assert(vec5[2] == 20);
    assert(vec5[3] == 30);

    // duplicates
    std::vector<int> vec6 = {30,20,10,0,20};
    v6.insertion_sort(vec6, vec6.size());

    assert(vec6.size() == 5);
    assert(vec6[0] == 0);
    assert(vec6[1] == 10);
    assert(vec6[2] == 20);
    assert(vec6[3] == 20);
    assert(vec6[4] == 30);

    return true;
}

bool test_merge_sort_vec(){
    // test cases: empty, one element, unsorted, sorted, reverse order, duplicates
    VectorSorter v1, v2, v3, v4, v5, v6;

    // empty
    std::vector<int> vec1;
    v1.merge_sort(vec1);

    assert(vec1.empty());

    // one element
    std::vector<int> vec2 = {5};
    v2.merge_sort(vec2);

    assert(vec2.size() == 1);
    assert(vec2[0] == 5);

    // unsorted
    std::vector<int> vec3 = {5,0,10,25};
    v3.merge_sort(vec3);

    assert(vec3.size() == 4);
    assert(vec3[0] == 0);
    assert(vec3[1] == 5);
    assert(vec3[2] == 10);
    assert(vec3[3] == 25);

    // sorted
    std::vector<int> vec4 = {0,10,20,25,30,45};
    v4.merge_sort(vec4);
    
    assert(vec4.size() == 6);
    assert(vec4[0] == 0);
    assert(vec4[1] == 10);
    assert(vec4[2] == 20);
    assert(vec4[3] == 25);
    assert(vec4[4] == 30);
    assert(vec4[5] == 45);

    // reverse order
    std::vector<int> vec5 = {30,20,10,0};
    v5.merge_sort(vec5);

    assert(vec5.size() == 4);
    assert(vec5[0] == 0);
    assert(vec5[1] == 10);
    assert(vec5[2] == 20);
    assert(vec5[3] == 30);

    // duplicates
    std::vector<int> vec6 = {30,20,10,0,20};
    v6.merge_sort(vec6);

    assert(vec6.size() == 5);
    assert(vec6[0] == 0);
    assert(vec6[1] == 10);
    assert(vec6[2] == 20);
    assert(vec6[3] == 20);
    assert(vec6[4] == 30);

    return true;
}


int main() {
    std::cout << "Quick Sort Test (DLL): " <<(test_quick_sort_dll() ? "Passed" : "Failed") << std::endl;
    std::cout << "Insertion Sort Test (DLL): " <<(test_insertion_sort_dll() ? "Passed" : "Failed") << std::endl;
    std::cout << "Merge Sort Test (DLL): " <<(test_merge_sort_dll() ? "Passed" : "Failed") << std::endl;

    std::cout << "Quick Sort Test (VEC): " <<(test_quick_sort_vec() ? "Passed" : "Failed") << std::endl;
    std::cout << "Insertion Sort Test (VEC): " << (test_insertion_sort_vec() ? "Passed" : "Failed") << std::endl;
    std::cout << "Merge Sort Test (VEC): " <<(test_merge_sort_vec() ? "Passed" : "Failed") << std::endl;
}
