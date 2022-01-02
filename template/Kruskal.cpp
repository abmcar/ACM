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
class Kruskal
{
public:
    int find(int x)
    {
        if (x == father[x])
            return x;
        father[x] = find(father[x]);
        return father[x];
    }
    Kruskal(int _n) : n(_n)
    {
        father.resize(n + 1);
        ans = 0;
        for (int i = 1; i <= n; i++)
            father[i] = i;
    }
    void insert(T x, T y, T z)
    {
        edges.push_back({x, y, z});
    }
    void solve()
    {
        sort(edges.begin(), edges.end());
        for (int i = 0; i < (int)edges.size(); i++)
        {
            int f1 = find(edges[i].from);
            int f2 = find(edges[i].to);
            if (f1 == f2)
                continue;
            ans += edges[i].val;
            father[f1] = f2;
            cnt++;
        }
    }
    int get()
    {
        if (cnt != n - 1)
            return -1;
        return ans;
    }

private:
    struct Edge
    {
        T from, to, val;
        bool operator<(Edge b) const
        {
            return val < b.val;
        }
    };
    vector<Edge> edges;
    vector<int> father;
    int n, cnt;
    T ans;
};

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    Kruskal<int> kru(n);
    for (int i = 1; i <= m; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        kru.insert(t1, t2, t3);
    }
    kru.solve();
    if (kru.get() == -1)
        cout << "impossible" << endl;
    else
        cout << kru.get() << endl;
    return 0;
}