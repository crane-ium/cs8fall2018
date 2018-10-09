#include <iostream>
#include <iomanip>
#include "node.h"
#include <random>
#include <time.h>
#include "bst.h"
#include <crtdbg.h>

using namespace std;

int main()
{
    int tmp;
    tmp = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
    tmp = (tmp & 0x0000FFFF) | _CRTDBG_CHECK_EVERY_16_DF;
    _CrtSetDbgFlag(tmp);

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
    cout << "Done\n";
}
