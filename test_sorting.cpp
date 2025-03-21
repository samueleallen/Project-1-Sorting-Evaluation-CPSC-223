#include <iostream>
#include <cassert>
#include "doubly_linked_list.hpp"

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
    l3.push_front(10);
    l3.push_front(5);
    l3.push_front(13);
    l3.push_front(17);
    l3.push_front(11);
    l3.quick_sort();
    assert(is_sorted(l3.get_head()));

    // // List with duplicate numbers
    l3.push_front(10);
    l3.push_front(10);
    l3.push_front(11);
    l3.push_front(11);
    l3.push_front(11);
    l3.quick_sort();
    assert(is_sorted(l3.get_head()));

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
    l3.push_front(10);
    l3.push_front(5);
    l3.push_front(13);
    l3.push_front(17);
    l3.push_front(11);
    DLLNode* head4 = l4.get_head(); 
    l3.insertion_sort(head4);
    assert(is_sorted(l4.get_head()));

    // List with duplicate numbers
    l3.push_front(10);
    l3.push_front(10);
    l3.push_front(11);
    l3.push_front(11);
    l3.push_front(11);
    DLLNode* head5 = l5.get_head(); 
    l3.insertion_sort(head5);
    assert(is_sorted(l5.get_head()));

    return true;
}

int main() {
    std::cout << "Quick Sort Test: " <<(test_quick_sort_dll() ? "Passed" : "Failed") << std::endl;
    std::cout << "Insertion Sort Test: " <<(test_insertion_sort_dll() ? "Passed" : "Failed") << std::endl;
}