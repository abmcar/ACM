#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <map>
#include <stack>
using namespace std;
int n, m, t;
int mp[105][105];
int vis[105][105];
int pre[5000005];
// int mv[8][2] = {2, 1, -2, 1, 2, -1, -2, -1, 1, 2, -1, 2, 1, -2, -1, -2};
int moveX[8] = {2,2,1,1,-2,-2,-1,-1};
int moveY[8] = {1,-1,2,-2,1,-1,-2,2};
int strX, strY;
int endX, endY;
bool p = false;
map<pair<int,int>,pair<int,int>> M;

void pr(pair<int,int> x)
{
    // cout << "nowpr" << endl;
    stack<pair<int,int>> S;
    S.push(x);
    while (x.first != strX || x.second != strY)
    {
        // cout << x.first << "    " << x.second << endl;
        x = M[x];
        S.push(x);
    }
    // cout << S.size() << endl;
    while (S.size() > 1)
    {
        cout << "(" << S.top().first << "," << S.top().second << ")";
        cout << ',';
        S.pop();
    }
    cout << "(" << S.top().first << "," << S.top().second << ")" << endl;
    return;
}

void bfs()
{
    queue<int> qX, qY, qT;
    vis[strX][strY] = 1;
    qX.push(strX);
    qY.push(strY);
    qT.push(0);
    while (!qX.empty())
    {
        int nowX = qX.front();
        int nowY = qY.front();
        int nowT = qT.front();
        qX.pop();
        qY.pop();
        qT.pop();
        pair<int,int> nowP = make_pair(nowX,nowY);
        // cout << "bfs " << nowX << " " << nowY << endl;
        if (nowX == endX && nowY == endY)
        {
            p = true;
            printf("%d\n", nowT);
            pr(nowP);
            return;
        }
        for (int i = 0; i < 8; i++)
        {
            int nextX = nowX + moveX[i];
            int nextY = nowY + moveY[i];
            if (nextX >= 0 && nextY >= 0 && nextX < m && nextY < n)
            {
                if (vis[nextX][nextY] == 0 && mp[nextX][nextY] == 0)
                {
                    int nextT = nowT + 1;
                    // pre[nextX * 1000 + nextY + 1000] = r.x * 1000 + r.y;
                    pair<int,int> nextP = make_pair(nextX,nextY);
                    M[nextP] = nowP;
                    qX.push(nextX);
                    qY.push(nextY);
                    qT.push(nextT);
                    vis[nextX][nextY] = 1;
                }
            }
        }
    }
}
int main()
{
    int i, j;
    while (~scanf("%d", &m))
    {
        if (m == -1)
        {
            break;
        }
        // p = 0;
        scanf("%d", &n);
        M.clear();
        p = false;
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                // pre[i * 1000 + j + 1000] = i * 1000 + j;
                vis[i][j] = 0;
                scanf("%d", &mp[i][j]);
            }
        }
        cin >> strX >> strY >> endX >> endY;
        bfs();
        if (!p)
        {
            printf("0\n");
        }
    }
    return 0;
}