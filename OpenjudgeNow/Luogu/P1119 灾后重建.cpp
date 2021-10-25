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

const int Maxn = 1e4 + 10;
const ll Mod = 1e9 + 7;

int n, m, q;
int dis[Maxn][Maxn];
int fixTime[Maxn];
int nowTime, nowFix = 1;

void updata(int pos)
{
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        dis[i][j] = min(dis[i][j], dis[i][pos] + dis[pos][j]);
}

int main()
{
    Buff;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        dis[i][j] = 1e9;
    // for (int i = 1; i <= n; i++)
    //     dis[i][i] = 0;
    for (int i = 1; i <= n; i++)
        cin >> fixTime[i];
    for (int i = 1; i <= m; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        t1++;
        t2++;
        dis[t1][t2] = t3;
        dis[t2][t1] = t3;
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int t1, t2;
        cin >> t1 >> t2 >> nowTime;
        t1++;
        t2++;
        for (nowFix; fixTime[nowFix] <= nowTime && nowFix <= n; nowFix++)
            updata(nowFix);
        if (dis[t1][t2] == 1e9 || nowTime < fixTime[t1] || nowTime < fixTime[t2])
            cout << "-1" << endl;
        else
            cout << dis[t1][t2] << endl;
    }
    return 0;
}