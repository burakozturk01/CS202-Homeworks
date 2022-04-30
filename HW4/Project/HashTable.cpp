/**
* Author : Burak Ozturk
* ID: 21901841
* Section : 01
* Assignment : 4
*/


#include <iostream>
#include "HashTable.h"

int reverse(int num) {
    int remainder, reversed = 0;

    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    return reversed;
}

HashTable::HashTable(const int tableSize, const CollisionStrategy option) {
    if (tableSize < 1 || !(option == LINEAR || option == QUADRATIC || option == DOUBLE))
        return;

    table = new int[tableSize]{0};
    states = new BucketState[tableSize]{EMPTY};

    this->tableSize = tableSize;
    cs = option;

}

HashTable::~HashTable() {
    delete[] table;
    delete[] states;
}

bool HashTable::insert(const int item) {
    int index;
    for (int i = 0; i < tableSize; i++) {
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

        if (index < 0)
            index += tableSize;
        if (states[index] == EMPTY) {
            states[index] = FULL;
            table[index] = item;
            return true;
        }
        else if ((states[index] == DELETED) && (table[index] == item)) {
            states[index] = FULL;
        }
        else {
            if (table[index] == item)
                return false;
            else
                continue;
        }
    }
    return false;
}

bool HashTable::remove(const int item) {
    int index;
    for (int i = 0; i < tableSize; i++) {
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
        if (index < 0)
            index += tableSize;
        if ((states[index] == FULL) && (table[index] == item)) {
            states[index] = DELETED;
            return true;
        }
        else if (states[index] != EMPTY)
            continue;
        else
            return false;
    }
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
        if (index < 0)
            index += tableSize;
        if ((states[index] == FULL) && (table[index] == item))
            return true;
        else if (states[index] != EMPTY)
            continue;
        else
            return false;
    }
    return false;
}

void HashTable::display() {
    for (int i = 0; i < tableSize; i++) {
        std::cout << i << ": ";
        if (states[i] == FULL)
            std::cout << table[i];
        std::cout << std::endl;
    }
}

void HashTable::analyze(int& numSuccProbes, int& numUnsuccProbes) {
    numSuccProbes = 0; numUnsuccProbes = 0;
    int probes;
    for (int i = 0; i < tableSize; i++) {
        probes = 0;
        if (states[i] == FULL) {
            search(table[i], probes);
            numSuccProbes += probes;
        }

        numUnsuccProbes += firstEmptyIndex(i);
    }
    if (cs == DOUBLE) numUnsuccProbes = -1;
}

int HashTable::firstEmptyIndex(const int startIndex) {
    if ((startIndex < 0) || (startIndex >= tableSize) || (cs == DOUBLE)) {
        return -1;
    }
    int index, i;
    for (i = 0; i < tableSize; i++) {
        switch (cs) {
            case LINEAR:
                index = (startIndex + i) % tableSize;
                break;
            case QUADRATIC:
                index = (startIndex + i * i) % tableSize;
                break;
        }
        if (states[index] == EMPTY)
            return (i + 1);
    }
    return (i + 1);
}