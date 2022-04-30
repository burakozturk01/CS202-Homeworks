#include <iostream>
#include <string>
using namespace std;

#include "NgramTree.h"
int main() {
    NgramTree tree;
    string fileName = "testFile.txt";
    int n = 4;

    tree.generateTree(fileName, n);

    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << tree << endl;

    cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;
    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No");

    // Before insertion of new n-grams
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;

    n = 3;
    tree.generateTree(fileName, n);

    tree.addNgram("sam");
    tree.addNgram("amp");
    tree.addNgram("zic");
    tree.addNgram("att");

    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << tree << endl;

    cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;
    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No");

    getline(cin, fileName);
}