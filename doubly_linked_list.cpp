#include <stdexcept>
#include <iostream>
#include "doubly_linked_list.hpp"

DLLNode::DLLNode() {
    value = 0;
    next = nullptr;
    prev = nullptr;
}

DLLNode::DLLNode(int v) {
    value = v;
    next = nullptr;
    prev = nullptr;
}

DLLNode::DLLNode(DLLNode* n) {
    value = 0;
    next = n;
    prev = nullptr;
    if (n != nullptr) {
        n->prev = this; // set previous pointer for next node
    }
}

DLLNode::DLLNode(int v, DLLNode* n) {
    value = v;
    next = n;
    prev = nullptr;
    if (n != nullptr) {
        n->prev = this; // set previous pointer for next node
    }
}

DLLNode::~DLLNode() {
    if (next != nullptr) {
        delete next;
        next = nullptr;
    }
}

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
    delete head;
}

bool DoublyLinkedList::push_back(int v) {
    if (is_empty()) {
        return push_front(v);
    }
    // no need for iterating with while loop if we just use tail
    DLLNode* newNode = new DLLNode(v);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode; // update tail pointer to new node
    return true;
}

bool DoublyLinkedList::push_front(int v) {
    DLLNode* temp = new DLLNode(v, head);
    if (head != nullptr) {
        head->prev = temp; // update old head's prev pointer if head isnt nullptr
    } else {
        tail = temp; // if list was empty, update tail
    }
    head = temp;
    return true;
}

bool DoublyLinkedList::insert(int v, int i) {
    
    if (i > size() || i < 0) {
        return false;
    } 
    else if (i == 0) {
        return push_front(v);
    }
    else if (i == size()) {
        return push_back(v);
    }
    else {
        DLLNode* iter = head;
        for (int count = 1; count < i; count++) {
            iter = iter->next;
        }
        DLLNode* newNode = new DLLNode(v, iter->next);
        if (iter->next != nullptr) { 
            iter->next->prev = newNode;
        }
        iter->next = newNode;
        newNode->prev = iter;
        return true;
    }
}

int DoublyLinkedList::at(int i) {
    if (i < 0 || i >= size()) {
        throw std::out_of_range("Invalid Index for List");
    }
    else {
        DLLNode* iter = head;
        for (int count = 0; count < i; count++) {
            iter = iter->next;
        }
        return iter->value;
    }
}

int DoublyLinkedList::search(int v) {
    DLLNode* iter = head;
    int count = 0;
    while (iter->next != nullptr && iter->value != v) {
        iter = iter->next;
        count++;
    }
    if (iter->value == v) {
        return count;
    }
    return -1;
}

bool DoublyLinkedList::is_empty(){
    return head == nullptr;
}

int DoublyLinkedList::size() {
    if (is_empty()) {
        return 0;
    }
    int count = 1;
    for(DLLNode* iter = head; iter->next != nullptr; iter=iter->next) {
        count++;
    }
    return count;
}

bool DoublyLinkedList::remove(int i) {
    if(is_empty()) {
        return false;
    }
    else if (i < 0 || i >= size()) {
        return false;
    }
    else if (i == 0) { // update head pointer and delete first node
        DLLNode* temp = head;
        head = head->next; // move head to next node in list
        if (head != nullptr) {
            head->prev = nullptr; // set new head's prev to null
        }
        delete temp;
        return true;
    }
    else {
        DLLNode* iter = head;
        // traverse to node
        for (int count = 1; count < i; count++) {
            iter = iter->next;
        }
        DLLNode* temp = iter->next;
        if (temp->next == nullptr) { // checks if node to remove is last in list
            iter->next = nullptr; // prev node's next becomes nullptr
            temp->prev = nullptr; // disconnects node from list
            delete temp;
            return true;
        }
        // for general case
        iter->next = temp->next;
        temp->next->prev = iter; // updates next node's prev to previous node
        temp->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return true;
    }
}

