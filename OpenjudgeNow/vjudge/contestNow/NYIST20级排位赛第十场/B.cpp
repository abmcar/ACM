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

int nx[] = {0, 1, 0, -1};
int ny[] = {1, 0, -1, 0};
char bd[123][123][123];
bool vis[123][123][123];
int k, m, n;
int strX, strY;
int ans;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> k >> n >> m;
    for (int i = 1; i <= k; i++)
    {
        for (int ax = 1; ax <= n; ax++)
            for (int ay = 1; ay <= m; ay++)
                cin >> bd[i][ax][ay];
    }
    // for (int i = 1; i <= k; i++)
    // {
    //     for (int ax = 1; ax <= n; ax++){
    //         for (int ay = 1; ay <= m; ay++)
    //             cout << bd[i][ax][ay];
    //         cout << Endl;
    //     }
    // }
    cin >> strX >> strY;
    queue<int> qX, qY, qZ;
    qX.push(strX);
    qY.push(strY);
    qZ.push(1);
    ans = 1;
    vis[1][strX][strY] = true;
    while (!qX.empty())
    {
        int nowX = qX.front();
        int nowY = qY.front();
        int nowZ = qZ.front();
        qX.pop();
        qY.pop();
        qZ.pop();
        // cout << nowX << " " << nowY << " " << nowZ << endl;
        for (int i = 0; i < 4; i++)
        {
            int nextX = nowX + nx[i];
            int nextY = nowY + ny[i];
            if (vis[nowZ][nextX][nextY])
                continue;
            if (nextX > n || nextY > m || nextX < 1 || nextY < 1)
                continue;
            if (bd[nowZ][nextX][nextY] == '#')
                continue;
            vis[nowZ][nextX][nextY] = true;
            ans++;
            qX.push(nextX);
            qY.push(nextY);
            qZ.push(nowZ);
        }
        // cout << nowX << " " << nowY << " " << nowZ << endl;
        // cout << vis[nowZ + 1][nowX][nowY] << " " << nowZ + 1 << " ! " << bd[nowZ + 1][nowX][nowY] << endl;
        if (vis[nowZ + 1][nowX][nowY] == false && nowZ + 1 <= k && bd[nowZ + 1][nowX][nowY] == '.')
        {
            vis[nowZ + 1][nowX][nowY] = true;
            ans++;
            qX.push(nowX);
            qY.push(nowY);
            qZ.push(nowZ + 1);
        }
        if (vis[nowZ - 1][nowX][nowY] == false && nowZ - 1 >= 1 && bd[nowZ - 1][nowX][nowY] == '.')
        {
            vis[nowZ - 1][nowX][nowY] = true;
            ans++;
            qX.push(nowX);
            qY.push(nowY);
            qZ.push(nowZ - 1);
        }
    }
    cout << ans << endl;
    return 0;
}