#ifndef LRUCACHE_CPP
#define LRUCACHE_CPP

#include "LRUCache.h"
#include <iostream>
using namespace std;


template <class T1, class T2>
void LRUCache<T1, T2> :: printCache()
{
    for(typename std::unordered_map<T1, node<T1, T2>*>::const_iterator it=cache.begin();it!=cache.end();it++){
        cout<<it->first<<" "<<it->second->value<<endl ;
    }
}

template <class T1, class T2>
void LRUCache<T1, T2> :: printList()
{
    cout<<"Cache Size = "<<capacity<<endl ;
    dcll.printList();
}

template <class T1, class T2>
void LRUCache<T1, T2> :: clear()
{
    for(typename std::unordered_map<T1, node<T1, T2>*>::const_iterator it=cache.begin();it!=cache.end();it++){
        cache.erase(it);
    } 
    dcll.clear();
}

template <class T1, class T2>
bool LRUCache<T1, T2> :: has_key(T1 key)
{
    if(cache.find(key)!=cache.end())
        return true;
    else 
        return false;
}

template <class T1, class T2>
void LRUCache<T1, T2> :: deleteEntry (T1 key)
{
    typename std::unordered_map<T1, node<T1, T2>*>:: iterator it = cache.find(key);
    if(it!=cache.end()){
        dcll.remove(it->second);
        cache.erase(it);
    }
}

template <class T1, class T2>
bool LRUCache<T1, T2> :: get(T1 key)
{
    typename std::unordered_map<T1, node<T1,T2>*>:: iterator it = cache.find(key);
    try
    {
        if(it!=cache.end()){
            dcll.moveback(it->second);
            cout<< it->second->value<<endl; //changeMe  this is again a list.. 
            return true;
        }
        else {
            throw "Key Not Present";   
        }
    }
    catch(const char* msg)
    {
        cerr<<msg<<endl;
         return false ;
    }
}

template <class T1, class T2>
void LRUCache<T1, T2> :: set(T1 key, T2 value) 
{//changeMe no need to check if key already present.. needs one more function 
    if(has_key(key)){
        typename std::unordered_map<T1, node<T1, T2>*>::iterator it = cache.find(key);
        dcll.update(it->second,value);
        dcll.moveback(it->second);
    }
    else if(capacity>0){
        if(capacity > dcll.getCount())    
            cache[key] = dcll.append(key, value);
        else {
            T1 oldKey = dcll.popKey(); //it also return -1 but we will not face this situation
            cache.erase(cache.find(oldKey));
            cache[key] = dcll.append(key, value);
        }
    }    
}

template <class T1, class T2>
void LRUCache<T1, T2> :: setSize(int size)
{
    int adjustDiff = size-dcll.getCount() ;
    while(adjustDiff++<0){     //delete adjustDiff entries using LRU..
        T1 key = dcll.popKey(); 
        cache.erase(cache.find(key));
    }
    capacity=size ;
}

#endif
        
    