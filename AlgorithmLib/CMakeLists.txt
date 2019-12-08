cmake_minimum_required(VERSION 3.15)

project(AlgorithmLib)

set(SOURCES ArrayAlgorithms.cpp BFT_Iterator.cpp DFT_Iterator.cpp BinaryTree.cpp Stack.cpp SElement.cpp Node.cpp)
set(HEADERS ArrayAlgorithms.h BFT_Iterator.h DFT_Iterator.h BinaryTree.h Stack.h SElement.h Node.h Iterator.h)

add_library(AlgorithmLib STATIC ${SOURCES} ${HEADERS})