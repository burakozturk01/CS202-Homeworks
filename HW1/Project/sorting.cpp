/**
*Title: Algorithm Efficiency and Sorting
*Author: Burak Ozturk
*ID: 21901841
*Section: 1
*Assignment: 1
*Description: Source file for implementations of sorting algorithms for HW1
*/

#include <iostream>
#include <stdio.h>
#include <chrono>

void insertionSort (int *arr, const int size, int &compCount, int &moveCount) {
    for (int unsorted = 1; unsorted < size; ++unsorted) {

        int nextItem = arr[unsorted];
        ++moveCount;

        int loc = unsorted;

        // A comp and a move carried out before every iteration of this for loop.
        for (  ;(loc > 0) && (arr[loc-1] > nextItem); --loc) {
            arr[loc] = arr[loc - 1];
            ++compCount;
            ++moveCount;
        }
        // If loc > 0, then one last comp must be carried out that ended for loop.
        // If not compiler most likely won't look to right side of && operator.
        if (loc > 0)
            ++compCount;

        arr[loc] = nextItem;
        ++moveCount;

    }
}

void merge( int *arr, int *second, int size1, int size2, int &compCount, int &moveCount) {
    int tempArray[size1+size2];    // temporary array

    int first1 = 0;    // beginning of first subarray
    int last1 = size1 - 1;        // end of first subarray
    int first2 = size1;    // beginning of second subarray
    int last2 = size1 + size2 - 1;        // end of second subarray
    int index = first1; // next available location in tempArray

    for (; (first1 <= last1) && (first2 <= last2); ++index) {

        if (arr[first1] < arr[first2]) {
            tempArray[index] = arr[first1];
            ++first1;
        } else {
            tempArray[index] = arr[first2];
            ++first2;
        }
        compCount++;
        moveCount++;
    }

    // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index) {
        tempArray[index] = arr[first1];
        ++moveCount;
    }

    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index) {
        tempArray[index] = arr[first2];
        ++moveCount;
    }

    // copy the result back into the original array
    for (index = 0; index < size1+size2; ++index) {
        arr[index] = tempArray[index];
        ++moveCount;
    }

}

void mergeSort(int *arr, const int size, int &compCount, int &moveCount) {
    int *second = arr + (size / 2);

    if (size > 1 && arr < second) {
        mergeSort(arr, size/2, compCount, moveCount);

        mergeSort(second, size - size/2, compCount, moveCount);

        // merge the two halves
        merge(arr, second, size/2, size - size/2, compCount, moveCount);
    }
}

void swap(int &first, int &second, int &moveCount) {
    int temp = first;
    first = second;
    second = temp;

    moveCount += 3;
}

void choosePivot (int theArray[], int first, int last) {
    // Pivot is left as the first element
}

void partition(int theArray[], int first, int last, int &pivotIndex, int &compCount, int &moveCount) {
    // Precondition: theArray[first..last] is an array; first <= last.
    // Postcondition: Partitions theArray[first..last] such that:
    //   S1 = theArray[first..pivotIndex-1] < pivot
    //   theArray[pivotIndex] == pivot
    //   S2 = theArray[pivotIndex+1..last] >= pivot

    // place pivot in theArray[first]
    choosePivot(theArray, first, last);

    int pivot = theArray[first]; // copy pivot
    moveCount++;

    // initially, everything but pivot is in unknown
    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in unknown

    // move one item at a time until unknown region is empty
    for (  ; firstUnknown <= last; ++firstUnknown) {
        // Invariant: theArray[first+1..lastS1] < pivot
        //            theArray[lastS1+1..firstUnknown-1] >= pivot

        // move item from unknown to proper region
        if (theArray[firstUnknown] < pivot) {  	// belongs to S1
            ++lastS1;
            swap(theArray[firstUnknown], theArray[lastS1], moveCount);
        }	// else belongs to S2
        compCount++;
    }
    // place pivot in proper position and mark its location
    swap(theArray[first], theArray[lastS1], moveCount);
    pivotIndex = lastS1;
}

void quicksort(int theArray[], int first, int last, int &compCount, int &moveCount) {
    // Precondition: theArray[first..last] is an array.
    // Postcondition: theArray[first..last] is sorted.

    int pivotIndex;

    if (first < last) {

        // create the partition: S1, pivot, S2
        partition(theArray, first, last, pivotIndex, compCount, moveCount);

        // sort regions S1 and S2
        quicksort(theArray, first, pivotIndex-1, compCount, moveCount);
        quicksort(theArray, pivotIndex+1, last, compCount, moveCount);
    }
}

