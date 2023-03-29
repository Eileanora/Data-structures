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

// -----------------------------------------------------------------------------------------------------------
struct DSU
{
    vector <int> parent, size;

    DSU(int n)
    {
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int leader(int x)
    {
        if(parent[x] == x)
            return x;
        return parent[x] = leader(parent[x]);
    }

    void merge(int x, int y)
    {
        x = leader(x);
        y = leader(y);

        if(x == y)
            return;

        if(size[x] < size[y])
            swap(x, y);

        parent[y] = x;
        size[x] += size[y];
    }

    int GetSize(int x)
    {
        int x = leader(x);
        return size[x];
    }
    bool is_cyclic(int u , int v)
    {
        int x = leader(u);
        int y = leader(v);
        if(x == y)
        {
            //parent[v] = v;
            return true;
        }
        merge(x , y);
        return false;
     
    }
    
};
