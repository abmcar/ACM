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

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

int n, m;
int posX[Maxn], posY[Maxn];
double dis[Maxn];
bool inQ[Maxn];
vector<int> g[Maxn];
vector<double> w[Maxn];
int cnt;

double getDis(int pos1, int pos2)
{
    double posX1 = posX[pos1];
    double posX2 = posX[pos2];
    double posY1 = posY[pos1];
    double posY2 = posY[pos2];
    return sqrt((posX1 - posX2) * (posX1 - posX2) + (posY1 - posY2) * (posY1 - posY2));
}

void spfa()
{
    queue<int> Q;
    Q.push(1);
    dis[1] = 0;
    // dis[1] = 0;
    while (!Q.empty())
    {
        int nowNode = Q.front();
        Q.pop();
        inQ[nowNode] = false;
        for (int i = 0; i < g[nowNode].size(); i++)
        {
            int nextNode = g[nowNode][i];
            double nextDis = max(dis[nowNode],w[nowNode][i]);
            if (dis[nextNode] > nextDis)
            {
                dis[nextNode] = nextDis;
                if (!inQ[nextNode])
                {
                    inQ[nextNode] = true;
                    Q.push(nextNode);
                }
            }
        }
    }
}

void work()
{
    m = 0;
    for (int i = 1; i <= n; i++)
        cin >> posX[i] >> posY[i], dis[i] = 1e9, g[i].clear(), w[i].clear();
    for (int i = 1; i <= n; i++)
    for (int j = i+1; j <= n; j++)
    {
        double nowDis = getDis(i, j);
        g[i].push_back(j);
        g[j].push_back(i);
        w[i].push_back(nowDis);
        w[j].push_back(nowDis);
    }
    spfa();
    cout << "Scenario #" << ++cnt << endl;
    cout << "Frog Distance = " <<  fixed << setprecision(3) << dis[2] << endl << endl;
}

int main()
{
    Buff;
    while (cin >> n && n)
        work();
    return 0;
}