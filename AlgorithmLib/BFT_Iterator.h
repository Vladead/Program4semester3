//
// Created by vladead on 17.11.2019.
//

#ifndef PROGRAM3_BFT_ITERATOR_H
#define PROGRAM3_BFT_ITERATOR_H

#include "Iterator.h"
#include "Node.h"
#include "Stack.h"

class BFT_Iterator : public Iterator {
private:
    Node *current;
    Stack stackForTraverse;
public:
    explicit BFT_Iterator(Node *root);

    ~BFT_Iterator() override;

    Node* next() override;    // Return element after current

    bool has_next() override;   // Check for the existing of the next element

    void traverse(Node *root) override;    // Load all elements in tree into the queue
};


#endif //PROGRAM3_BFT_ITERATOR_H
