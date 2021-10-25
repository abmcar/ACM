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
using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll xors[Maxn];
ll a, b;
int t;

int len(ll x)
{
    int i = 0;
    while ((1<<i) <= x)
        i++;
    return i;
}

void work()
{
    cin >> a >> b;
    if (xors[a-1] == b)
    {
        cout << a << endl;
        return;
    }
    if (xors[a] == b)
        cout << a+2 << endl;
    else
        cout << a+1 << endl;
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    for (int i = 1; i <= 3e5; i++)
        xors[i] = xors[i-1] xor i;
    cin >> t;
    while (t--)
        work();
    return 0;
}