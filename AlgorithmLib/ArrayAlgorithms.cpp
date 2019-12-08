//
// Created by vladead on 29.11.2019.
//

#include <cstddef>
#include <stdexcept>
#include <algorithm>
#include <random>
#include <fstream>
#include <chrono>
#include <iostream>
#include "ArrayAlgorithms.h"

//return index of value in sorted array
int BinarySearch(const int *array, size_t size, int value) {
    if (size == 0) {
        throw std::out_of_range("Array is empty");
    }

    int first = 0, last = size, middle = 0;
    while (first <= last) {
        middle = (first + last) / 2;
        if (value == array[middle]) {
            return middle;
        } else if (value > array[middle]) {
            first = middle + 1;
        } else {
            last = middle - 1;
        }
    }
    return 666;
}

void QuickSort(int *array, int left, int right) {
    int leftNumber = left, rightNumber = right;    // right and left border of array
    int pivot = array[(leftNumber + rightNumber) / 2];    // base element

    int temp = 0;
    while (leftNumber <= rightNumber) {    // while borders not equal
        while (array[leftNumber] < pivot)
            leftNumber++;    // change the left border while left border is less then pivot
        while (array[rightNumber] > pivot)
            rightNumber--;    // change the right border while right border is bigger then pivot
        if (leftNumber <= rightNumber) {
            temp = array[leftNumber];
            array[leftNumber] = array[rightNumber];    // change the left and the right element
            array[rightNumber] = temp;
            leftNumber++;
            rightNumber--;
        }
    }

    if (left < rightNumber) {
        QuickSort(array, left, rightNumber);
    }
    if (leftNumber < right) {
        QuickSort(array, leftNumber, right);
    }
}

void outputQuickSortStats() {
    std::fstream outputQuickSort;
    outputQuickSort.open("QuickSortOutput.txt", std::ios::out);
    std::random_device rd;
    std::mt19937 mersenne(rd());

    int array_10[10], array_100[100], array_1000[1000], array_10000[10000], array_100000[100000];
    for (int &i : array_10) {
        i = 1 + mersenne() % 10;
        outputQuickSort << i << ' ';
    }
    outputQuickSort << std::endl;
    for (int &i : array_100) {
        i = 1 + mersenne() % 100;
        outputQuickSort << i << ' ';
    }
    outputQuickSort << std::endl;
    for (int &i : array_1000) {
        i = 1 + mersenne() % 1000;
        outputQuickSort << i << ' ';
    }
    outputQuickSort << std::endl;
    for (int &i : array_10000) {
        i = 1 + mersenne() % 10000;
        outputQuickSort << i << ' ';
    }
    outputQuickSort << std::endl;
    for (int &i : array_100000) {
        i = 1 + mersenne() % 100000;
        outputQuickSort << i << ' ';
    }
    outputQuickSort << std::endl << std::endl << std::endl;

    auto startTime = std::chrono::high_resolution_clock::now();
    QuickSort(array_10, 0, 9);
    auto finishTime = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime);
    outputQuickSort << "10 elements: " << time.count() << std::endl;

    startTime = std::chrono::high_resolution_clock::now();
    QuickSort(array_100, 0, 99);
    finishTime = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime);
    outputQuickSort << "100 elements: " << time.count() << std::endl;

    startTime = std::chrono::high_resolution_clock::now();
    QuickSort(array_1000, 0, 999);
    finishTime = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime);
    outputQuickSort << "1000 elements: " << time.count() << std::endl;

    startTime = std::chrono::high_resolution_clock::now();
    QuickSort(array_10000, 0, 9999);
    finishTime = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime);
    outputQuickSort << "10000 elements: " << time.count() << std::endl;

    startTime = std::chrono::high_resolution_clock::now();
    QuickSort(array_100000, 0, 99999);
    finishTime = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime);
    outputQuickSort << "100000 elements: " << time.count() << std::endl;

    outputQuickSort << std::endl << std::endl << std::endl;
    outputQuickSort << "Sorted arrays: " << std::endl;

    outputQuickSort << "The first one: " << std::endl << "////////";
    for (int &i : array_10) {
        outputQuickSort << i << ' ';
    }
    outputQuickSort << "////////" << std::endl;
    outputQuickSort << "The second one: " << std::endl << "////////";
    for (int &i : array_100) {
        outputQuickSort << i << ' ';
    }
    outputQuickSort << "////////" << std::endl;
    outputQuickSort << "The third one: " << std::endl << "////////";
    for (int &i : array_1000) {
        outputQuickSort << i << ' ';
    }
    outputQuickSort << "////////" << std::endl;
    outputQuickSort << "The forth one: " << std::endl << "////////";
    for (int &i : array_10000) {
        outputQuickSort << i << ' ';
    }
    outputQuickSort << "////////" << std::endl;
    outputQuickSort << "The fifth one: " << std::endl << "////////";
    for (int &i : array_100000) {
        outputQuickSort << i << ' ';
    }
    outputQuickSort << "////////" << std::endl;

    outputQuickSort.close();
}

void InsertionSort(int *array, size_t size) {
    if (size == 0) {
        throw std::out_of_range("Array is empty");
    }

    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0 && array[j - 1] > array[j]; j--) {
            std::swap(array[j - 1], array[j]);
        }
    }
}

