#ifndef DCLL_CPP
#define DCLL_CPP

#include <iostream>
using namespace std;
#include "DCLL.h"


template<class T1, class T2>
node<T1, T2>* createNode ( T2 value){
    node<T1, T2> * temp =  new node<T1, T2>;
    temp->value = value ;
    temp->next = NULL;
    temp->prev = NULL ;
    return temp;
}


template<class T1, class T2>
node<T1, T2>* createNode (T1 key, T2 value){
    node<T1, T2> * temp =  new node<T1, T2>;
    temp->value = value ;
    temp->next = NULL;
    temp->prev = NULL ;
    temp->key = key;
    return temp;
}



template<class T1, class T2>    
void DoubleCircularLinkedList<T1, T2> :: clear(){
    while(head->next!=head){
        remove(head->next);
    }
        
}

template<class T1, class T2>    
void DoubleCircularLinkedList<T1, T2> :: remove(node<T1, T2>* temp)
{
    temp->prev->next = temp->next ;
    temp->next->prev=temp->prev;
    count--;
    delete temp;
}

template<class T1, class T2>    
node<T1, T2>* DoubleCircularLinkedList<T1, T2> :: append(T2 value)
{
    node<T1, T2> * temp = createNode(value);
    head->prev->next = temp;
    temp->next=head;
    temp->prev=head->prev;
    head->prev=temp;
    count++;
    return temp;
}

template<class T1, class T2>    
node<T1, T2>* DoubleCircularLinkedList<T1, T2> :: append(T1 key, T2 value)
{
    node<T1, T2> * temp = createNode(key, value);
    head->prev->next = temp;
    temp->next=head;
    temp->prev=head->prev;
    head->prev=temp;
    count++;
    return temp;
}
    
template<class T1, class T2>
T2 DoubleCircularLinkedList<T1, T2> :: pop()
{
  T2 value ;        
  if(head->next!=head){
    value = head->next->value;
    remove(head->next);
  }    
  return value;
}

template<class T1, class T2>
T1 DoubleCircularLinkedList<T1, T2> :: popKey()
{
  T1 key ;
  if(head->next!=head){
    key = head->next->key;
    remove(head->next);
  }    
  return key;
}
    
template<class T1, class T2>
void DoubleCircularLinkedList<T1, T2> :: printList()
{
   //changeMe 
    node<T1, T2>* temp = head ;
    cout<<"   Elements - "<<count<<endl;
    bool flag=false;
    while(temp->next!=head)
    {
        if(flag)
            cout<<" <--> " ;
        temp=temp->next;
        cout<<temp->value;    
        flag=true;
    }
}



template<class T1, class T2>
void DoubleCircularLinkedList<T1, T2> :: moveback(node<T1, T2>* temp)
{
    if(head->prev!=temp){
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        
        head->prev->next=temp;
        temp->prev=head->prev;
        temp->next=head;
        head->prev=temp;
    }    
    
}

template<class T1, class T2>
int DoubleCircularLinkedList<T1, T2> :: getCount()
{
    return count;
}

template<class T1, class T2>
node<T1, T2> *  DoubleCircularLinkedList<T1, T2> ::getHead()
{
    return head;
}

template<class T1, class T2>
void DoubleCircularLinkedList<T1, T2> :: update(node<T1, T2>* temp, T2 value)
{
    temp->value = value;
}

#endif