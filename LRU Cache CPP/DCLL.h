#ifndef DCLL_H
#define DCLL_H

typedef struct node{
    
    int key ;
    int value ;
    struct node * next;
    struct node * prev;
} node ;

node* createNode (int ) ;
node* createNode (int , int ) ;

class DoubleCircularLinkedList{
    private :
        node * head;
        int count;
    public :    
    DoubleCircularLinkedList() ;
    ~DoubleCircularLinkedList();
    void clear();
    void remove(node* );
    node* append(int );
    node* append(int , int );
    void moveback(node* );
    int pop();
    int popKey();
    void printList();
    int getCount();
    void update(node* , int );
    
    
};

#endif