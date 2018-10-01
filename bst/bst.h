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
    bst(const bst& copy);
    bst& operator =(const bst& rhs);
    //MOD MEMBER FUNCTIONS
    void insert(T item=T());
    void delete_node(T item=T());
    //CONST MEMBER FUNCTIONS
    void print_inorder() const;
    void print() const;
private:
    tree_node<T>* _head;
    void delete_node(const tree_node<T> *root, T item=T()); //deletes a specific node and reorganizes tree appropriately

};

template<class T>
bst<T>::~bst(){

}

template<class T>
bst<T>::bst(const bst& copy){

}

template <class T>
bst<T>& bst<T>::operator =(const bst& rhs){

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
    _head->tree_print(_head, 0, cout);
    tree_node<T>* temp = NULL;
    tree_node<T>* parent = NULL;
    cout << _head->find_node(6, _head, temp, parent) << endl;
    if(temp)
        cout << temp->_item << endl;
}

template<class T>
void bst<T>::delete_node(T item){
    _head->delete_node(_head, item);
}

#endif // BST_H
