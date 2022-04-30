/**
* Author : Burak Ozturk
* ID: 21901841
* Section : 01
* Assignment : 4
*/


#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "HashTable.h"

using namespace std;

int main() {
	
	// Change this values for different tableSize's and CollisionStrategy's
    const int tableSize = 13;
    const CollisionStrategy collisionStrategy = DOUBLE;

    fstream file;

    file.open(R"(D:\bilkent\3rdYear\Fall\CS202\Homeworks\HW4\Project\input.txt)", ios::in);

    string read;

    if (file.is_open()) {

        HashTable ht(tableSize, collisionStrategy);

        int index, number, probes;
        string reverseNumber;
		
		// Read line
        while (getline(file, read)) {
			
			// Get number as a string, reversed and ending with '*'
            read += '*';
            reverseNumber = "";
            for (index = 2; read.at(index) != '*'; index++)
                reverseNumber = read.at(index) + reverseNumber;
            reverseNumber += '*';
			
			// Convert string to int
            number = 0;
            for (int i = 0; reverseNumber.at(i) != '*'; i++) {
                number += (((int) reverseNumber.at(i)) - ((int) '0')) * pow(10, i);
            }
			
			// I: insert
            if (read.at(0) == 'I') {
                if (ht.insert(number))
                    cout << number << " inserted" << endl;
                else
                    cout << number << " not inserted" << endl;
            }
			
			// R: remove
            else if (read.at(0) == 'R') {
                if (ht.remove(number))
                    cout << number << " removed" << endl;
                else
                    cout << number << " not removed" << endl;
            }
			
			// S: search
            else if (read.at(0) == 'S') {
                probes = 0;
                if (ht.search(number, probes))
                    cout << number << " found after " << probes << " probes" << endl;
                else
                    cout << number << " not found after " << probes << " probes" << endl;
            }
        }
		
		// Report CollisionStrategy and tableSize
        cout << endl << "Collision strategy: " << ((collisionStrategy == LINEAR) ? "Linear" : ((collisionStrategy == QUADRATIC) ? "Quadratic" : "Double"));
        cout << endl << "Table size: " << tableSize << endl;

        int succ, unSucc;

        ht.display();
        ht.analyze(succ, unSucc);

        cout << endl << "Successful probes:   " << succ;
        cout << endl << "Unsuccessful probes: " << unSucc;

        file.close();
    }
    return 0;

}
