//
// Created by golde on 2/24/2020.
//

#include "HashTable.h"
#include <list>
#include <vector>
#include <string>

int HashTable::hashFunction(std::string item) {
    int hash = 0;
    for (int i = 0; i < item.size(); ++i) {
        char tempo = item[i];
        hash += (int) item[i];
    }
    return hash % 1000;
}

HashTable::HashTable(int size) {
    hashed = new std::vector<std::string>[size];
    this->size = size;
}

void HashTable::insertItem(std::string item) {
    int index = hashFunction(item);
    hashed[index].push_back(item);
}

bool HashTable::checkItem(std::string item) {
    int index = hashFunction(item);
    std::vector<std::string> tempo = hashed[index];
    for (auto x:tempo) {
        if (x == item) {
            return true;
        }
    }
    return false;
}

int HashTable::getMaxCollisions() const {
    int max = 0;
    for (int i = 0; i < size; ++i) {
        std::vector<std::string> tempo = hashed[i];
        if (tempo.size() > max)max = tempo.size();
    }
    return max;
}



