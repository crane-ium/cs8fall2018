#ifndef BST_H
#define BST_H

#include <iostream>
#include <cassert>

using namespace std;

template <class T>
struct tree_node{
    T _item;
    tree_node<T>* _left;
    tree_node<T>* _right;
    unsigned int _height;
    int balance_factor(){
        return 0;
    }

    tree_node(T item=T(), tree_node* left=NULL, tree_node* right=NULL):
        _item(item), _left(left), _right(right), _height(0){}
    //MOD MEMBER FUNCTIONS
    void tree_insert(tree_node<T>* &root, const T &item);
    int height();
    void update_height();
    //CONST MEMBER FUNCS
    void tree_print_inorder(tree_node<T>* root, int level, ostream& outs=cout) const;
    void tree_print(tree_node<T>* root, int level, ostream& outs=cout) const;
    //FRIEND FUNCS
    friend ostream& operator <<(ostream& outs, tree_node<T>*& node){
        node->tree_print(node, 0, outs);
        return outs;
    }
};

template<class T>
void tree_node<T>::tree_insert(tree_node<T>* &root, const T& item){
    //NOTE: changed const T& item to T item

    //just starting with a basic in-order cout
    if(!root){
        root = new tree_node(item);
    }else if(item < root->_item){
        tree_insert(root->_left, item);
    }else if(item > root->_item){
        tree_insert(root->_right, item);
    }
    if(item == root->_item)
        return;
    assert(item != root->_item); //quick check
    root->update_height();
}

template<class T>
void tree_node<T>::tree_print_inorder(tree_node<T> *root, int level, ostream &outs) const{
    if(!root)
        return;
    tree_print_inorder(root->_left, level+1, outs);
    outs << setw(level) << "";
    outs << root->_item << ": " << root->_height << endl;
    tree_print_inorder(root->_right, level+1, outs);
}

template<class T>
void tree_node<T>::tree_print(tree_node<T> *root, int level, ostream &outs) const{
    if(!root)
        return;
    tree_print(root->_right, level+1, outs);
    for(int i = 0; i < level; i++)
        outs << "---- ";
    outs << root->_item << ": " << root->_height << endl;
    tree_print(root->_left, level+1, outs);
}

template<class T>
int tree_node<T>::height(){
    //set the height of the node
    if(_right && _left)
        this->_height = (_right->_height > _left->_height)?(_right->_height + 1):(_left->_height + 1);
    else if(_right)
        _height = _right->_height + 1;
    else if(_left)
        _height = _left->_height + 1;
    else
        _height = 0;
    return _height;
}

template<class T>
void tree_node<T>::update_height(){
    this->_height = height();
}

#endif // BST_H
