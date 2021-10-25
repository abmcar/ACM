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

const int Maxn = 1234;
const ll Mod = 1e9 + 7;

int n, m, ans;
char bd[Maxn][Maxn];
bool used1[Maxn], used2[Maxn];

void bfs(int strX, int strY)
{
    queue<int> qx,qy;
    qx.push(strX);
    qy.push(strY);
    while (!qx.empty())
    {
        int nowX = qx.front();
        int nowY = qy.front();
        qx.pop();
        qy.pop();
        for (int i = 1; i <= n; i++)
        {
            if (used1[i])
                continue;
            if (bd[i][nowY] == '1')
            {
                used1[i] = true;
                qx.push(i);
                qy.push(nowY);
            }
        }
        for (int i = 1; i <= m; i++)
        {
            if (used2[i])
                continue;
            if (bd[nowX][i] == '1')
            {
                used2[i] = true;
                qx.push(nowX);
                qy.push(i);
            }
        }
    }
}

int main()
{
    Buff;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        cin >> bd[i][j];
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
        if (used1[i] || used2[j])
            continue;
        if (bd[i][j] == '0')
            continue;
        ans++;
        bfs(i,j);
    }
    cout << ans;
    return 0;
}