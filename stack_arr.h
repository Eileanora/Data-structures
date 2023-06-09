// implement stack using array
#include <iostream>
#include <cassert>
using namespace std;

template <class T>
class stack
{
    T* arr;
    int size;
    int stktop;
public:
    stack(int Size) {
        size = Size;
        arr = new T[size];
        stktop = 0;
    }
    bool is_empty() {
        return stktop == 0;
    }
    bool is_full() {
        return stktop == size;
    }
    void push(T data) {
        assert(!is_full());
        arr[stktop++] = data;
    }
    void pop() {
        assert(!is_empty());
        stktop--;
    }
    T top() {
        assert(!is_empty());
        return arr[stktop - 1];
    }
    ~stack() {
        delete[] arr;
    }

};