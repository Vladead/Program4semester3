//
// Created by vladead on 17.11.2019.
//

#include <stdexcept>
#include "DFT_Iterator.h"
#include "Stack.h"

DFT_Iterator::DFT_Iterator(Node *root) {
    current = root;
    traverse(root);
}

DFT_Iterator::~DFT_Iterator() {
    stackForTraverse.clear();
}

Node *DFT_Iterator::next() {
    if (current == nullptr) {
        throw std::out_of_range("Next element does not exist");
    }
    current = stackForTraverse.pop();
    Node *temp = current;
    return temp;
}

bool DFT_Iterator::has_next() {
    return (stackForTraverse.get_size() != 0);
}

void DFT_Iterator::traverse(Node *root) {
    if (root) {
        traverse(root->get_left());
        stackForTraverse.push(root);
        traverse(root->get_right());
    }
}
