#include <bits/stdc++.h>
#include "DoublyLinkedList.h"

using namespace std;

void btats()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("/home/yasmeen/Documents/solving/misc/input.txt", "r", stdin),
        freopen("/home/yasmeen/Documents/solving/misc/output.txt", "w", stdout);
    #endif
}

int main()
{
    btats();
    DoublyLinkedList list;
    list.insert_front(1);
    list.insert_front(2);
    list.print();
    list.pop_front();
    list.print();
    list.insert_back(3);
    list.pop_back();
    list.print();
}