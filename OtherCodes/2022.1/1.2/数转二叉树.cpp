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

int n;
struct Node
{
    char data;
    int parent;
    int lc;
    int rc;
} nodes[Maxn];

void solve1(int nowNode)
{
    if (nowNode <= 0)
        return;
    cout << nodes[nowNode].data;
    solve1(nodes[nowNode].lc);
    solve1(nodes[nowNode].rc);
}

void solve2(int nowNode)
{
    if (nowNode <= 0)
        return;
    solve2(nodes[nowNode].lc);
    solve2(nodes[nowNode].rc);
    cout << nodes[nowNode].data;
}

void work()
{
    for (int i = 1; i <= n; i++)
        nodes[i].parent = 0;
    for (int i = 1; i <= n; i++)
    {
        int t1, t2;
        cin >> nodes[i].data >> t1;
        nodes[i].lc = t1;
        while (t1)
        {
            nodes[t1].parent = i;
            cin >> t2;
            nodes[t1].rc = t2;
            t1 = t2;
        }
    }
}

void output()
{
    int strNode = 0;
    for (int i = 1; i <= n; i++)
    {
        if (nodes[i].parent == 0)
        {
            strNode = i;
            break;
        }
    }
    nodes[strNode].rc = 0;
    solve1(strNode);
    cout << endl;
    solve2(strNode);
    cout << endl;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    while (cin >> n)
    {
        work();
        output();
    }
    return 0;
}