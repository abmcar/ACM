// #include <iostream>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <iomanip>
// #include <cmath>
// #include <ctime>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <climits>
// #include <ext/pb_ds/priority_queue.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#include <bits/extc++.h>
#include <bits/stdc++.h>
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

int n, ans;
struct Node
{
    int l, r;
    bool const operator<(Node b) const
    {
        return l < b.l;
    }
} node[Maxn];

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    ans = n;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        node[i].l = l;
        node[i].r = r;
    }
    sort(node + 1, node + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        // cout << i << endl;
        int nowPos = i + 1;
        while (nowPos <= n)
        {
            if (node[nowPos].l <= node[i].r)
            {
            // cout << node[nowPos].l << " " << node[i].r << endl;
                // cout << nowPos << endl;
                node[i].r = max(node[i].r, node[nowPos].r); 
                ans--;
                nowPos++;
                // cout << nowPos << endl;
            }else
            {
                // i = nowPos - 1;
                // cout << i << endl;
                break;
            }
        }
        i = nowPos - 1; 
    }
    cout << ans << endl;
    return 0;
}