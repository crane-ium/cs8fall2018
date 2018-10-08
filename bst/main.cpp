#include <iostream>
#include <iomanip>
#include "node.h"
#include <random>
#include <time.h>
#include "bst.h"

using namespace std;

int main()
{
    bst<int> tree;
    srand(time(NULL));
    //generate random trees over and over
    for(int i = 0; i < 100; i++){
        int rng = rand() % 100;
        tree.insert(rng);
    }
    tree.print_inorder();

//    bst<int> tree;
//    int items[13] = {42, 13, 80, 9, 28, 77, 84, 54, 78, 89, 66, 5, 2};
//    for(int i = 0; i < sizeof(items)/sizeof(items[0])-0; i++){
//        cout << "Inserting " << items[i]<<endl;
//        tree.insert(items[i]);
//    }
////    tree.insert(66);
//////    tree.insert(30);
//////    tree.insert(29);
//////    tree.insert(31);
////    tree.insert(5);
////    tree.insert(30);
////    tree.insert(2);
//    tree.print();
//    tree.insert(10);
//    tree.print();
//    tree.insert(30);
//    tree.print();
//    bst<int> tree2;
//    tree.clear();
//    int itemss[5] = {10, 5, 15, 4, 3};
//    for(int i = 0; i < sizeof(itemss)/sizeof(itemss[0]); i++){
//        cout << "Inserting " << itemss[i]<<endl;
//        tree.insert(itemss[i]);
//    }
//    tree.print();
    cout << "Done\n";
}
