#include <cassert>
using namespace std;
template <class T>

class queue
{
private:
    int front, rear, size;
    T* arr;
public:
    queue(int sz) {
        front = -1;
        rear = -1;
        size = sz;
        arr = new T[size];
    }
    bool is_empty() {
        return front == -1;
    }

    bool is_full() {
        return front == (rear + 1) % size;
    }
    void push(T data) {
        assert(!is_full());
        if (front == -1)
            front = 0;
        rear = (rear + 1) % size;
        arr[rear] = data;
    }
    void pop() {
        assert(!is_empty());
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
    }
    T Front() {
        assert(!is_empty());
        return arr[front];
    }
    ~queue() {
        delete[] arr;
    }

};