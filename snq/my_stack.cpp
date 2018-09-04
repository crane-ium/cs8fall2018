#include "my_stack.h"
#include <assert.h>

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
    return rhs;
}

template <class T>
void Stack<T>::push(T item){
    //create a new node at the start (front) of the list for a FILO format
    insert_head(_top, item);
}

template <class T>
T Stack<T>::pop(){
    //Requires the user to check if it is empty first
    assert(!this->empty());
    return delete_head(_top);
}

template <class T>
T Stack<T>::top(){
    assert(!this->empty());
    return _top->_item;
}

template <class T>
bool Stack<T>::empty(){
    if(_top == nullptr)
        return true;
    else
        return false;
}
