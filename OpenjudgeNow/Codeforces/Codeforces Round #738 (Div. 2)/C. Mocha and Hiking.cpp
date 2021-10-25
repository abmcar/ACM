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

int road[Maxn];
int n, t;

void work()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> road[i];
    if (road[n] == 0)
    {
        for (int i = 1; i <= n + 1; i++)
            cout << i << " ";
        cout << endl;
        return;
    }
    if (road[1] == 1)
    {
        cout << n+1 << " ";
        for (int i = 1; i <= n; i++)
            cout << i << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i < n; i++)
        if (road[i] == 0 && road[i + 1] == 1)
        {
            for (int j = 1; j <= i; j++)
                cout << j << " ";
            cout << n + 1 << " ";
            for (int j = i + 1; j <= n; j++)
                cout << j << " ";
            cout << endl;
            return;
        }
    cout << -1 << endl;
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