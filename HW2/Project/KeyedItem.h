/**
* Title: Trees
* Author: Burak Ozturk
* ID: 21901841
* Assignment: 2
* Description: Header file for custom KeyedItem class
*/

#ifndef PROJECT_KEYEDITEM_H
#define PROJECT_KEYEDITEM_H

#include <string>
#include <iostream>

class KeyedItem {
public:
    KeyedItem();
    KeyedItem(const std::string& keyValue);
    KeyedItem(KeyedItem &otherKeyedItem);
    ~KeyedItem();

    std::string getKey() const;

    int getCount() const;

    void changeCount(const int difference);

private:
    std::string searchKey;
    int count;
};
#endif //PROJECT_KEYEDITEM_H
