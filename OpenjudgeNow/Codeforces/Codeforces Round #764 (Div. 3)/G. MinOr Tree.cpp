#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;
map<int, int> M;

template <typename T>
class Kruskal
{
public:
    Kruskal(int _n) : n(_n)
    {
        father.resize(n + 1);
        ans = 0;
        cnt = 0;
        for (int i = 1; i <= n; i++)
            father[i] = i;
    }
    void insert(T x, T y, T z)
    {
        edges.push_back({x, y, z});
        M[z]++;
    }
    void solve()
    {
        for (int i = 0; i < (int)edges.size(); i++)
        {
            edges[i].oriVal = edges[i].val;
            edges[i].val = edges[i].val / M[edges[i].val];
        }
        sort(edges.begin(), edges.end());
        for (int i = 0; i < (int)edges.size(); i++)
        {
            int f1 = find(edges[i].from);
            int f2 = find(edges[i].to);
            if (f1 == f2)
                continue;
            ans = ans | edges[i].oriVal;
            father[f1] = f2;
            cnt++;
        }
    }
    int get()
    {
        cout << "cnt" << cnt << endl;
        if (cnt != n - 1)
            return -1;
        return ans;
    }

private:
    struct Edge
    {
        T from, to, val;
        T oriVal;
        bool operator<(Edge b) const
        {
            return val < b.val;
        }
    };
    int find(int x)
    {
        if (x == father[x])
            return x;
        father[x] = find(father[x]);
        return father[x];
    }
    vector<Edge> edges;
    vector<int> father;
    int n, cnt;
    T ans;
};

void work()
{
    cin >> n >> m;
    Kruskal<int> kru(n);
    for (int i = 1; i <= m; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        kru.insert(t1, t2, t3);
    }
    kru.solve();
    cout << kru.get() << endl;
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