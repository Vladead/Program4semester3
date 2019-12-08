//
// Created by vladead on 17.10.2019.
//

#include <iostream>
#include <stdexcept>
#include "Stack.h"

Stack::Stack() : size(0), top(nullptr) {

}

Stack::~Stack() {
    clear();
}

void Stack::push(Node *value) {
    try {
        auto temp = new SElement;

        if (top != nullptr) {
            temp->next = top;
            top = temp;
        } else {
            top = temp;
        }
        top->element = value;
        size++;
    }
    catch (const std::bad_alloc &) {
        std::cerr << "Something bad happened with memory allocation " << std::endl;
        exit(-1);
    }
}

Node *Stack::pop() {
    if (get_size() == 0) {
        throw std::runtime_error("There is nothing to delete");
    }

    auto current = top->next;
    Node *tempValue;
    tempValue = top->element;
    delete top;
    top = current;
    size--;
    return tempValue;
}

Node *Stack::peek() {
    if (get_size() == 0) {
        throw std::runtime_error("There is nothing to show");
    }
    return top->element;
}

size_t Stack::get_size() noexcept {
    size_t sizeOfList = 1;

    if (top == nullptr) {
        sizeOfList = 0;
    } else {
        auto current = top;
        while (current->next != nullptr) {
            sizeOfList++;
            current = current->next;
        }
    }

    return sizeOfList;
}

void Stack::clear() noexcept {
    if (get_size() != 0) {
        SElement *temp;

        while (top) {
            temp = top->next;
            delete top;
            top = temp;
        }
    }
}