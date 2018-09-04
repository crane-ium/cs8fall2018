#include "list.h"
#include "my_stack.cpp"

template <class T>
class Stack{
public:
    Stack():_top(nullptr){}

    ~Stack();
    Stack(const Stack<T>& other);
    Stack<T>& operator =(const Stack<T>& rhs);

    void push(T item);
    T pop();
    T top();
    bool empty();
    template <class U>
    friend ostream& operator << (ostream& outs, const Stack<U>& s){
        //iterate through the LL and cout each node
        for(node<U>* walker = s._top; walker != nullptr; walker = walker->_next){
            outs << *walker;
        }
        outs << "NULL" << endl; //put the null at the end of the list
        return outs;
    }
private:
    node<T>* _top;
};
