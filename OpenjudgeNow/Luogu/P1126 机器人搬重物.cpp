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
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

int nx[5] = {0, 1, 0, -1, 0};
int ny[5] = {0, 0, 1, 0, -1};
int n, m;
int bd[Maxn][Maxn];
int minTime[Maxn][Maxn][5];
int strX, strY, endX, endY;
char firDir;
int ans = 1e9;

struct Node
{
    int x, y;
    int direction;
    int time;
    bool isEnd()
    {
        if (x == endX && y == endY)
            return true;
        return false;
    }
};

void bfs()
{
    queue<Node> Q;
    int dirNum;
    switch (firDir)
    {
    case 'N':
        dirNum = 3;
        break;
    case 'S':
        dirNum = 1;
        break;
    case 'E':
        dirNum = 2;
        break;
    case 'W':
        dirNum = 4;
        break;
    }
    Q.push({strX,
            strY,
            dirNum,
            0});
    while (!Q.empty())
    {
        Node nowNode = Q.front();
        Q.pop();
        // cout << nowNode.x << " " << nowNode.y << " " << nowNode.time << endl;
        if (nowNode.isEnd())
        {
            ans = min(ans, nowNode.time);
            continue;
        }
        if (nowNode.direction == 1)
        {
            Node nextNode;
            nextNode = nowNode;
            nextNode.time++;
            if (nextNode.time < minTime[nowNode.x][nowNode.y][2])
            {
                minTime[nowNode.x][nowNode.y][2] = nextNode.time;
                nextNode.direction = 2;
                Q.push(nextNode);
            }
            if (nextNode.time < minTime[nowNode.x][nowNode.y][4])
            {
                minTime[nowNode.x][nowNode.y][4] = nextNode.time;
                nextNode.direction = 4;
                Q.push(nextNode);
            }
            if (nextNode.time+1 < minTime[nowNode.x][nowNode.y][3])
            {
                minTime[nowNode.x][nowNode.y][3] = nextNode.time+1;
                nextNode.direction = 3;
                nextNode.time++;
                Q.push(nextNode);
                nextNode.time--;
            }
        }
        if (nowNode.direction == 2)
        {
            Node nextNode;
            nextNode = nowNode;
            nextNode.time++;
            if (nextNode.time < minTime[nowNode.x][nowNode.y][3])
            {
                minTime[nowNode.x][nowNode.y][3] = nextNode.time;
                nextNode.direction = 3;
                Q.push(nextNode);
            }
            if (nextNode.time < minTime[nowNode.x][nowNode.y][1])
            {
                minTime[nowNode.x][nowNode.y][1] = nextNode.time;
                nextNode.direction = 1;
                Q.push(nextNode);
            }
            if (nextNode.time+1 < minTime[nowNode.x][nowNode.y][4])
            {
                minTime[nowNode.x][nowNode.y][4] = nextNode.time+1;
                nextNode.direction = 4;
                nextNode.time++;
                Q.push(nextNode);
                nextNode.time--;
            }
        }
        if (nowNode.direction == 3)
        {
            Node nextNode;
            nextNode = nowNode;
            nextNode.time++;
            if (nextNode.time < minTime[nowNode.x][nowNode.y][4])
            {
                minTime[nowNode.x][nowNode.y][4] = nextNode.time;
                nextNode.direction = 4;
                Q.push(nextNode);
            }
            if (nextNode.time < minTime[nowNode.x][nowNode.y][2])
            {
                minTime[nowNode.x][nowNode.y][2] = nextNode.time;
                nextNode.direction = 2;
                Q.push(nextNode);
            }
            if (nextNode.time+1 < minTime[nowNode.x][nowNode.y][1])
            {
                minTime[nowNode.x][nowNode.y][1] = nextNode.time+1;
                nextNode.direction = 1;
                nextNode.time++;
                Q.push(nextNode);
                nextNode.time--;
            }
        }
        if (nowNode.direction == 4)
        {
            Node nextNode;
            nextNode = nowNode;
            nextNode.time++;
            if (nextNode.time < minTime[nowNode.x][nowNode.y][1])
            {
                minTime[nowNode.x][nowNode.y][1] = nextNode.time;
                nextNode.direction = 1;
                Q.push(nextNode);
            }
            if (nextNode.time < minTime[nowNode.x][nowNode.y][3])
            {
                minTime[nowNode.x][nowNode.y][3] = nextNode.time;
                nextNode.direction = 3;
                Q.push(nextNode);
            }
            if (nextNode.time+1 < minTime[nowNode.x][nowNode.y][2])
            {
                minTime[nowNode.x][nowNode.y][2] = nextNode.time+1;
                nextNode.direction = 2;
                nextNode.time++;
                Q.push(nextNode);
                nextNode.time--;
            }
        }
        nowNode.time++;
        for(int i = 1; i <= 3; i++)
        {
            if(bd[nowNode.x][nowNode.y] == 1 || bd[nowNode.x+1][nowNode.y] == 1 || bd[nowNode.x][nowNode.y+1] == 1 || bd[nowNode.x+1][nowNode.y+1] == 1)
                break;
            nowNode.x += nx[nowNode.direction];
            nowNode.y += ny[nowNode.direction];
            if(nowNode.isEnd())
            {
                ans = min(ans,nowNode.time);
                cout << ans << endl;
                return;
            }
            if(nowNode.x > n || nowNode.x < 1 || nowNode.y > m || nowNode.y < 1)
                break;
            if(nowNode.time < minTime[nowNode.x][nowNode.y][nowNode.direction])
                Q.push(nowNode);
        }
    }
    if (ans == 1e9)
        ans = -1;
    cout << ans << endl;
}

int main()  
{
    Buff;
    cin >> n >> m;
    for (int i = 0; i <= n+1; i++)
        for (int j = 0; j <= m+1; j++)
            bd[i][j] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> bd[i][j];
            for(int k = 1; k <= 4; k++)
                minTime[i][j][k] = 1e9;
        }
    cin >> strX >> strY >> endX >> endY >> firDir;
    bfs();
    // cout << ans << endl;
    return 0;
}