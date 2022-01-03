#include "bits/stdc++.h"

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int n, ans;
string bd[1234];
queue<int> qX, qY, qD;
int nx[] = {0, 1, 0, -1};
int ny[] = {1, 0, -1, 0};
bool vis[1234][1234];

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
        cin >> bd[i];
        bd[i] = "-" + bd[i];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (bd[i][j] == '#')
            {
                qX.push(i), qY.push(j), qD.push(0);
                vis[i][j] = true;
            }
    while (!qX.empty())
    {
        int nowX = qX.front();
        int nowY = qY.front();
        int nowD = qD.front();
        // cout << nowX << " " << nowY << " " << nowD << endl;
        qX.pop();
        qY.pop();
        qD.pop();
        ans = nowD;
        for (int i = 0 ; i < 4; i++)
        {
            int nextX = nowX + nx[i];
            int nextY = nowY + ny[i];
            int nextD = nowD + 1;
            if (nextX > n || nextY > n || nextX < 1 || nextY < 1)
                continue;
            if (vis[nextX][nextY])
                continue;
            if (bd[nextX][nextY] == '#')
                continue;
            vis[nextX][nextY] = true;
            qX.push(nextX);
            qY.push(nextY);
            qD.push(nextD);
        }
    }
    cout << ans << endl;
    return 0;
}
/* 
3
#..
...
...

 */