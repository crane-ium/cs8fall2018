#include "list.h"

template <class T>
node<T>* init_head(node<T>*& head){
    head = NULL;
    return head;
}

template <class T>
node<T>* insert_head(node<T>*& head, T item){
    head = new node<T>(item, head);
    return head;
}

template <class T>
node<T>* insert_after(node<T>*& n, T item){
    node<T>* new_n = new node<T>(item, n->_next);
    n->_next = new_n;
    return new_n;
}

template <class T>
T delete_head(node<T>*& head){
    if(head != nullptr){
        node<T>* temp = head;
        head = head->_next;
        T val = temp->_item;
        delete temp;
        return val;
    }
    return 0;
}
