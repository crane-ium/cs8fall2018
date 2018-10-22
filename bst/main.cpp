#include <iostream>
#include <iomanip>
#include "node.h"
#include <random>
#include <time.h>
#include "bst.h"
#include <crtdbg.h>
#include "record.h"

using namespace std;

void old_stuff();

int main()
{
    avl<record<string> > hash_test;
    hash_test.insert(record<string>(1, "test"));
    hash_test.insert(record<string>(5, "s test", "string"));
    for(int i = 0; i < 100; i++)
        hash_test.insert(record<string>(rand()%100, to_string(rand()%100)
                                        , (rand() % 2) ? ("") : ("string"+to_string(rand()%100))));
//    hash_test.erase(record<string>(5, "", "string"));
    hash_test.print_list();

    cout << "Done\n";
}

void old_stuff(){
//    int tmp;
//    tmp = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
//    tmp = (tmp & 0x0000FFFF) | _CRTDBG_CHECK_EVERY_16_DF;
//    _CrtSetDbgFlag(tmp);

    avl<int> tree;
    int items[13] = {42, 13, 80, 9, 28, 77, 84, 54, 78, 89, 66, 5, 2};
    for(int i = sizeof(items)/sizeof(items[0])-1; i >= 0; i--){
        //running it in reverse to show that it inserts properly as an AVL
        cout << "Inserting " << items[i]<<endl;
        tree.insert(items[i]);
    }
    tree.erase(13);
    tree.erase(50);
    tree.insert(23);
    tree.insert(18);
    tree.insert(17);
    tree.insert(15); //Test that the merge can handle duplicates
    tree.insert(10);
    tree.insert(25);
    cout << "Tree 1 in sideways view!\n";
    cout << tree << endl;
    avl<int> tree2;
    tree2.insert(15);
    tree2.insert(20);
    tree2.insert(25);
    tree2.print();

    cout << "\nConcatenate: \n";
    tree2 += tree;
    cout << "Final tree 2 (Tree 2 += Tree 1)\n";
    cout << tree2 << endl;

    cout << "Search for 25: ";
    tree_node<int>* found_25 = NULL;
    if(tree2.search(25, found_25))
        cout << "FOUND!\n";
    else cout << "NOT FOUND!\n";

    cout << "Search for 95: ";
    tree_node<int>* found_95 = NULL;
    if(tree2.search(95, found_95))
        cout << "FOUND!\n";
    else cout << "NOT FOUND!\n";

    tree2.clear();
    cout << "\nPrint cleared tree2\n";
    tree2.print();
    tree2 = tree;
    cout << "\nPrint tree2 that copied tree1!\n" << tree2 << endl;

}
