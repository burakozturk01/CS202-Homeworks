/**
* Author : Burak Ozturk
* ID: 21901841
* Section : 01
* Assignment : 4
*/


#include <iostream>
#include "HashTable.h"

// Reverses an integer digit-wise
int reverse(int num) {
    int remainder, reversed = 0;

    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    return reversed;
}

// Constructor
HashTable::HashTable(const int tableSize, const CollisionStrategy option) {
    // Table size can't be smaller than 1 and
	// CollisionStrategy must be one of three choises
	if (tableSize < 1 || !(option == LINEAR || option == QUADRATIC || option == DOUBLE))
        return;
	
	// table starts as all initiated to zero
    table = new int[tableSize]{0};
	
	// To keep track of bucket states
    states = new BucketState[tableSize]{EMPTY};

	// Initializing class properties
    this->tableSize = tableSize;
    cs = option;

}

// Destructor
HashTable::~HashTable() {
    delete[] table;
    delete[] states;
}

bool HashTable::insert(const int item) {
    int index;
    for (int i = 0; i < tableSize; i++) {
		
		// Calculates index according to CollisionStrategy
        switch (cs) {
            case LINEAR:
                index = (item + i) % tableSize;
                break;
            case QUADRATIC:
                index = (item + i * i) % tableSize;
                break;
            case DOUBLE:
                index = (item + i * reverse(item)) % tableSize;
                break;
        }
		
		// Index can be negative for negative items
        if (index < 0)
            index += tableSize;
		
		// If the bucket is empty, put the item to there
        if (states[index] == EMPTY) {
            states[index] = FULL;
            table[index] = item;
            return true;
        }
		
		// If the item was in there, re-activate that bucket
        else if ((states[index] == DELETED) && (table[index] == item)) {
            states[index] = FULL;
        }
		
        else {
			// If bucket is full and the item is there, unsuccessful
            if (table[index] == item)
                return false;
			// If item is not there continue.
            else
                continue;
        }
    }
	// If the item couldn't be placed to the whole list, unsuccessful
    return false;
}

bool HashTable::remove(const int item) {
    int index;
    for (int i = 0; i < tableSize; i++) {
		
		// Calculates index according to CollisionStrategy
        switch (cs) {
            case LINEAR:
                index = (item + i) % tableSize;
                break;
            case QUADRATIC:
                index = (item + i * i) % tableSize;
                break;
            case DOUBLE:
                index = (item + i * reverse(item)) % tableSize;
                break;
        }
		
		// Index can be negative for negative items
        if (index < 0)
            index += tableSize;
		
		// If the bucket is full and item is there, mark it as deleted and successful
        if ((states[index] == FULL) && (table[index] == item)) {
            states[index] = DELETED;
            return true;
        }
		
		// If the bucket is not empty, continue
        else if (states[index] != EMPTY)
            continue;
		
		// Otherwise, unsuccessful
        else
            return false;
    }
	
	// If after traversing whole table item couldn't be removed, unsuccessful
    return false;
}

bool HashTable::search(const int item, int& numProbes) {
    int index;
    numProbes = 0;
    for (int i = 0; i < tableSize; i++) {
        numProbes++;
        switch (cs) {
            case LINEAR:
                index = (item + i) % tableSize;
                break;
            case QUADRATIC:
                index = (item + i * i) % tableSize;
                break;
            case DOUBLE:
                index = (item + i * reverse(item)) % tableSize;
                break;
        }
		
		// Index can be negative for negative items
        if (index < 0)
            index += tableSize;
		
		// If the bucket is full and item is there, successful
        if ((states[index] == FULL) && (table[index] == item))
            return true;
		
		// If the bucket is not empty, continue
        else if (states[index] != EMPTY)
            continue;
		
		// Otherwise, unsuccessful
        else
            return false;
    }
	
	// If after traversing whole table item couldn't be found, unsuccessful
    return false;
}

void HashTable::display() {
    for (int i = 0; i < tableSize; i++) {
		// "i: "
        std::cout << i << ": ";
		
		// isFULL ? value : ""
        if (states[i] == FULL)
            std::cout << table[i];
		
		// "\n"
        std::cout << std::endl;
    }
}

void HashTable::analyze(int& numSuccProbes, int& numUnsuccProbes) {
	
	// Setting outputs to zero in case of left over values
    numSuccProbes = 0; numUnsuccProbes = 0;
	
	// Probe counter
    int probes;
	
	// For every value in table,
    for (int i = 0; i < tableSize; i++) {
        probes = 0;
		
		// if the state of the bucket is FULL
        if (states[i] == FULL) {
			
			// search the HashTable for that value
            search(table[i], probes);
			
			// and add results to numSuccProbes
            numSuccProbes += probes;
        }
		
		// and for unsuccessfulls, from every index search for next available
		// then add probe count to numUnsuccProbes
        numUnsuccProbes += firstEmptyIndex(i);
    }
	
	// For DOUBLE, -1
    if (cs == DOUBLE) numUnsuccProbes = -1;
}

int HashTable::firstEmptyIndex(const int startIndex) {
	// startIndex must be in ange [0, tableSize)
	// if CollisionStrategy is DOUBLE, -1
    if ((startIndex < 0) || (startIndex >= tableSize) || (cs == DOUBLE)) {
        return -1;
    }
    int index, i;
    for (i = 0; i < tableSize; i++) {
		// Calculate index according to CollisionStrategy
        switch (cs) {
            case LINEAR:
                index = (startIndex + i) % tableSize;
                break;
            case QUADRATIC:
                index = (startIndex + i * i) % tableSize;
                break;
        }
		
		// i + 1 gives the probe count
        if (states[index] == EMPTY)
            return (i + 1);
    }
	// i + 1 gives the probe count
    return (i + 1);
}