#include <iostream>
#include "my_stack.h"

using namespace std;

int main(){
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s;
    Stack<int> s2;
    Stack<int> s3(s);
    cout << s3;
    s3.~Stack();
    cout << s3;
    cout << s.pop() << endl;
    for(int i = 0; i < 5; i++)
        cout << s.pop();
}
