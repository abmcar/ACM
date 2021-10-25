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

const int Maxn = 1e2 + 10;
const ll Mod = 1e9 + 7;

int nx[5] = {0, 1, 0, -1, 0};
int ny[5] = {0, 0, 1, 0, -1};
int n, m, t;
int ans;
bool used[Maxn][Maxn];
char bd[Maxn][Maxn];
int temp[Maxn][Maxn][20];
int strX, strY, endX, endY;

struct Node
{
    int x, y, time;
};

int main()
{
    Buff;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> bd[i][j];
    cin >> strX >> strY >> endX >> endY;
    queue<Node> Q;
    Q.push({strX, strY, 0});
    temp[strX][strY][0] = 1;
    while (!Q.empty())
    {
        Node nowNode = Q.front();
        Q.pop();
        if(nowNode.time == t)
        {
            if(nowNode.x == endX && nowNode.y == endY)
                ans += temp[nowNode.x][nowNode.y][t];
            temp[nowNode.x][nowNode.y][t] = 0;
            continue;
        }
        for (int i = 1; i <= 4; i++)
        {
            Node nextNode;
            nextNode.x = nowNode.x + nx[i];
            nextNode.y = nowNode.y + ny[i];
            nextNode.time = nowNode.time + 1;
            if(nextNode.x > n || nextNode.y > m || nextNode.x < 1 || nextNode.y < 1)
                continue;
            if(bd[nextNode.x][nextNode.y] == '*')
                continue;
            if(temp[nextNode.x][nextNode.y][nextNode.time] == 0)
                Q.push(nextNode);
            temp[nextNode.x][nextNode.y][nextNode.time] += temp[nowNode.x][nowNode.y][nowNode.time];
        }
        temp[nowNode.x][nowNode.y][nowNode.time] = 0;
    }
    cout << ans << endl;
    return 0;
}