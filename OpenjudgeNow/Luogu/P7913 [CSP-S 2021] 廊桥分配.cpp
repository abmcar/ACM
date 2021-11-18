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
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int n, m1, m2;
int preAns1[Maxn], preAns2[Maxn];
int d1[Maxn], d2[Maxn];

void init()
{
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= m1; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        d1[t1]++;
        d1[t2+1]--;
    }
    for (int i = 1; i <= m2; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        d2[t1]++;
        d2[t2+1]--;
    }
    int now1 = 0;
    for (int i = 1; i <= Maxn; i++)
    {
        now1 += d1[i];
        preAns1[i] = now1;
    }
    int now2 = 0;
    for (int i = 1; i <= Maxn; i++)
    {
        now2 += d2[i];
        preAns2[i] = now2;
    }
    int ans = 0;
    for (int i = 1; i<= Maxn; i++)
        ans = max(ans, preAns1[i] + preAns2[i]);
    cout << ans << endl;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    init();
    return 0;
}