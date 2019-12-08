//
// Created by vladead on 23.11.2019.
//

#ifndef PROGRAM3_ITERATOR_H
#define PROGRAM3_ITERATOR_H

#include "Node.h"

class Iterator {
public:
    virtual ~Iterator() = default;

    virtual Node *next() = 0;

    virtual bool has_next() = 0;

    virtual void traverse(Node *root) = 0;
};

#endif //PROGRAM3_ITERATOR_H
