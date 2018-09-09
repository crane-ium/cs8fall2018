#ifndef MY_STACK_H
#define MY_STACK_H

/*Stack:
 * Using a linked list, control the linked list in a FILO system */

#include <iostream>
#include "my_list.h"
#include <assert.h>
#include <exception>

using namespace std;

template <class T>
class Stack{
public:
    Stack();

    //Big 3
    ~Stack();
    Stack(const Stack<T>& other);
    Stack<T>& operator =(const Stack<T>& rhs);

    void push(T item);
    T pop(); //Pops the head (last in) and returns item
    T top(); //returns item of head
    bool empty();
    friend ostream& operator << (ostream& outs, const Stack<T>& s){
        //iterate through the LL and cout each node
        for(node<T>* walker = s._top; walker != nullptr; walker = walker->_next){
            outs << *walker;
        }
        outs << "|||" << endl; //put the null at the end of the list
        return outs;
    }
private:
    node<T>* _top;
};

template <class T>
Stack<T>::Stack():_top(nullptr){}

//-----Big 3------
template <class T>
Stack<T>::~Stack(){
    //destruct all nodes individually
    while(_top != nullptr){
        delete_head(_top);
    }
}

template <class T>
Stack<T>::Stack(const Stack<T>& other){
    this->_top = nullptr;
    if(other._top != nullptr){
        node<T>* tail;
        tail = insert_head(this->_top, other._top->_item);
        if(other._top->_next != nullptr)
            //walk through the remaining nodes and create a new node in insert_after
            for(node<T>* walker = other._top->_next; walker != nullptr; walker = walker->_next)
                tail = insert_after(tail, walker->_item);
    }
}

template <class T>
Stack<T>& Stack<T>::operator =(const Stack<T>& rhs){
    //using a copy-swap idiom copy assignment operator
    Stack<T> temp(rhs);
    swap(_top, temp._top);
    return *this;
}

template <class T>
void Stack<T>::push(T item){
    //create a new node at the start (front) of the list for a FILO format
    insert_head(_top, item);
}

//assert macro
#define MY_ASSERT(val,err) if (!val) throw err

//Pops head (last one in) and returns the item
template <class T>
T Stack<T>::pop(){
    //Requires the user to check if it is empty first
    //These assert macros are redundant after the throw exception built into the LL
    //But they're kinda cool so i'll leave it for now
    MY_ASSERT(!this->empty(), ExceptionEmptyList());
    return delete_head(_top);
}

template <class T>
T Stack<T>::top(){
    MY_ASSERT(!this->empty(), ExceptionEmptyList());
    return _top->_item;
}

template <class T>
bool Stack<T>::empty(){
    if(_top == nullptr)
        return true;
    else
        return false;
}

#endif //MY_STACK_H
