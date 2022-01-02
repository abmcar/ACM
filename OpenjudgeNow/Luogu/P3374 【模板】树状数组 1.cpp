#include "bits/stdc++.h"

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

template <typename T>
class Fenwick
{
public:
    vector<T> fenw;
    int n;
    Fenwick(int _n) : n(_n)
    {
        fenw.resize(n);
    }

    void modify(int x, T val)
    {
        while (x < n)
        {
            fenw[x] += val;
            // x += lowbit(x);
            x |= (x + 1);
        }
    }

    T get(int x)
    {
        T nowAns{};
        while (x >= 0)
        {
            nowAns += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return nowAns;
    }
};

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    Fenwick<int> fen(10);
    fen.modify(1,1);
    fen.modify(2,2);
    cout << fen.get(2) << endl;
    return 0;
}