using namespace std;
template <class T>
class queue
{
private:
    struct node
    {
        T data;
        node* next;
        node (T Data) {
            this->data = Data;
            this->next = nullptr;
        }
    };
    node* front;
    node* rear;
public:
    queue() {
        front = nullptr;
        rear = nullptr;
    }
    void push(T data) {
        node *newnode = new node(data);
        if (front == nullptr) {
            front = rear = newnode;
            return;
        }
        else {
            rear->next = newnode;
            rear = newnode;
        }
    }
    void pop() {
        if (front == nullptr) {
            throw "queue is empty";
        }
        else {
            node *temp = front;
            front = front->next;
            delete temp;
        }
    }
    T top() {
        if (front == nullptr) {
            throw "queue is empty";
        }
        else {
            return front->data;
        }
    }
    bool is_empty() {
        return front == nullptr;
    }
    ~queue() {
        while (!is_empty()) {
            pop();
        }
    }
};