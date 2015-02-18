#include <iostream>
#include "DCLL.h"
#include "LRUCache.h"

using namespace std;


int main()
{
   cout << "Hello World" << endl; 
   DoubleCircularLinkedList dcll;
   dcll.append(10);
   dcll.append(11);
   dcll.append(13);
   dcll.printList();
   dcll.pop();
   dcll.printList();
   dcll.append(23);
   dcll.printList();
   dcll.clear();
   dcll.printList();
   
   LRUCache lrucache(3) ;
   
   lrucache.set(2,100);
   lrucache.set(3,140);
   lrucache.printCache();
   
   return 0;
}

