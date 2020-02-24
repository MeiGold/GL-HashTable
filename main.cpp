#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "HashTable.h"

int main() {
    HashTable a(1000);
    std::string dictionary[] = {
            "a", "or", "ro", "and", "asterisk", "zorb", "zorg", "ant", "cat", "rat", "rack","ro"
    };

    for(auto w : dictionary) {
        a.insertItem(w);
    }

    for(auto w : dictionary) {
        if (!a.checkItem(w)) {
            std::cout << "Exists check failed!" << std::endl;
        }
    }

    std::string badWords[] = {
            "aa", "oro", "b", "asteriska", "zorba", "zork", "racks"
    };

    for(auto w : badWords) {
        if (a.checkItem(w)) {
            std::cout << "NOT Exists check failed!" << std::endl;
        }
    }
    std::cout << "Maximal collisions count " << a.getMaxCollisions() << std::endl;
    return 0;
}
