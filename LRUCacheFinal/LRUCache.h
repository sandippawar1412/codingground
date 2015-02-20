#ifndef LRUCACHE_H
#define LRUCACHE_H

#define LRU_CAPACITY 10

#include "DCLL.h"
#include <unordered_map>

using namespace std;

template <class T1, class T2>
class LRUCache {
    int capacity;
    DoubleCircularLinkedList<T1, DoubleCircularLinkedList<T1, T2>* > dcll;
    std::unordered_map<T1, node<T1, T2>* > cache;
    
  public :
    LRUCache(int size=LRU_CAPACITY){
      capacity = size ;
    }
    ~LRUCache()
    {
        clear();
        capacity=0;
    }
    
    void set(T1 , T2 );
    void printCache();
    void printList();
    void clear();
    bool has_key(T1 );
    void deleteEntry (T1 );
    bool get(T1 );
    void setSize(int );
    
};

#include "LRUCache.cpp"

#endif