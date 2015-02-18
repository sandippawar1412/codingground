#ifndef LRUCACHE_H
#define LRUCACHE_H

#define LRU_CAPACITY 10

#include "DCLL.h"
#include <unordered_map>

using namespace std;

class LRUCache {
    int capacity;
    DoubleCircularLinkedList dcll;
    std::unordered_map<int, node* > cache;
    
  public :
    LRUCache(int size=LRU_CAPACITY){
      capacity = size ;
    }
    ~LRUCache()
    {
    }
    
    void set(int , int );
    void printCache();
    void printList();
    void clear();
    bool has_key(int );
    void deleteEntry (int );
    int get(int );
    
    
};

#endif