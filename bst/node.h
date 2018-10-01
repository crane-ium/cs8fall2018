#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include <cassert>

using namespace std;

template <class T>
struct tree_node{
    T _item;
    tree_node<T>* _left;
    tree_node<T>* _right;
    unsigned int _height;
    //CTOR
    tree_node(T item=T(), tree_node* left=NULL, tree_node* right=NULL):
        _item(item), _left(left), _right(right), _height(0){}
    //MOD MEMBER FUNCTIONS
    void tree_insert(tree_node<T>* &root, const T &item);
    int height(); //gets height of the current node by propogating thru the children also
    void update_height(); //updates the height of the chosen node
    void delete_node(tree_node<T> *&root, T item=T()); //deletes a specific node based on item
    tree_node<T>* get_largest_node(tree_node<T>* root, tree_node<T> *&parent);
    bool find_node(T item, tree_node<T> *&root, tree_node<T> **&node);
    void clear(tree_node<T>* &root); //deletes the root and all children
    //CONST MEMBER FUNCS
    void tree_print_inorder(tree_node<T>* root, int level, ostream& outs=cout) const;
    void tree_print(tree_node<T>* root, int level, ostream& outs=cout) const;
    int balance_factor() const;
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
        this->_height = (_right->height() > _left->height())?
                (_right->height() + 1):(_left->height() + 1);
    else if(_right)
        _height = _right->height() + 1;
    else if(_left)
        _height = _left->height() + 1;
    else
        _height = 0;
    return _height;
}

template<class T>
void tree_node<T>::update_height(){
    this->_height = height();
}

template <class T>
void tree_node<T>::delete_node(tree_node<T>* &root, T item){
    tree_node<T>** node = NULL;
    if(!find_node(item, root, node))
        return;
    else{
        tree_node<T>* largest = NULL;
        tree_node<T>* parent = NULL;
        largest = get_largest_node((*node)->_left, parent);
        if(largest){
            //Then there is a node to the left
            if(parent){
                //Then there was a parent of the left node that is not this
                parent->_right = NULL;
            }else
                (*node)->_left = NULL; //else the largest node was the left child
            (*node)->_item = largest->_item;
            delete largest;
        }else{
            if((*node)->_right){
                //There was no largest, so instead combine the right tree
                (*node)->_item = (*node)->_right->_item;
                (*node)->_right = (*node)->_right->_right;
            }else{
                //There's no node to the right so just set node to null and delete
                tree_node<T>* temp = (*node);
                (*node) = NULL;
                delete temp;
            }
        }
        root->update_height();
    }
}

template<class T>
bool tree_node<T>::find_node(T item, tree_node<T>* &root, tree_node<T>** &node){
    if(!root)
        return false;
    if(root->_item == item){
        node = &root; //returns the node back to the base call
        return true;
    }
    if(root->_item < item){
        return find_node(item, root->_right, node);
    }else{
        return find_node(item, root->_left, node);
    }
}

template<class T>
tree_node<T>* tree_node<T>::get_largest_node(tree_node<T> *root, tree_node<T>* &parent){
    if(root == NULL)
        return NULL; //this would be bad, btw
    if(root->_right != NULL){
        parent = root;
        return get_largest_node(root->_right, parent);
    }else{
        return root;
    }
}

template <class T>
void tree_node<T>::clear(tree_node<T> *&root){
    if(!root)
        return;
    clear(root->_left);
    clear(root->_right);
    tree_node<T>** temp = &root;
    delete root;
    (*temp) = NULL;
}

template<class T>
int tree_node<T>::balance_factor() const{
    //Checks whether to use the _height or -1 if _left or _right DNE
    return ((_left)?(_left->_height):(-1)) - ((_right)?(_right->_height):(-1));
}

#endif // TREENODE_H
