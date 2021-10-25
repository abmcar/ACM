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

int n, m, x;
int ans1, ans2, pos1, pos2;
int arr1[Maxn], arr2[Maxn];

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
        cin >> arr1[i];
    for (int i = 1; i <= m; i++)
        cin >> arr2[i];
    pos2 = m;
    for (pos1 = 1; pos1 <= n; pos1++)
    {
        while (arr1[pos1] + arr2[pos2] > x && pos2 > 1)
            pos2--;
        if (arr1[pos1] + arr2[pos2] == x)
            cout << pos1-1 << " " << pos2-1 << endl;
    }
    return 0;
}