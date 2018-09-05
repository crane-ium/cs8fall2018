#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include <iostream>
#include "my_list.h"

/* Queue:
 * Control a linked list with a FIFO system */

template <class T>
class Queue{
public:
    Queue():_head(nullptr){};

    ~Queue();
    Queue(const Queue<T>& other);
    Queue<T>& operator =(const Queue<T>& rhs);

    void push(T item);
    T pop();
    T top();
    bool empty();
    template <class U>
    friend ostream& operator << (ostream& outs, Queue<U> q){
        //iterate through the queue with a walker and output each node
        for(node<U>* walker = q._front; walker != nullptr; walker = walker->_next){
            outs << walker->_item;
        }
        outs << "|||" << endl;
        return outs;
    }
private:
    node<T>* _head;
};
#endif //MY_QUEUE_H

template <class T>
Queue<T>::~Queue(){
    while(_head != nullptr){
        delete_head(_head);
    }
}

//template <class T>
//Queue<T>::
