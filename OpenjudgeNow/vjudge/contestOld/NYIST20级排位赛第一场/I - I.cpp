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
// #include <unordered_map>
// #include <unordered_set>
// #include <ext/pb_ds/priority_queue.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
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

int n, m;
int board[123][123];
int preAns[123][123];
bool vis[123][123];
ll tot = 0;
int ans = 0;
int nextX[5] = {0, 1, -1, 0};
int nextY[5] = {1, 0, 0, -1};

// void work(int strX, int strY)
// {
//     // map<int, int> M[123];
//     int nowAns = 0;
//     int M[123][123];
//     memset(M, 0, sizeof M);
//     queue<int> qX, qY, qD;
//     qX.push(strX);
//     qY.push(strY);
//     qD.push(1);
//     M[strX][strY] = true;
//     while (!qX.empty())
//     {
//         tot++;
//         int nowX = qX.front();
//         int nowY = qY.front();
//         int nowD = qD.front();
//         qX.pop();
//         qY.pop();
//         qD.pop();
//         if (M[nowX][nowY] > nowD)
//             continue;
//         else
//             M[nowX][nowY] = nowD;
//         // cout << nowX << " " << nowY << " " << nowD << endl;
//         nowAns = max(nowAns, nowD);
//         for (int i = 0; i < 4; i++)
//         {
//             int nx = nowX + nextX[i];
//             int ny = nowY + nextY[i];
//             int nd = nowD + 1;
//             if (nx > n || ny > m || nx < 1 || ny < 1)
//                 continue;
//             // if (M[nx][ny])
//             //     continue;
//             if (board[nx][ny] > board[nowX][nowY])
//                 continue;
//             if (nowD + M[nx][ny] > nowAns)
//                 continue;
//             // if (preAns[nx][ny] != 0)
//             // {
//             //     nowAns = max(nowAns, nowD+preAns[nx]
//             // }
//             qX.push(nx);
//             qY.push(ny);
//             qD.push(nd);
//             M[nx][ny] = true;
//         }
//     }
//     for (int i = 1; i <= n; i++)
//     for (int j = 1; j <= m; j++)
//         preAns[strX][strY] = max(preAns[strX][strY],M[i][j]);
//     ans = max(ans,nowAns);
//     // cout << strX << " " << strY << " " << nowAns << endl;
// }

int work(int nowX, int nowY, int nowD)
{
    tot++;
    if (preAns[nowX][nowY] != 0)
        return nowD - 1 + preAns[nowX][nowY];
    int nowMax = nowD;
    for (int i = 0; i < 4; i++)
    {
        int nx = nowX + nextX[i];
        int ny = nowY + nextY[i];
        if (nx > n || ny > m || nx < 1 || ny < 1)
            continue;
        if (vis[nx][ny])
            continue;
        if (board[nx][ny] >= board[nowX][nowY])
            continue;
        vis[nx][ny] = true;
        nowMax = max(nowMax, work(nx, ny, nowD + 1));
        vis[nx][ny] = false;
    }
    preAns[nowX][nowY] = max(preAns[nowX][nowY], nowMax - nowD + 1);
    return nowMax;
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> board[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            // if (board[i][j] > board[i+1][j])
            // if (board[i][j] > board[i][j+1])
            // if (board[i][j] > board[i-1][j])
            // if (board[i][j] > board[i][j-1])
            {
                // memset(preAns, 0, sizeof(preAns));
                vis[i][j] = true;
                preAns[i][j] = work(i, j, 1);
                ans = max(ans, preAns[i][j]);
                vis[i][j] = false;
            }
        }
    cout << ans << endl;
    // cout << tot << endl;
    return 0;
}