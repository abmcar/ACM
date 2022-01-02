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

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

template <typename T>
class Fenwick
{
public:
    vector<T> fenw;
    int n;
    Fenwick(int _n) : n(_n)
    {
        fenw.resize(n + 1);
    }
    void modifty(int x, int val)
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
};

int t, n;
struct Edge
{
    int from, to;
    int size;
    bool operator<(Edge b) const
    {
        return size < b.size;
    }
} edges[Maxn];

void work()
{
    cin >> n;
    unordered_map<int, int> M[Maxn];
    vector<int> r(n + 1);
    vector<int> tx, ty;
    vector<int> g[Maxn];
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        tx.push_back(t1);
        ty.push_back(t2);
        M[t1][t2] = ++cnt;
        edges[cnt].from = t1;
        edges[cnt].to = t2;
        edges[cnt].size = t2 - t1 + 1;
    }
    Fenwick<int> fen(n);
    sort(edges + 1, edges + 1 + cnt);
    for (int i = 1; i <= cnt; i++)
    {
        int l = edges[i].from;
        int r = edges[i].to;
        int nowAns = fen.get(r) - fen.get(l - 1);
        nowAns = edges[i].size * (l + r) / 2 - nowAns;
        fen.modifty(nowAns, nowAns);
        cout << l << " " << r << " " << nowAns << endl;
    }
    cout << endl;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}