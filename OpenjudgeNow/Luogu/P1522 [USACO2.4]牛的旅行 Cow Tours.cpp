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

const int Maxn = 233;
const ll Mod = 1e9 + 7;

struct Edge
{
    int from, to;
    double val;
    bool const operator<(Edge b) const
    {
        return val > b.val;
    }
};

int n, posX[Maxn], posY[Maxn], father[Maxn];
double dis[Maxn][Maxn];
double Dis[Maxn][Maxn], ldis[Maxn];
bool isEdge[Maxn][Maxn];
double ans = 2e9;
double ans1;
int farPos[Maxn];
vector<int> points1, points2;
priority_queue<Edge> Q;

double getDis(int pos1, int pos2)
{
    double posX1 = posX[pos1];
    double posX2 = posX[pos2];
    double posY1 = posY[pos1];
    double posY2 = posY[pos2];
    return sqrt((posX1 - posX2) * (posX1 - posX2) + (posY1 - posY2) * (posY1 - posY2));
}

int find(int son)
{
    if (father[son] == son)
        return son;
    father[son] = find(father[son]);
    return father[son];
}

int main()
{
    Buff;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> posX[i] >> posY[i], father[i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            Dis[i][j] = 2e9;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = getDis(i, j);
            char tempChar;
            cin >> tempChar;
            if (i == j)
            {
                dis[i][j] = 2e9;
                continue;
            }
            if (tempChar == '1')
            {
                Dis[i][j] = dis[i][j];
                isEdge[i][j] = true;
                int f1 = find(i);
                int f2 = find(j);
                if (f1 == f2)
                    continue;
                father[f1] = f2;
            }
            else
                Q.push({i, j, dis[i][j]});
        }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                Dis[i][j] = min(Dis[i][j], Dis[i][k] + Dis[k][j]);
            }
    for (int i = 1; i <= n; i++)
    {
        double maxn = 0;
        for (int j = 1; j <= n; j++)
        {
            // if(i == j)
            //     continue;
            if (Dis[i][j] == 2e9)
                continue;
            ans1 = max(ans1, Dis[i][j]);
            if (Dis[i][j] > maxn)
            {
                maxn = Dis[i][j];
                farPos[i] = j;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
        int f1 = find(i);
        int f2 = find(j);
        if (f1 == f2)
            continue;
        // cout << dis[i][j] + Dis[i][farPos[i]] + Dis[j][farPos[j]] << endl;
        ans = min(ans, dis[i][j] + Dis[i][farPos[i]] + Dis[j][farPos[j]]);
    }
    ans = max(ans,ans1);
    cout << fixed << setprecision(6) << ans;
    return 0;
}