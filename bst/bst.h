#ifndef BST_H
#define BST_H

#include <iostream>
#include "node.h"

using namespace std;

template <class T>
class bst{
public:
    bst():_head(NULL){}
    //BIG 3
    ~bst();
    bst(const bst& other);
    bst& operator =(const bst& rhs);
    //MOD MEMBER FUNCTIONS
    void insert(T item=T());
    void delete_node(T item);
    void clear(); //delete the whole tree
    //CONST MEMBER FUNCTIONS
    void print_inorder() const;
    void print() const;
private:
    tree_node<T>* _head;
    void delete_node(const tree_node<T> *root, T item=T()); //deletes a specific node and reorganizes tree appropriately

};

template<class T>
bst<T>::~bst(){
    _head->clear(_head);
}

template<class T>
bst<T>::bst(const bst& other){
    //Copy the other's tree
    if(this==&other)
        return;
    tree_copy(other._head, this->_head); //call friend function
}

template <class T>
bst<T>& bst<T>::operator =(const bst& rhs){
    if(this==&rhs)
        return *this;
    tree_copy(rhs._head, this->_head);
}

template<class T>
void bst<T>::insert(T item){
    _head->tree_insert(_head, item);
}

template<class T>
void bst<T>::print_inorder() const{
    _head->tree_print_inorder(_head, 0, cout);
}

template <class T>
void bst<T>::print() const{
    cout << "~~~~~~Tree in sideways view~~~~~~\n";
    _head->tree_print(_head, 0, cout);
    cout << "Done printing\n";
}

template<class T>
void bst<T>::delete_node(T item){
    _head->delete_node(_head, item);
}

template<class T>
void bst<T>::clear(){
    _head->clear(_head);
}

#endif // BST_H