bool DoublyLinkedList::remove_value(int v) {
    if (is_empty()) {
        return false;
    } else if (search(v) == -1) {
        return false;
    } else {
        remove(search(v));
        return true;
    }
}

void DoublyLinkedList::print() {
    DLLNode* iter = head;
    while (iter != nullptr) {
        std::cout << iter-> value << " ";
        iter = iter->next;
    } 
    std::cout << std::endl;
}

void DoublyLinkedList::print_reverse() {
    DLLNode* iter = tail;
    while (iter != nullptr) {
        std::cout << iter-> value << " ";
        iter = iter->prev;
    } 
    std::cout << std::endl;
}

// Helper function to swap the values of two nodes
void DoublyLinkedList::swap(DLLNode* a, DLLNode* b) {
    // Swap the values of each node
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
}

// Public quicksort function that calls recursive function and returns head
DLLNode* DoublyLinkedList::quick_sort() {
    //If element is size one or lower no sorting needs to be done
    if (head == nullptr || head->next == nullptr) { 
        return head;
    }
    //Find tail node
    tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    head = quick_sort(head, tail);
    return head;
}

//Helper function to split the list into nodes to the left of the pivot if less than
//and values to the right of the pivot node if greater than the pivot
DLLNode* DoublyLinkedList::partition(DLLNode* low, DLLNode* high) {
    // Choose the first element as pivot
    int pivot_value = low->value;
    
    // Pointer to place smaller nodes
    DLLNode* i = low;  
    
    // Traverse from low node to high node
    for (DLLNode* j = low->next; j != nullptr && j != high->next; j = j->next) {
        // If current nodes data is less than or equal to pivot
        if (j->value <= pivot_value) {
            // Move i forward and swap values
            i = i->next;  
            swap(i, j); 
        }
    }

    // Place pivot in its final sorted position
    // and return pivot position
    swap(low, i);
    return i;  
}

DLLNode* DoublyLinkedList::quick_sort(DLLNode* head, DLLNode* tail) {
    // Ensure list has more than one element
    if (head != nullptr && tail != nullptr && tail != head) {
        // Find the pivot
        DLLNode* pivot = partition(head, tail);
        //Recursively sort left half from head up to the pivot->prev
        if (pivot->prev != nullptr && head != pivot) {
            quick_sort(head, pivot->prev);
        }
        //Recursively sort right half from pivot->next to tail
        if (pivot->next != nullptr && pivot != tail) {
            quick_sort(pivot->next, tail);
        }
    }

    // Ensure head pointer is correct
    while (head != nullptr && head->prev != nullptr) {
        head = head->prev;
    }
    return head;
}

DLLNode* DoublyLinkedList::insertion_sort(DLLNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    DLLNode* sorted = nullptr;
    DLLNode* curr = head;

    // Traverse the list to sort each element
    while (curr != nullptr) {
        //Store next node to process
        DLLNode* next = curr->next;

        // Insert curr into sorted list
        if (sorted == nullptr || sorted->value >= curr->value) {
            curr->next = sorted;

            // If sorted list is not empty, set its prev
            if (sorted != nullptr) {
                sorted->prev = curr;
            }

            // Update sorted to the new head
            sorted = curr;
            sorted->prev = nullptr;
        } else {
            // Pointer to traverse sorted part
            DLLNode* curr_sorted = sorted;

            // Find correct position to insert at
            while (curr_sorted->next != nullptr && curr_sorted->next->value < curr->value) {
                curr_sorted = curr_sorted->next;
            }

            // Insert curr after curr_sorted
            curr->next = curr_sorted->next;

            // Set prev if curr is not inserted at the end
            if (curr_sorted->next != nullptr) {
                curr_sorted->next->prev = curr;
            }

            // Set next of current_sorted to curr
            curr_sorted->next = curr;
            curr->prev = curr_sorted; 
        }

        // Move on to next node in the unsorted list
        curr = next;
    }
    return sorted;
}