void outputInsertionSortStats() {
    std::fstream outputInsertionSort;
    outputInsertionSort.open("InsertionSortOutput.txt", std::ios::out);
    std::random_device rd;
    std::mt19937 mersenne(rd());

    int array_10[10], array_100[100], array_1000[1000], array_10000[10000], array_100000[100000];
    for (int &i : array_10) {
        i = 1 + mersenne() % 10;
        outputInsertionSort << i << ' ';
    }
    outputInsertionSort << std::endl;
    for (int &i : array_100) {
        i = 1 + mersenne() % 100;
        outputInsertionSort << i << ' ';
    }
    outputInsertionSort << std::endl;
    for (int &i : array_1000) {
        i = 1 + mersenne() % 1000;
        outputInsertionSort << i << ' ';
    }
    outputInsertionSort << std::endl;
    for (int &i : array_10000) {
        i = 1 + mersenne() % 10000;
        outputInsertionSort << i << ' ';
    }
    outputInsertionSort << std::endl;
    for (int &i : array_100000) {
        i = 1 + mersenne() % 100000;
        outputInsertionSort << i << ' ';
    }
    outputInsertionSort << std::endl << std::endl << std::endl;

    auto startTime = std::chrono::high_resolution_clock::now();
    InsertionSort(array_10, 10);
    auto finishTime = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime);
    outputInsertionSort << "10 elements: " << time.count() << std::endl;

    startTime = std::chrono::high_resolution_clock::now();
    InsertionSort(array_100, 100);
    finishTime = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime);
    outputInsertionSort << "100 elements: " << time.count() << std::endl;

    startTime = std::chrono::high_resolution_clock::now();
    InsertionSort(array_1000, 1000);
    finishTime = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime);
    outputInsertionSort << "1000 elements: " << time.count() << std::endl;

    startTime = std::chrono::high_resolution_clock::now();
    InsertionSort(array_10000, 10000);
    finishTime = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime);
    outputInsertionSort << "10000 elements: " << time.count() << std::endl;

    startTime = std::chrono::high_resolution_clock::now();
    InsertionSort(array_100000, 100000);
    finishTime = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime);
    outputInsertionSort << "100000 elements: " << time.count() << std::endl;

    outputInsertionSort << std::endl << std::endl << std::endl;
    outputInsertionSort << "Sorted arrays: " << std::endl;

    outputInsertionSort << "The first one: " << std::endl << "////////";
    for (int &i : array_10) {
        outputInsertionSort << i << ' ';
    }
    outputInsertionSort << "////////" << std::endl;
    outputInsertionSort << "The seconds one: " << std::endl << "////////";
    for (int &i : array_100) {
        outputInsertionSort << i << ' ';
    }
    outputInsertionSort << "////////" << std::endl;
    outputInsertionSort << "The third one: " << std::endl << "////////";
    for (int &i : array_1000) {
        outputInsertionSort << i << ' ';
    }
    outputInsertionSort << "////////" << std::endl;
    outputInsertionSort << "The forth one: " << std::endl << "////////";
    for (int &i : array_10000) {
        outputInsertionSort << i << ' ';
    }
    outputInsertionSort << "////////" << std::endl;
    outputInsertionSort << "The fifth one: " << std::endl << "////////";
    for (int &i : array_100000) {
        outputInsertionSort << i << ' ';
    }
    outputInsertionSort << "////////" << std::endl;

    outputInsertionSort.close();
}

void TreeSort(int *array, size_t size) {
    if (size == 0) {
        throw std::out_of_range("Array is empty");
    }

    BinaryTree sortTree;
    for (int i = 0; i < size; i++) {
        sortTree.insert(array[i]);
    }

    Iterator *iterator = sortTree.create_dft_iterator();
    int i = 0;
    while (iterator->has_next()) {
        array[i] = iterator->next()->get_data();
        i++;
    }
    delete iterator;

}

void outputTreeSort() {
    std::fstream treeSortOutputFile;
    treeSortOutputFile.open("TreeSortOutput.txt", std::ios::out);
    std::random_device rd;
    std::mt19937 mersenne(rd());

    int array[100], size = 100;
    treeSortOutputFile << "Array: " << std::endl;
    for (int i = 0; i < size; i++) {
        array[i] = mersenne() % 100;
        treeSortOutputFile << array[i] << ' ';
    }
    treeSortOutputFile << std::endl << std::endl;
    TreeSort(array, size);
    treeSortOutputFile << "Sorted array: " << std::endl;
    for (int i = 0; i < size; i++) {
        treeSortOutputFile << array[i] << ' ';
    }

    treeSortOutputFile.close();
}

void BogoSort(int *array, size_t size) {
    if (size == 0) {
        throw std::out_of_range("Array is empty");
    } else if (size > 6) {
        std::cerr << "I am afraid that the sort will lasts for the rest of our life" << std::endl;
    }

    while (!checkSortedArray(array, size)) {
        shakeShakeShake(array, size);
    }
}

void CountingSort(char *array, size_t size) {
    if (size == 0) {
        throw std::out_of_range("Array is empty");
    }

    size_t frequency[256]{0};
    for (size_t i = 0; i < size; i++) {
        frequency[array[i]]++;
    }
    size_t position = 0;
    for (size_t number = 0; number <= 255; number++) {
        for (size_t i = 0; i < frequency[number]; i++) {
            array[position] = number;
            position++;
        }
    }
}

bool checkSortedArray(const int *array, size_t size) {
    if (size == 0) {
        throw std::out_of_range("Array is empty");
    }

    while (size-- > 0) {
        if (array[size - 1] > array[size]) {
            return false;
        }
    }

    return true;
}

void shakeShakeShake(int *array, size_t size) {
    if (size == 0) {
        throw std::out_of_range("Array is empty");
    }

    std::random_device rd;
    std::mt19937 mersenne(rd());
    for (auto i = 0; i < size; i++) {
        std::swap(array[i], array[mersenne() % size]);
    }
}