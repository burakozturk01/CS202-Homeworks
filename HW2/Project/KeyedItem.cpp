/**
* Title: Trees
* Author: Burak Ozturk
* ID: 21901841
* Assignment: 2
* Description: Source file for custom KeyedItem class
*/

#include <string>
#include <iostream>

#include "KeyedItem.h"

KeyedItem::KeyedItem () {
    searchKey = "";
    count = 1;
}

KeyedItem::KeyedItem(const std::string& keyValue):count(1) {
    std::string lowerCase = keyValue;

    for (int i = 0; ((int) lowerCase[i] ) != 0; ++i) {
        if (((int) lowerCase[i] ) >= 65 && ((int) lowerCase[i] ) <= 90)
            lowerCase[i] += 32;
    }

    searchKey = lowerCase;
}

KeyedItem::KeyedItem(KeyedItem &otherKeyedItem) {
    searchKey = otherKeyedItem.searchKey;
    count = otherKeyedItem.count;
}
KeyedItem::~KeyedItem() {
}

std::string KeyedItem::getKey() const {
    return searchKey;
}

int KeyedItem::getCount() const {
    return count;
}

void KeyedItem::changeCount(const int difference) {
    count += difference;
}