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

int m, n, ans = 1e9;
int color[Maxn][Maxn];
int nx[5] = {0, 1, 0, -1, 0};
int ny[5] = {0, 0, 1, 0, -1};
int minCost[Maxn][Maxn];

struct Node
{
    int x, y;
    int cost;
    int usingMagic;
    bool isEnd()
    {
        if (x == m && y == m)
            return true;
        return false;
    }
};

void bfs()
{
    queue<Node> Q;
    Q.push({1, 1, 0, 0});
    while (!Q.empty())
    {
        Node nowNode = Q.front();
        Q.pop();
        // cout << "nowNode:" << nowNode.x << " " << nowNode.y << " " << nowNode.cost << endl;
        if (nowNode.isEnd())
        {
            ans = min(ans, nowNode.cost);
            continue;
        }
        for (int i = 1; i <= 4; i++)
        {
            Node nextNode;
            nextNode.x = nowNode.x + nx[i];
            nextNode.y = nowNode.y + ny[i];
            nextNode.usingMagic = 0;
            // cout << "#pass0" << endl;
            if (nextNode.x > m || nextNode.y > m || nextNode.x < 1 || nextNode.y < 1)
                continue;
            if (color[nextNode.x][nextNode.y] == 0)
            {
                // cout << "#pass1" << endl;
                if (nowNode.usingMagic == 0)
                {
                    nextNode.usingMagic = 1;
                    nextNode.cost = nowNode.cost + 2;
                    if (color[nowNode.x][nowNode.y] != 1)
                        nextNode.cost++;
                    // cout << "#pass2 usingMagic" << endl;
                    // if (nextNode.cost >= minCost[nextNode.x][nextNode.y])
                    //     continue;
                    minCost[nextNode.x][nextNode.y] = nextNode.cost;
                    Q.push(nextNode);
                    nextNode.usingMagic = 2;
                    if (color[nowNode.x][nowNode.y] != 1)
                        nextNode.cost--;
                    if (color[nowNode.x][nowNode.y] != 2)
                        nextNode.cost++;
                    // if (nextNode.cost >= minCost[nextNode.x][nextNode.y])
                    //     continue;
                    minCost[nextNode.x][nextNode.y] = min(minCost[nextNode.x][nextNode.y], nextNode.cost);
                    Q.push(nextNode);
                    continue;
                }
                continue;
            }
            // cout << "#pass3" << endl;
            if (nowNode.usingMagic != 0)
            {
                if (nowNode.usingMagic == color[nextNode.x][nextNode.y])
                    nextNode.cost = nowNode.cost;
                else
                    nextNode.cost = nowNode.cost + 1;
            }
            else
            {
                if (color[nowNode.x][nowNode.y] == color[nextNode.x][nextNode.y])
                    nextNode.cost = nowNode.cost;
                else
                    nextNode.cost = nowNode.cost + 1;
            }
            if (minCost[nextNode.x][nextNode.y] <= nextNode.cost)
                continue;
            // cout << "#pass4" << endl;
            minCost[nextNode.x][nextNode.y] = nextNode.cost;
            Q.push(nextNode);
        }
    }
    if (ans == 1e9)
        ans = -1;
    cout << ans << endl;
}

int main()
{
    Buff;
    cin >> m >> n;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            minCost[i][j] = 1e9;
    for (int i = 1; i <= n; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        if (t3 == 0)
            t3 = 2;
        color[t1][t2] = t3;
    }
    bfs();
    return 0;
}