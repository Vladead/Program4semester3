//
// Created by vladead on 17.11.2019.
//

#ifndef PROGRAM3_DFT_ITERATOR_H
#define PROGRAM3_DFT_ITERATOR_H

#include "Stack.h"
#include "Iterator.h"
#include "Node.h"

class DFT_Iterator : public Iterator {
private:
    Node *current;
    Stack stackForTraverse;
public:
    explicit DFT_Iterator(Node *root);

    ~DFT_Iterator() override;

    Node* next() override;    // Return element after current

    bool has_next() override;    // Check for the existing of the next element

    void traverse(Node *root) override;    // Load all elements in tree into the stack
};


#endif //PROGRAM3_DFT_ITERATOR_H
