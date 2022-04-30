/**
*Title: Algorithm Efficiency and Sorting
*Author: Burak Ozturk
*ID: 21901841
*Section: 1
*Assignment: 1
*Description: Header file for source file of sorting algorithms for HW1
*/

#ifndef PROJECT_SORTING_H
#define PROJECT_SORTING_H


void insertionSort (int *arr, const int size, int &compCount, int &moveCount);

void mergeSort(int *arr, const int size, int &compCount, int &moveCount);

void quickSort(int *arr, const int size, int &compCount, int &moveCount);

void radixSort(int *arr, const int size);

void printArray(int *arr, int size);

void performanceAnalysis();

void merge( int *arr, int *second, int size1, int size2, int &compCount, int &moveCount);

void swap(int &first, int &second, int &moveCount);

void choosePivot (int theArray[], int first, int last);

void partition(int theArray[], int first, int last, int &pivotIndex, int &compCount, int &moveCount);

void quicksort(int theArray[], int first, int last, int &compCount, int &moveCount);

// Returns maximum value of given array
int getMax(int *arr, const int size);

// Sorts array for given exp
void countSort(int *arr, const int size, const int exp);

int countDigit(int number);

#endif //PROJECT_SORTING_H
