//
// Created by vladead on 29.11.2019.
//

#ifndef PROGRAM4_ARRAYALGORITHMS_H
#define PROGRAM4_ARRAYALGORITHMS_H

#include "BinaryTree.h"

int BinarySearch(const int *array, size_t size, int value);    // return index of value in sorted array

void QuickSort(int *array, int left, int right);

void outputQuickSortStats();

void InsertionSort(int *array, size_t size);

void outputInsertionSortStats();

void TreeSort(int *array, size_t size);

void outputTreeSort();

void BogoSort(int *array, size_t size);

void CountingSort(char *array, size_t size);

bool checkSortedArray(const int *array, size_t size);    // Check for the correction of sorted array

void shakeShakeShake(int *array, size_t size);    // Shake elements in array

#endif //PROGRAM4_ARRAYALGORITHMS_H
