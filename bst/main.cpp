#include <iostream>
#include <iomanip>
#include "bst.h"
#include <random>
#include <time.h>

using namespace std;

int main()
{
    tree_node<int>* base = NULL;
    srand(time(NULL));
    for(int i = 0; i < 1000; i++)
        base->tree_insert(base, rand() % 1000);
//    base->tree_insert(base, 10);
//    base->tree_insert(base,5);
//    base->tree_insert(base,15);
//    base->tree_print_inorder(base, 0, cout);
//    cout << "NEXT\n";
    cout << base << endl;
}
