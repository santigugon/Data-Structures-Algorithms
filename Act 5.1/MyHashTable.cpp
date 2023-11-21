
#include "MyLinkedList.h"
#include "MyHashTable.h"

MyHashTable::MyHashTable(){

    this->size=0;
    this->sizeA=11;
    this->tabla=new MyLinkedList();
}

int MyHashTable::getPos(string key){
    size_t hashC=hash<string>{}(key);
    int hashCode=static_cast<int>(hashC);
    return abs(hashCode)%this->sizeA;
}
