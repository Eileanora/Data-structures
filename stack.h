#include <iostream>
using namespace std;

template <class T>
class stack
{
    struct node
    {
        T data;
        node* prev;
        node (T Data)
        {
            this->data = Data;
            this->prev = nullptr;
        }
    };
    node* topp;
    node* bottom;
public:
    stack() {
        topp = nullptr;
        bottom = nullptr;
    }
    bool is_empty() {
        return topp == nullptr;
    }
    void push(T data) {
        node* newnode = new node(data);
        newnode->prev = topp;
        topp = newnode;
    }
    void pop() {
        if (is_empty()) {
            cout << "stack is empty" << endl;
            return;
        }
        node* temp = topp;
        topp = topp->prev;
        delete temp;
    }
    T top() {
        if (is_empty()) {
            cout << "stack is empty" << endl;
            return 0;
        }
        return topp->data;
    }
    ~stack() {
        while (!is_empty()) {
            pop();
        }
    }
};