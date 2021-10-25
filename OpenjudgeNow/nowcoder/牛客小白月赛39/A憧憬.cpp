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

int n;
double dx[Maxn], dy[Maxn];
double targetX, targetY;
double targetX1, targetY1;
double targetX2, targetY2;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t1, t2, t3, t4;
        cin >> t1 >> t2 >> t3 >> t4;
        dx[i] = (t1 - t3);
        dy[i] = (t2 - t4);
    }
    cin >> targetX1 >> targetY1;
    cin >> targetX2 >> targetY2;
    targetX = targetX1 - targetX2;
    targetY = targetY1 - targetY2;
    // if (targetX == targetY && targetX == 0)
    // {
    //     cout << "YES" << endl;
    //     return 0;
    // }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            double nowX = dx[i] + dx[j];
            double nowY = dy[i] + dy[j];
            if (nowX / nowY == targetX / targetY)
            // if (targetY / nowY == targetX / nowX)
            {
                // cout << dx[i] << " " << dy[i] << " " << dy[j] << " " << dy[j] << endl;
                // cout << nowX << " " << nowY << " " << targetX << " " << targetY << endl;
                // cout << i << " " << j << endl;
                cout << "YES" << endl;
                return 0;
            }
        }
    cout << "NO" << endl;
    return 0;
}