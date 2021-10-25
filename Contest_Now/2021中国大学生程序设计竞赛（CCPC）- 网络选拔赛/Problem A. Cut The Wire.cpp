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

int d[Maxn], f[Maxn];

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    for (int i = 1; i <= 300; i++)
    {
        // d[i]++, d[i*2+1]--;
        if (i % 2)
            d[i]++, d[i*3+1]--;
        else
            d[i/2]++,d[i]--;
    }
    int now = 0;
    for (int i = 1; i < 100; i++)
    {
        now += d[i];
        f[i] = now;
        int temp = (i-1) / 2  + (((i-1))/3) + 2;
        cout << i << " " << f[i] << " " << temp << endl;
    }
    return 0;
}