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

int n, m, q, nowAns;
int w1[Maxn], w2[Maxn];

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        w1[t1]++;
        w1[t2]++;
        w2[max(t1, t2)]++;
    }
    for (int i = 1; i <= n; i++)
        if (w1[i] == w2[i])
            nowAns++;
    cin >> q;
    while (q--)
    {
        int opt, t1, t2;
        cin >> opt;
        if (opt == 1)
        {
            cin >> t1 >> t2;
            if (w1[t1] == w2[t1])
                nowAns--;
            if (w1[t2] == w2[t2])
                nowAns--;
            w1[t1]++;
            w1[t2]++;
            w2[max(t1, t2)]++;
            if (w1[t1] == w2[t1])
                nowAns++;
            if (w1[t2] == w2[t2])
                nowAns++;
        }
        else if (opt == 2)
        {
            cin >> t1 >> t2;
            if (w1[t1] == w2[t1])
                nowAns--;
            if (w1[t2] == w2[t2])
                nowAns--;
            w1[t1]--;
            w1[t2]--;
            w2[max(t1, t2)]--;
            if (w1[t1] == w2[t1])
                nowAns++;
            if (w1[t2] == w2[t2])
                nowAns++;
        }
        else if (opt == 3)
            cout << nowAns << endl;
    }
    return 0;
}