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
    Fenwick(int _n) : n(_n)
    {
        fenw.resize(n + 1);
    }
    void modifty(int x, T val)
    {
        while (x <= n)
        {
            fenw[x] += val;
            x |= (x + 1);
        }
    }

    T get(int x)
    {
        T cnt{};
        while (x >= 0)
        {
            cnt += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return cnt;
    }

private:
    vector<T> fenw;
    int n;
};

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    Fenwick<int> fen1(10);
    fen1.modifty(1, 1);
    cout << fen1.get(4) << endl;
    return 0;
}