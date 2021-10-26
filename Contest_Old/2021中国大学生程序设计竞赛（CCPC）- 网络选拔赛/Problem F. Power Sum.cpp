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

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    ll tot = 0;
    // for (int i = 1; i <= 1000; i++)
        // tot = tot + i * i;
        // cout << i << " " << i*i << " " << 2*i-1 << endl;
    // cout << tot << endl;
    map<int,int> f[1010];
    map<int,int> ok;
    f[0][0] = 1;
    for (int i = 1; i <= 150; i++)
    {
        for (auto it : f[i-1])
        {
            f[i][it.first + i*i] = 1;
            f[i][it.first - i*i] = 1;
            ok[it.first + i*i] = 1;
            ok[it.first - i*i] = 1;
        }
        cout << i << endl;
    }
    for (int i = 1; i <= 1000000; i++)
        if (!ok[i])
            cout << i << endl;
        // cout << i << "  " << ok[i] << endl;
    return 0;
}
/**
 * @brief 
 * 1
 * 3 3 2
 * 1 N 1 Y 1 N
 * 1 N 1 Y 1 N
 * 1 N 1 N 1 N
 */