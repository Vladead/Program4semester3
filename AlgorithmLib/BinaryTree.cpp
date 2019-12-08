//
// Created by vladead on 31.10.2019.
//

#include <stdexcept>
#include <iostream>
#include "BinaryTree.h"
#include "BFT_Iterator.h"
#include "DFT_Iterator.h"

BinaryTree::BinaryTree() : root(nullptr) {

}

BinaryTree::~BinaryTree() {
    destroy(root);
    root = nullptr;
}

bool BinaryTree::contains(int key) {
    if (root == nullptr) {
        throw std::out_of_range("The tree is empty");
    }

    if (root->data == key) {
        return true;
    }
    Iterator *iterator = create_dft_iterator();
    while (iterator->has_next()) {
        if (iterator->next()->data == key) {
            delete iterator;
            return true;
        }
    }
    delete iterator;
    return false;
}

void BinaryTree::insert(int key) {
    if (!root) {
        root = new Node(key);
    } else {
        addElement(root, key);
    }
}

void BinaryTree::addElement(Node *node, int key) {
    if (node->data > key) {
        if (node->left == nullptr) {
            node->left = new Node(key);
        } else {
            addElement(node->left, key);
        }
    } else {
        if (node->right == nullptr) {
            node->right = new Node(key);
        } else {
            addElement(node->right, key);
        }
    }
}

void BinaryTree::remove(int key) {
    if (root == nullptr) {
        throw std::out_of_range("The tree is empty");
    }

    if (!contains(key)) {
        throw std::runtime_error("The key does not exist");
    }

    Iterator *iterator = create_dft_iterator();
    Node *shouldBeDeleted = nullptr;
    while (iterator->has_next()) {
        shouldBeDeleted = iterator->next();
        if (shouldBeDeleted->data == key) {
            break;
        }
    }
    Node *parentOfShouldBeDeleted = findParent(shouldBeDeleted);
    if (shouldBeDeleted->right == nullptr && shouldBeDeleted->left == nullptr) {
        if (parentOfShouldBeDeleted->right == shouldBeDeleted) {
            parentOfShouldBeDeleted->right = nullptr;
        }
        if (parentOfShouldBeDeleted->left == nullptr) {
            parentOfShouldBeDeleted->left = nullptr;
        }
        destroy(shouldBeDeleted);
    } else if (shouldBeDeleted->left == nullptr || shouldBeDeleted->right == nullptr) {
        if (shouldBeDeleted->left == nullptr) {
            if (parentOfShouldBeDeleted->left == shouldBeDeleted) {
                parentOfShouldBeDeleted->left = shouldBeDeleted->right;
            } else {
                parentOfShouldBeDeleted->right = shouldBeDeleted->right;
            }
        } else {
            if (parentOfShouldBeDeleted->left == shouldBeDeleted) {
                parentOfShouldBeDeleted->left = shouldBeDeleted->left;
            } else {
                parentOfShouldBeDeleted->right = shouldBeDeleted->left;
            }
        }
    } else {
        auto suitable = next(shouldBeDeleted);
        shouldBeDeleted->data = suitable->data;
        if (findParent(suitable)->left == suitable) {
            findParent(suitable)->left = nullptr;
            destroy(suitable);
        } else {
            findParent(suitable)->right = suitable->right;
            suitable->right = nullptr;
            destroy(suitable);
        }
    }
    delete iterator;
}

Node *BinaryTree::minimum(Node *node) {
    if (node->left == nullptr) {
        return node;
    }
    return minimum(node->left);
}

Node *BinaryTree::next(Node *node) {
    if (node->right != nullptr) {
        return minimum(node->right);
    }
    auto temp = findParent(node);
    while (temp != nullptr && node == temp->right) {
        node = temp;
        temp = findParent(temp);
    }
    return temp;
}

Node *BinaryTree::findParent(Node *node) {
    if (node == root) {
        throw std::out_of_range("Node is the root of the tree");
    }
    Iterator *iterator = create_bft_iterator();
    Node *temp;
    while (iterator->has_next()) {
        temp = iterator->next();
        if (temp->left == node || temp->right == node) {
            delete iterator;
            return temp;
        }
    }
    delete iterator;
    return nullptr;
}

Iterator *BinaryTree::create_bft_iterator() {
    return new BFT_Iterator(root);
}

Iterator *BinaryTree::create_dft_iterator() {
    return new DFT_Iterator(root);
}

void BinaryTree::print() {
    if (root == nullptr) {
        throw std::out_of_range("The tree is empty");
    }
    int level = 0;
    printNode(root, level, false);
    std::cout << std::endl;
}

void BinaryTree::printNode(Node *node, int level, bool side) {
    for (int i = 0; i < level; i++) {
        std::cout << ' ';
    }
    if (level != 0) {
        std::cout << '|';
        std::cout << "->";
        if (!side) {
            std::cout << "L: ";
        } else {
            std::cout << "R: ";
        }
    } else {
        std::cout << ' ';
    }
    if (node) {
        std::cout << node->data << std::endl;
    } else {
        std::cout << '-' << std::endl;
    }
    if (node) {
        if (level > 0) {
            if (node->get_left() || node->get_right()) {
                printNode(node->get_left(), level + 3, false);
                printNode(node->get_right(),level + 3, true);
            }
        } else {
            if (node->get_left() || node->get_right()) {
                printNode(node->get_left(), level + 1, false);
                printNode(node->get_right(), level + 1, true);
            }
        }
    }
}

void BinaryTree::destroy(Node *node) {
    if (node) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}
