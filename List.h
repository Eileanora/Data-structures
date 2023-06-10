// dynamic list

#include <iostream>
using namespace std; 

template <class T>
class List
{
private: 
    int maxSize;
    int size;
    T* list;

public:
    List(int maxsz)
    {
        maxSize = maxsz;
        size = 0;
        list = new T[maxSize];
    }

    bool empty() {
        return size == 0;
    }
    bool full() {
        return size == maxSize;
    }

    void insert(T data)
    {
        if (full())
        {
            cout << "List is full" << endl;
            return;
        }
        list[size] = data;
        size++;
    }

    void insert_pos(int pos , T data)
    {
        if (full())
            return void (cout << "List is full" << endl);
        
        if (pos < 0 || pos > size)
            return void (cout << "Invalid position" << endl);
        
        // shift elements to the right
        for (int i = size - 1; i > pos; i--)
            list[i] = list[i - 1];

        list[pos] = data;
        size++;
    }

    void pop_back()
    {
        if (empty())
            return void (cout << "List is empty" << endl);
        
        size--;
    }

    void remove_pos(int pos)
    {
        if (empty())
            return void (cout << "List is empty" << endl);
        
        if (pos < 0 || pos > size)
            return void (cout << "Invalid position" << endl);
        
        // shift elements to the left
        for (int i = pos; i < size - 1; i++)
            list[i] = list[i + 1];
        
        size--;
    }
    
    int search(T data)
    {
        for (int i = 0; i < size; i++)
        {
            if (list[i] == data)
                return i;
        }
        return -1;
    }

    int get_size() {
        return size;
    }
    int get_maxSize() {
        return maxSize;
    }

    void increase_maxSize(int newMaxSize)
    {
        if (newMaxSize < maxSize)
            return void (cout << "Invalid newMaxSize" << endl);
        
        T* temp = new T[newMaxSize];
        for (int i = 0; i < size; i++)
            temp[i] = list[i];
        
        delete[] list;
        list = temp;
        maxSize = newMaxSize;
    }

    
    void print() {
        for (int i = 0; i < size; i++)
        {
            cout << list[i] << " ";
        }
        cout << endl;
    }

    ~List()
    {
        delete[] list;
    }
};