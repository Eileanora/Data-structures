#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define Num_of_Digits(n) ((int)log10(n) + 1)
#define sz(x) int(x.size())
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define fixed(n) fixed << setprecision(n)
#define ll long long
#define ull unsigned long long
constexpr ll linf = 1LL << 62;
constexpr int inf = 1 << 30;
constexpr int mod = 1e9 + 7;
#define PI acos(-1)
#define cin_2d(vec, n, m) for(int i = 0; i < n; i++) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define ceil(w, m) (((w) / (m)) + ((w) % (m) ? 1 : 0)
#define PI acos(-1)
#define multiOrderedSet tree <int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;
template <typename T = int> istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}
template <typename T = int> ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const T &x : v)
        out << x << " ";
    return out;
}

void set_file(string &file_name) {
    freopen((file_name + ".in").c_str(), "r", stdin);
    freopen((file_name + ".out").c_str(), "w", stdout);
}

// void btats()
// {
//     ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
//     #endif
//     //freopen("input.txt", "r", stdin);
//     //freopen("output.txt", "w", stdout);
// }

/*
    Linked list types:
    1. Singly linked list
    2. Doubly linked list
    3. Circular linked list
    4. Circular doubly linked list

    Complexity:
    1. Insertion: O(1)
    2. Deletion: O(1)
    3. Search: O(n)
    4. Access: O(n)

    Functions:
    1. push_front
    2. push_back
    3. pop_front
    4. pop_back
    5. insert
    6. erase
    7. reverse    
*/

class LinkedList
{
    struct Node
    {
        int data;
        Node *next;
        Node(int Data) : data(Data), next(nullptr) {}
    };

private:
    Node *head;
    Node *tail;
    int size;

    void empty(Node* curr)
    {
        if (curr != NULL)
            empty(curr->next);

        delete curr;
    }

public:
    LinkedList() {
        head = tail = nullptr;
        size = 0;
    }

    void insert_front(int data)
    {
		Node* newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
        else if (head == tail)
        {
            newNode->next = head;
            head = newNode;
            tail = newNode->next;
        }
		else
		{
			newNode->next = head;
			head = newNode;
		}
		size++;
    }

    void insert_back(int data)
    {
        Node* newnode = new Node(data);
        if (head == tail)
            head = tail = newnode;
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        size++;
    }

    void insert(int data, int pos)
    {
        if (pos < 0 || pos > size)
            return;
        if (pos == 0)
            insert_front(data);
        else if (pos == size)
            insert_back(data);
        else
        {
            Node* newnode = new Node(data);
            Node* cur = head;
            for (int i = 0; i < pos - 1; i++)
                cur = cur->next;
            Node* p = cur->next;

            cur->next = newnode;
            newnode->next = p;
        }
        size++;
    }

    void print()
    {
        Node* curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
        delete curr;
    }

    bool empty()
    {
        return head == NULL;
    }
    void build_list() {
        cout << "type -1 to stop\n";
        int x;
        while (cin >> x && x != -1)
            insert_back(x);
    }

    void pop_front(){
        if (head == NULL)
            return void (cout << "List is empty\n");
        
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node* p = head;
            Node* q = head->next;
            head = q;
            delete p;
        }
    }

    void pop_back(){
        if (head == NULL)
            return void (cout << "List is empty\n");
        
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node* curr = head;
            while (curr->next != tail)
                curr = curr->next;
                
            delete tail;
            tail = curr;
            tail->next = NULL;
        }
    }

    void erase(int pos){
        if (pos < 0 || pos >= size)
            return void (cout << "Invalid position\n");
        if (pos == 0)
            pop_front();
        else if (pos == size - 1)
            pop_back();
        else
        {
            Node* curr = head;
            for (int i = 0; i < pos - 1; i++)
                curr = curr->next;
            Node* p = curr->next;
            curr->next = p->next;
            delete p;
        }
    }

    void empty(Node* curr)
    {
        if (curr != NULL)
            empty(curr->next);

        delete curr;
    }
    ~LinkedList()
    {
        empty(head);
    }
};