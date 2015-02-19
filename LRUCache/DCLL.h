#ifndef DCLL_H
#define DCLL_H

template <class T1, class T2>
struct node{
    
    T1 key ;
    T2 value ;
    struct node * next;
    struct node * prev;
}  ;


template <class T1, class T2>
using node = struct node<T1, T2>;

template<class T1, class T2>
node<T1, T2>* createNode ( T2 );

template <class T1, class T2>
node<T1, T2>* createNode (T1 , T2 ) ;

template <class T1, class T2>
class DoubleCircularLinkedList{
    private :
        node<T1, T2> * head;
        int count;
    public :    
    
    DoubleCircularLinkedList(){
        node<T1, T2>* temp = new node<T1, T2>;
        temp->next=temp->prev=temp;
        head=temp;
        count=0;
    } 
    ~DoubleCircularLinkedList(){
        clear();
        delete head;
        count=0;
    }
    void clear();
    void remove(node<T1, T2>* );
    node<T1, T2>* append(T2 );
    node<T1, T2>* append(T1 , T2 );
    void moveback(node<T1, T2>* );
    T2 pop();
    T1 popKey();
    void printList();
    int getCount();
    void update(node<T1, T2>* , T2 );
    
    
};


#include "DCLL.cpp"
#endif