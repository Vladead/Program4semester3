//
// Created by vladead on 17.10.2019.
//

#ifndef PROGRAM2_STACK_H
#define PROGRAM2_STACK_H

#include <cstddef>
#include "SElement.h"
#include "Node.h"

class Stack {
private:
    size_t size;
    SElement *top;
public:
    Stack();

    ~Stack();

    void push(Node *value);          // Add element to stack

    Node *pop();                     // Delete element from stack. Return element from deleted element

    Node *peek();                    // Return element from top of stack

    size_t get_size() noexcept;  // Return count of elements in stack

    void clear() noexcept;      // Delete all elements in stack
};


#endif //PROGRAM2_STACK_H
