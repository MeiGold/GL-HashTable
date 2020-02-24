#include <iostream>
#include <list>
#include <vector>
#include <string>

class SeparateChaining{
private:
    int size;
    std::vector<std::string> *hashed;

    int hashFunction(std::string item){
        int hash = 0;
        for(int i=0;i<item.size();++i){
            char tempo = item[i];
            hash+=(int)item[i];
        }
        return hash%1000;
    }
public:
    SeparateChaining(int size){
        hashed = new std::vector<std::string>[size];
        this->size=size;
    }

    void insertItem(std::string item){
        int index = hashFunction(item);
        hashed[index].push_back(item);
    }

    bool checkItem(std::string item){
        int index = hashFunction(item);
        std::vector<std::string> tempo = hashed[index];
        for(auto x:tempo){
            if(x==item){
                return true;
            }
        }
        return false;
    }

    int getMaxCollisions() const{
        int max=0;
        for(int i=0;i<size;++i){
            std::vector<std::string> tempo = hashed[i];
            if(tempo.size()>max)max=tempo.size();
        }
        return max;
    }



};

int main() {
    SeparateChaining a(1000);
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
