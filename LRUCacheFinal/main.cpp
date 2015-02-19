#include <iostream>
#include "DCLL.h"
#include "LRUCache.h"
#include <string>
using namespace std;
void ignore_line ( std::istream& in ) ;
template <class T1, class T2>
bool scanInput(LRUCache<T1, T2>& lrucache) ;

//typedef LRUCache<int, int> LRUCacheInt;

int main()
{
    cout<<"Enter \"lcmd\" to get the list of commands. All commands are case sensitive."<<endl;
   
    LRUCache<int, float> lrucache;
   
    while(scanInput(lrucache)) {}
    
    return 0;
}


void ignore_line ( std::istream& in )
{
  char ch;
  while ( in.get ( ch ) && ch != '\n' )  ;
}

template <class T1, class T2>
bool scanInput(LRUCache<T1, T2>& lrucache)
{
//mention type of two parameters

    T1 para1;
    T2 para2 ;
    std::string inpCmd;
    cin>>inpCmd ;
    if(!inpCmd.compare("CLEAR")){
        lrucache.clear();
    }
    else if(!inpCmd.compare("PRINT_CACHE")){
        lrucache.printList();
    }
    else if(!inpCmd.compare("END")){
        cout<<"Program is Exiting"<<endl;
        return false;
    }
    else if(!inpCmd.compare("SIZE")){
        int size;    
        cin>>size;    
        lrucache.setSize(size);
    }
    else if(!inpCmd.compare("GET")){
        cin>>para1;
        lrucache.get(para1);
    }
    
    else if(!inpCmd.compare("HAS_KEY")){
        cin>>para1;
        if(lrucache.has_key(para1))
            cout<<"Key Present"<<endl;
        else
            cout<<"Key not Present"<<endl;
    }
    else if(!inpCmd.compare("DELETE")){
        cin>>para1;
        lrucache.deleteEntry(para1);
    }
    else if(!inpCmd.compare("SET")){
        cin>>para1;
        cin>>para2;
        lrucache.set(para1, para2);
    }
    else if(!inpCmd.compare("lcmd")){
        cout<<" CLEAR \n PRINT_CACHE \n SIZE <size> \n GET <key> \n SET <key> <value> \n DELETE <key> \n"\
              " HAS_KEY <key> \n END"<<endl;
    }
    else{
        cout<<"Wrong Input. Enter lcmd to get List of commands"<<endl;
    }
    ignore_line(cin);
    return true ;
}

