//
// Created by golde on 2/24/2020.
//

#ifndef UNTITLED_HASHTABLE_H
#define UNTITLED_HASHTABLE_H

#include <vector>
#include <string>

class HashTable {
private:
    int size;
    std::vector<std::string> *hashed;
    int hashFunction(std::string item);
public:
    HashTable(int size);
    void insertItem(std::string item);
    bool checkItem(std::string item);
    int getMaxCollisions() const;

};


#endif //UNTITLED_HASHTABLE_H
