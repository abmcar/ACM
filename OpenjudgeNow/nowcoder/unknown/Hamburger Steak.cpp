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
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll n, m, totT, nowPos;
ll t[Maxn], k;
ll nowT[Maxn];

struct Node
{
    int pos;
    ll val;
    bool const operator<(Node b) const
    {
        return val > b.val;
    }
} node[Maxn];

void init()
{
    ll maxn = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i], totT += t[i], maxn = max(maxn, t[i]);
        node[i].val = t[i];
        node[i].pos = i;
    }
    totT = max((totT+m-1) / m, maxn);
}

void work()
{
    nowPos = 1;
    // for (int i = 1; i <= m; i++)
    //     nowT[i] = totT;
    // sort(node + 1, node + 1 + n);
    // cout << t[1] << endl;
    // cout << totT << endl;
    for (int i = 1; i <= n; i++)
    {
        if (nowT[nowPos] + node[i].val <= totT)
        {
            cout << 1 << " " << nowPos << " " << nowT[nowPos] << " " << nowT[nowPos] + node[i].val << endl;
            nowT[nowPos] = nowT[nowPos] + node[i].val;
            if (nowT[nowPos] == totT)
                nowPos++;
        }
        else
        {
            ll part1 = totT - nowT[nowPos];
            ll part2 = node[i].val - part1;
            cout << 2 << " " << nowPos + 1 << " " << 0 << " " << part2 << " ";
            cout << nowPos << " " << nowT[nowPos] << " " << nowT[nowPos] + part1 << endl;
            nowPos++;
            nowT[nowPos] = part2;
        }
    }
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    init();
    work();
    return 0;
}