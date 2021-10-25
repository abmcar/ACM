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

int t, n, m;
int board[555][555];
int preAns[555][555];
int r[555][555];
int finAns;

void work()
{
    cin >> n >> m;
    finAns = n*m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char tempChar;
            cin >> tempChar;
            board[i][j] = tempChar == '0' ? 0 : 1;
            r[i][j] = r[i][j-1] + board[i][j];
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            preAns[i][j] = preAns[i][j - 1] + preAns[i - 1][j] - preAns[i - 1][j - 1] + board[i][j];
    for (int x1 = 1; x1 <= n; x1++)
    for (int y1 = 1; y1 <= m; y1++)
    for (int x2 = x1+4; x2 <= n; x2++)
    for (int y2 = y1+3; y2 <= m; y2++)
    {
        int ans1 = preAns[x2-1][y2-1] - preAns[x2-1][y1] - preAns[x1][y2-1] + preAns[x1][y1];
        if (ans1 >= finAns)
            break;
        int temp1 = r[x1][y2-1] - r[x1][y1];
        int temp2 = r[x2][y2-1] - r[x2][y1];
        if (temp1+temp2 >= finAns)
            break;
        int ans2 = preAns[x2][y2] - preAns[x2][y1-1] - preAns[x1-1][y2] + preAns[x1-1][y1-1];
        ans2 = ((x2-x1+1)+(y2-y1+1))*2-4 - (ans2 - ans1);
        if (ans1+ans2-4 >= finAns)
            continue;
        if (board[x1][y1] == 0)
            ans2--;
        if (board[x1][y2] == 0)
            ans2--;
        if (board[x2][y1] == 0)
            ans2--;
        if (board[x2][y2] == 0)
            ans2--;
        // if (ans2 > finAns)
        //     continue;
        finAns = min(finAns, ans2+ans1);
        // cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << ans1 << " " << ans2 << endl;
    }
    cout << finAns << endl;
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