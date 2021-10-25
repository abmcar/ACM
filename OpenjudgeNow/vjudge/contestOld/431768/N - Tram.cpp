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

const int Maxn = 123;
const ll Mod = 1e9 + 7;

int n, strPos, endPos;
int dis[Maxn][Maxn];
bool inQ[Maxn];

void init()
{
    cin >> n >> strPos >> endPos;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        dis[i][j] = 1e9;
    for (int i = 1; i <= n; i++)
    {
        int tempN, tempNode;
        cin >> tempN;
        for (int j = 1; j <= tempN; j++)
        {
            cin >> tempNode;
            dis[i][tempNode] = 1;
            if (j == 1)
                dis[i][tempNode] = 0;
        }
    }
}

void work()
{
    for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
        // cout << dis[i][j] << " " << dis[i][k] + dis[k][j] << endl;
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
    if (dis[strPos][endPos] == 1e9)
        dis[strPos][endPos] = -1;
    cout << dis[strPos][endPos];
}

int main()
{
    Buff;
    init();
    work();
    return 0;
}