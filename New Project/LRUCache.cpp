
#include "LRUCache.h"
#include <iostream>
using namespace std;

void LRUCache :: printCache()
{
    for(std::unordered_map<int, node*>::const_iterator it=cache.begin();it!=cache.end();it++){
        cout<<it->first<<" "<<it->second->value<<endl ;
    }
}

void LRUCache :: printList()
{
    cout<<"Cache Size = "<<capacity<<endl ;
    dcll.printList();
}

    
void LRUCache :: clear()
{
    for(std::unordered_map<int, node*>::const_iterator it=cache.begin();it!=cache.end();it++){
        cache.erase(it);
    } 
    dcll.clear();
}

bool LRUCache :: has_key(int key)
{
    if(cache.find(key)!=cache.end())
        return true;
    else 
        return false;
}

void LRUCache :: deleteEntry (int key)
{
    std::unordered_map<int, node*>:: iterator it = cache.find(key);
    if(it!=cache.end()){
        dcll.remove(it->second);
        cache.erase(it);
    }
}

int LRUCache :: get(int key)
{
    std::unordered_map<int, node*>:: iterator it = cache.find(key);
    try
    {
        if(it!=cache.end()){
            dcll.moveback(it->second);
            return it->second->value;
        }
        else {
            throw "Key Not Present";   
        }
    }
    catch(const char* msg)
    {
        cerr<<msg<<endl;
         return -1 ;
    }
}


void LRUCache :: set(int key, int value) 
{
    if(has_key(key)){
        std::unordered_map<int, node*>::iterator it = cache.find(key);
        dcll.update(it->second,value);
        dcll.moveback(it->second);
    }
    else{
        if(capacity > dcll.getCount())    
            cache[key] = dcll.append(key, value);
        else {
            int oldKey = dcll.popKey(); //it also return -1 but we will not face this situation
            cache.erase(cache.find(oldKey));
            cache[key] = dcll.append(key, value);
        }
    }    
}

void LRUCache :: setSize(int size)
{
    int adjustDiff = size-dcll.getCount() ;
    while(adjustDiff++<0){     //delete adjustDiff entries using LRU..
        int key = dcll.popKey(); 
        cache.erase(cache.find(key));
    }
    capacity=size ;
}
        
    