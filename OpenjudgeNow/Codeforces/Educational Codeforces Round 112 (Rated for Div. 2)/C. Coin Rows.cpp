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
#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

int t, m, pos, maxn;
int a1[Maxn], a2[Maxn];
int preA1[Maxn], preA2[Maxn];
void work()
{
    maxn = 1e9;
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> a1[i], preA1[i] = preA1[i-1] + a1[i];
    for (int i = 1; i <= m; i++)
        cin >> a2[i], preA2[i] = preA2[i-1] + a2[i];
    for (int i = 1; i <= m; i++)
    {
        int nowAns = max(preA1[m] - preA1[i], preA2[i-1]);
        maxn = min(maxn, nowAns);
    }
    for (int i = 1; i <= m; i++)
        a1[i] = a2[i] = preA1[i] = preA2[i] = 0;
    cout << maxn << endl;
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