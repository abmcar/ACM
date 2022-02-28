#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3 + 10;

int nx1[] = {1, 1, -1, -1};
int nx2[] = {2, 2, -2, -2};
int ny1[] = {-1, 1, -1, 1};
int ny2[] = {-2, 2, -2, 2};
int n, m, k;
int strX, strY, endX, endY;
bool unV[Maxn][Maxn];
int minCost[Maxn][Maxn];

signed main()
{
    cin >> n >> m;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        unV[t1][t2] = true;
    }
    cin >> strX >> strY >> endX >> endY;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            minCost[i][j] = 1e9;
    queue<pair<int, int>> Q;
    Q.push({strX, strY});
    minCost[strX][strY] = 0;
    while (Q.size())
    {
        int nowX = Q.front().first;
        int nowY = Q.front().second;
        Q.pop();
        // cout << nowX << " " << nowY << endl;
        if (nowX == endX && nowY == endY)
        {
            cout << minCost[nowX][nowY] << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int nextX1 = nowX + nx1[i];
            int nextY1 = nowY + ny1[i];
            int nextCost = minCost[nowX][nowY] + 1;
            int nextX = nowX + nx2[i];
            int nextY = nowY + ny2[i];
            if (nextX > n || nextX < 1 || nextY > m || nextY < 1)
                continue;
            if (unV[nextX1][nextY1])
                continue;
            if (nextCost >= minCost[nextX][nextY])
                continue;
            minCost[nextX][nextY] = nextCost;
            Q.push({nextX, nextY});
        }
    }
    cout << -1 << endl;
    return 0;
}