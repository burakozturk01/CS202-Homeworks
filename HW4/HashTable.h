/**
* Author : Burak Ozturk
* ID: 21901841
* Section : 01
* Assignment : 4
*/

#ifndef PROJECT_HASHTABLE_H
#define PROJECT_HASHTABLE_H

enum CollisionStrategy {LINEAR, QUADRATIC, DOUBLE};
enum BucketState {EMPTY, DELETED, FULL};

class HashTable {
public:
    HashTable(const int tableSize, const CollisionStrategy option);
    ~HashTable();

    bool insert(const int item);

    bool remove(const int item);

    bool search(const int item, int& numProbes);

    void display();

    void analyze(int& numSuccProbes, int& numUnsuccProbes);

private:
    int* table;
    int tableSize;
    CollisionStrategy cs;
    BucketState* states;

    int firstEmptyIndex(const int startIndex);
};


#endif //PROJECT_HASHTABLE_H
