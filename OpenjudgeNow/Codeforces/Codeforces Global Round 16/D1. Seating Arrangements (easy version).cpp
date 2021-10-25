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
    bool const operator<(Node b) const
    {
        if (val == b.val)
            return oriPos > b.oriPos;
        return val < b.val;
    }
} node[2333];

bool cmp(Node a, Node b)
{
    return a.oriPos < b.oriPos;
}

void work()
{
    ll ans = 0;
    vector<int> nowV;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> node[i].val, node[i].oriPos = i;
    sort(node + 1, node + 1 + m);
    for (int i = 1; i <= m; i++)
        node[i].pos = i;
    sort(node + 1, node + 1 + m, cmp);
    for (int i = 1; i <= m; i++)
    {
        int nowPos = upper_bound(nowV.begin(),nowV.end(),node[i].pos-1) - nowV.begin();
        // cout << nowPos << " ";
        ans += nowPos;
        nowV.insert(upper_bound(nowV.begin(),nowV.end(),node[i].pos), node[i].pos);
    }
    // cout << "    ";
    // for (int i : nowV)
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