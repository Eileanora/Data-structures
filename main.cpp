#include <iostream>
#include "queue.h"
using namespace std;

void btats()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("/home/yasmeen/Documents/vs-folders/solving/misc/input.txt", "r", stdin),
        freopen("/home/yasmeen/Documents/vs-folders/solving/misc/output.txt", "w", stdout);
    #endif
}

int main()
{
    btats();
    queue <int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.top() << " ";
    q.pop();
    cout << q.top() << " ";
    q.pop();
    cout << q.top() << " ";


}