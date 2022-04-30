/**
*Title: Algorithm Efficiency and Sorting
*Author: Burak Ozturk
*ID: 21901841
*Section: 1
*Assignment: 1
*Description: main file for sorting algorithms for HW1
*/

#include <iostream>
#include <string>
#include "sorting.h"

int main () {
	int arr[16] = {7,3,6,12,13,4,1,9,15,0,11,14,2,8,10,5};	
	
	int tmp[16];

	int tmp1, tmp2;

	for (int i = 0; i < 16; i++)
		tmp[i] = arr[i];
	insertionSort(tmp, 16, tmp1, tmp2);
	printArray(tmp, 16);

	for (int i = 0; i < 16; i++)
		tmp[i] = arr[i];
	mergeSort(tmp, 16, tmp1, tmp2);
	printArray(tmp, 16);

	for (int i = 0; i < 16; i++)
		tmp[i] = arr[i];
	quickSort(tmp, 16, tmp1, tmp2);
	printArray(tmp, 16);

	for (int i = 0; i < 16; i++)
		tmp[i] = arr[i];
	radixSort(tmp, 16);
	printArray(tmp, 16);
	
	performanceAnalysis();
	
	// This is to make command line wait after results show up
	char wait[10];
	std::cin.get(wait, 10);
	
	return 0;
}
