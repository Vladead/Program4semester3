//
// Created by vladead on 23.11.2019.
//

#include "Node.h"

Node::Node() : data(0), right(nullptr), left(nullptr) {}

Node::Node(int data) : data(data), right(nullptr), left(nullptr) {

}

Node::~Node() = default;

Node* Node::get_left() {
    return left;
}

Node* Node::get_right() {
    return right;
}

int Node::get_data() {
    return data;
}
