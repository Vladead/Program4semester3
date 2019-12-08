//
// Created by vladead on 17.11.2019.
//

#include <stdexcept>
#include "BFT_Iterator.h"
#include "Stack.h"

BFT_Iterator::BFT_Iterator(Node *root) {
    current = root;
    traverse(root);
}

BFT_Iterator::~BFT_Iterator() {
    stackForTraverse.clear();
}

Node *BFT_Iterator::next() {
    if (current == nullptr) {
        throw std::out_of_range("Next element does not exist");
    }
    current = stackForTraverse.pop();
    Node *temp = current;
    return temp;
}

bool BFT_Iterator::has_next() {
    return (stackForTraverse.get_size() != 0);
}

void BFT_Iterator::traverse(Node *root) {
    Stack temp;
    Node* tempNode;
    temp.push(root);
    while (temp.get_size() != 0) {
        tempNode = temp.pop();
        stackForTraverse.push(tempNode);
        if (tempNode->get_left()) {
            temp.push(tempNode->get_left());
        }
        if (tempNode->get_right()) {
            temp.push(tempNode->get_right());
        }
    }
}