void quickSort(int *arr, const int size, int &compCount, int &moveCount) {
    quicksort(arr, 0, size-1, compCount, moveCount);
}

// Returns maximum value of given array
int getMax(int *arr, const int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Sorts array for given exp
void countSort(int *arr, const int size, const int exp) {
    int temp[size];
    int count[10] = {0};

    // count counts occurences of digits
    for (int i = 0; i < size; ++i)
        count[(arr[i] / exp) % 10]++;

    // Updating count[i] to contain actual positions of digits
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Forms temporary array
    for (int i = size - 1; i >= 0; i--) {
        temp[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Transfers temporary to actual array
    for (int i = 0; i < size; i++)
        arr[i] = temp[i];
}

void radixSort(int *arr, const int size) {
    int max = getMax(arr, size);

    // Does counting sort for every digit
    // exp is 10^i where i is current digit
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(arr, size, exp);
}

void printArray(int *arr, int size) {
    std::cout << "[" << arr[0];
    for (int i = 1; i < size; i++) {
        std::cout << ", " << arr[i];
    }
    std::cout << "]\n\n";
}

int countDigit(int number) {
    if (!number)
        return 1;
    int count = 0;
    while(number != 0) {
        number = number / 10;
        count++;
    }
    return count;
}

void performanceAnalysis() {
    // Variablized for modifiablity
    const int sizeCount = 8;

    // Sizes are incremented cause original values are too small to measure
    int sizes[sizeCount] = {14000, 18000, 22000, 26000, 30000, 34000, 38000, 42000};

    // Resetted after each algorithm
    double times[sizeCount];
    int compCounts[sizeCount] = {0};
    int moveCounts[sizeCount] = {0};

    // Original array generated with maximum size
    // and smaller arrays are being cutted from its start
    int origArr[sizes[7]];
    for (int i = 0; i < sizes[7]; i++) {
        origArr[i] = rand();
    }

    for (int t = 0; t < 4; t++) {
        switch (t) {
            case 0:
                std::cout << "-----------------------------------------------------\n"
                          << "Part a - Time Analysis of Insertion Sort\n"
                          << "Array Size     Time Elapsed       compCount       moveCount\n";
                break;
            case 1:
                std::cout << "-----------------------------------------------------\n"
                          << "Part b - Time Analysis of MergeSort\n"
                          << "Array Size     Time Elapsed       compCount       moveCount\n";
                break;
            case 2:
                std::cout << "-----------------------------------------------------\n"
                          << "Part c - Time Analysis of QuickSort\n"
                          << "Array Size     Time Elapsed       compCount       moveCount\n";
                break;
            case 3:
                std::cout << "-----------------------------------------------------\n"
                             << "Part d - Time Analysis of Radix Sort\n"
                             << "Array Size     Time Elapsed       compCount       moveCount\n";
                break;
        }

        for (int i = 0; i < sizeCount; i++) {

            // Allocate array for size i
            int arr[sizes[i]];

            // Cut original array for that size and copy to array
            for (int j = 0; j < sizes[i]; j++)
                arr[j] = origArr[j];

            auto start = std::chrono::high_resolution_clock::now();

            switch (t) {
                case 0:
                    insertionSort(arr, sizes[i], compCounts[i], moveCounts[i]);
                    break;
                case 1:
                    mergeSort(arr, sizes[i], compCounts[i], moveCounts[i]);
                    break;
                case 2:
                    quickSort(arr, sizes[i], compCounts[i], moveCounts[i]);
                    break;
                case 3:
                    radixSort(arr, sizes[i]);
                    break;
                default:
                    std::cout << "Switch case error\n";
            }

            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

            times[i] = duration.count() / 1000000.0;
            // Time stored in times[]

        }

        // This loop is for printing only
        // There are digit counting, filling with spaces etc.
        for (int j = 0; j < sizeCount; j++) {
            int digits;
            std::cout << sizes[j] << "      ";

            printf("%13f ms", times[j]);

            digits = countDigit(compCounts[j]);
            for (int i = 0; i < (16 - digits); i++)
                std::cout << " ";
            std:: cout << compCounts[j];

            digits = countDigit(moveCounts[j]);
            for (int i = 0; i < (16 - digits); i++)
                std::cout << " ";
            std:: cout << moveCounts[j] << std::endl;
        }

        // Resetting comp and move counts
        for (int i = 0; i < sizeCount; i++) {
            compCounts[i] = 0;
            moveCounts[i] = 0;
        }
    }
}