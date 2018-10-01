#include <iostream>
#include <iomanip>
#include "node.h"
#include <random>
#include <time.h>
#include "bst.h"

using namespace std;

int main()
{
//    tree_node<int>* base = NULL;
//    srand(time(NULL));
//    for(int i = 0; i < 1000; i++)
//        base->tree_insert(base, rand() % 1000);
////    base->tree_insert(base, 10);
////    base->tree_insert(base,5);
////    base->tree_insert(base,15);
////    base->tree_print_inorder(base, 0, cout);
////    cout << "NEXT\n";
//    cout << base << endl;
    bst<int> tree;
    tree.insert(4);
    tree.insert(2);
//    tree.insert(1);
//    tree.insert(3);
    tree.insert(6);
//    tree.insert(5);
    tree.insert(7);
    tree.print();
    tree.delete_node(6);
    cout << "Deleted " << endl;
    tree.print();
    cout << "Done\n";
}
