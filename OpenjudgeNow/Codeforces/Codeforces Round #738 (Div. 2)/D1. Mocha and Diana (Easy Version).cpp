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

int father1[Maxn], father2[Maxn];
int n, m1, m2, ans;
vector<int> ans1, ans2;

int find1(int son)
{
    if (father1[son] == son)
        return son;
    father1[son] = find1(father1[son]);
    return father1[son];
}

int find2(int son)
{
    if (father2[son] == son)
        return son;
    father2[son] = find2(father2[son]);
    return father2[son];
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= n; i++)
        father1[i] = father2[i] = i;
    for (int i = 1; i <= m1; i++)
    {
        int t1,t2;
        cin >> t1 >> t2;
        int f1 = find1(t1);
        int f2 = find1(t2);
        father1[f1] = f2;
    }
    for (int i = 1; i <= m2; i++)
    {
        int t1,t2;
        cin >> t1 >> t2;
        int f1 = find2(t1);
        int f2 = find2(t2);
        father2[f1] = f2;
    }
    for (int i = 1; i <= n; i++)
    for (int j = i+1; j <= n; j++)
    {
        int fa1 = find1(i);
        int fb1 = find1(j);
        int fa2 = find2(i);
        int fb2 = find2(j);
        if (fa1 == fb1 || fa2 == fb2)
            continue;
        // cout <<i << " " <<j << " " << fa1 << " " << fb1 << " " << fa2 << " " << fb2 << endl;
        ans++;
        ans1.push_back(i);
        ans2.push_back(j);
        father1[fa1] = fb1;
        father2[fa2] = fb2;
    }
    cout << ans << endl;
    for (int i = 0; i < ans; i++)
        cout << ans1[i] << " " << ans2[i] << endl; 
    return 0;
}