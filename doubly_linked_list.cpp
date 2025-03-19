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
