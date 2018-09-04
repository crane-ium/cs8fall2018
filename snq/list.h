#include <iostream>
#include "list.cpp"

using namespace std;

template <class T>
struct node{
    T _item;
    node<T>* _next;
    node(const T& item = T(), node<T>* next = nullptr):_item(item), _next(next){}
    friend ostream& operator << (ostream& outs, const node<T>& print_node){
        outs << "[" << print_node._item << "]->";
        return outs;
    }
};

template <class T>
node<T>* init_head(node<T>*& head);

template <class T>
node<T>* insert_head(node<T>*& head, T item);

template <class T>
node<T>* insert_after(node<T>*& n, T item);

template <class T>
T delete_head(node<T>*& head);
