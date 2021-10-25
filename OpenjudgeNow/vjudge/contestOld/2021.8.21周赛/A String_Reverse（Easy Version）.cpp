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
#define ull unsigned long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const int Maxn = 1e6 + 10;
const ll Mod = 1e9 + 7;

int n, m;
ull prime = 131;
String oriString, tempString;

ull p[Maxn], h[Maxn], h1[Maxn];

inline ull getHash(int l, int r)
{
    return h[r] - h[l-1] * p[r-l+1];
}

inline ull getHash1(int l, int r)
{
    return h1[r] - h1[l-1] * p[r-l+1];
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int t;
    cin >> t;
    p[0] = 1;
    for (int i = 1; i <= 1e6; i++)
        p[i] = p[i-1] * prime;
    while (t--)
    {
        cin >> n >> m >> oriString;
        oriString = "-" + oriString;
        for (int i = 1; i <= n; i++)
        {
            h[i] = h[i-1] * prime + oriString[i];
            h1[i] = h1[i-1] * prime + oriString[n-i+1];
        }
        int l1, l2, r1, r2;
        while (m--)
        {
            cin >> l1 >> r1 >> l2 >> r2;
            cout << (getHash(l1,r1) == getHash1(n-r2+1,n-l2+1) ? "YES" : "NO") << endl;
        }
    }
    return 0;
}