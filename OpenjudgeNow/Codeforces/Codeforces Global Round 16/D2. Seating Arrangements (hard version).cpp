#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <unordered_set>
// #include <ext/pb_ds/priority_queue.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
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

const int Maxn = 1e4 + 10;
const ll Mod = 1e9 + 7;

ll t, n, m;
struct Node
{
    ll oriPos;
    ll pos, val;
    ll nowr;
    bool const operator<(Node b) const
    {
        if (val == b.val)
            return oriPos < b.oriPos;
        return val < b.val;
    }
} node[233333];

Node nodes[333][333];

bool cm1(Node a, Node b)
{
        if (a.val == b.val)
            return a.oriPos > b.oriPos;
        return a.val < b.val;
}
bool cmp(Node a, Node b)
{
    return a.oriPos < b.oriPos;
}

void work()
{
    ll ans = 0;
    vector<int> nowV[333];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        cin >> node[(i-1)*m+j].val, node[(i-1)*m+j].oriPos = (i-1)*m+j;
    sort(node + 1, node + 1 + m*n);
    for (int i = 1; i <= n; i++)
        sort(node+1+(i-1)*m,node+1+m+(i-1)*m,cm1);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
        node[(i-1)*m+j].pos = j;
        nodes[i][j] = node[(i-1)*m+j];
    }
    for (int i = 1; i <= n; i++)
    {
        sort(nodes[i]+1,nodes[i]+1+m,cmp);
        for (int j = 1; j <= m; j++)
        {
            int nowPos = upper_bound(nowV[i].begin(),nowV[i].end(),nodes[i][j].pos-1) - nowV[i].begin();
            // cout << nowPos << " " << nodes[i][j].pos << "  ";
            ans += nowPos;
            nowV[i].insert(upper_bound(nowV[i].begin(),nowV[i].end(),nodes[i][j].pos), nodes[i][j].pos);
        }
        // cout << endl;
    }
    // cout << "    ";
    // for (int i : nowV[2])
    //     cout << i << " ";
    cout << ans << endl;
}

int main()
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
