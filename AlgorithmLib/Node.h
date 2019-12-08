//
// Created by vladead on 23.11.2019.
//

#ifndef PROGRAM3_NODE_H
#define PROGRAM3_NODE_H


class Node {
private:
    int data;
    Node *right;
    Node *left;
public:
    Node();

    explicit Node(int data);

    ~Node();

    Node *get_left();

    Node *get_right();

    int get_data();

    friend class BinaryTree;
};


#endif //PROGRAM3_NODE_H
