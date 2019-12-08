//
// Created by vladead on 17.10.2019.
//

#ifndef PROGRAM2_ELEMENT_H
#define PROGRAM2_ELEMENT_H

#include "Node.h"

class SElement {
private:
    Node *element;
    SElement *next;

public:
    SElement();

    ~SElement();

    friend class Stack;
};


#endif //PROGRAM2_ELEMENT_H
