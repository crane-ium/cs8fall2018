#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include <iostream>
#include <cassert>
#include "my_list.h"

/* Queue:
 * Control a linked list with a FIFO system */

using namespace std;

template <class T>
class Queue{
public:
    Queue():_head(nullptr), _tail(nullptr), length(0){}

    ~Queue();
    Queue(const Queue<T>& other);
    Queue<T>& operator =(const Queue<T>& rhs);

    void push(T item);
    T pop(); //Remove and return first item in queue
    T top(); //return first item in queue
    bool empty(); //return T if _head == nullptr
    friend ostream& operator << (ostream& outs, const Queue<T>& q){
        //iterate through the queue with a walker and output each node
        for(node<T>* walker = q._head; walker != nullptr; walker = walker->_next){
            outs << *walker;
        }
        outs << "|||" << endl;
        return outs;
    }
    size_t get_size() const {return length;} //returns length of queue
private:
    node<T>* _head;
    node<T>* _tail;
    size_t length;
};

template <class T>
Queue<T>::~Queue(){
    while(_head != nullptr){
        delete_head(_head);
    }
}

template <class T>
Queue<T>::Queue(const Queue<T>& q){
    this->_head = nullptr;
    this->_tail = nullptr;
    length = q.get_size();
    if(q._head != nullptr){
        _tail = insert_head(_head, q._head->_item);
        for(node<T>* walker = q._head->_next; walker != nullptr; walker = walker->_next){
            _tail = insert_after(_tail, walker->_item);
        }
    }
}

template <class T>
Queue<T>& Queue<T>::operator =(const Queue<T>& rhs){
    //copy-swap idiom copy assignment operator
    Queue<T> temp(rhs);
    swap(this->_head, temp._head);
    swap(this->_tail, temp._tail);
    swap(this->length, temp.length);
    return *this;
}

template <class T>
void Queue<T>::push(T item){
    //Insert at the end of the queue and update the tail
    if(this->_head == nullptr){
        this->_tail = insert_head(this->_head, item);
    }else
        this->_tail = insert_after(_tail, item);
    length++;
}

template <class T>
T Queue<T>::pop(){
    T item = delete_head(_head);
    length--;
    assert(length > 0); //guarantee length is not less than 0
    if(_head == nullptr)
        _tail = nullptr;
    return item;
}

template <class T>
T Queue<T>::top(){
    return this->_head->_item;
}

template <class T>
bool Queue<T>::empty(){
    return (this->_head == nullptr) ? true : false;
}


#endif //MY_QUEUE_H
