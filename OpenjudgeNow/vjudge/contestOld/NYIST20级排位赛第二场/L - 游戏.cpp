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

int n, m, k;
int board[233][233];
int x, y, cnt;
String ans;
int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        int nowX, nowY;
        cin >> nowX >> nowY;
        // board[nowX][nowY] = true;
    }
    for (int i = 1; i <= k; i++)
    {
        int nowX, nowY;
        cin >> nowX >> nowY;
        board[nowX][nowY] = true;
    }
    for (int i = 1; i <= n; i++)
        ans = ans + "U";
    // cout << "L";
    for (int i = 1; i <= m; i++)
        ans = ans + "L";
    // cout << "R";
    cnt = n * m;
    x = y = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            for (int i =2; i <= m; i++)
                ans.append("R");
            if (n > 1)
            ans.append("D");
            continue;
        }
        if (i % 2)
            for (int i = 2; i <= m; i++)
                ans.append("R");
        else
            for (int i = 2; i <= m; i++)
                ans.append("L");
        if (i != n)
        ans.append("D");
    }
    cout << ans.size() << endl;
    cout << ans << endl;
    return 0;
}