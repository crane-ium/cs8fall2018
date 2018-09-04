#include "list.h"
#include "my_queue.cpp"

template <class T>
class Queue
{
public:
    Queue();

    ~Queue();
    Queue(const Queue<T>& other);
    Queue<T>& operator =(const Queue<T>& rhs);

    void push(T item);
    T pop();
    T top();
    bool empty();
    template <class U>
    friend ostream& operator << (ostream& outs, Queue<U> q){
        //iterate through the queue with a walker and output each node
        for(node<U>* walker = q._front; walker != nullptr; walker = walker->_next){
            outs << walker->_item;
        }
        outs << "NULL" << endl;
        return outs;
    }
private:
    node<T>* _front;
};
