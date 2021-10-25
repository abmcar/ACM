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

int strX, strY, endX, endY;
int posX[Maxn], posY[Maxn];
int cnt;
double dis[Maxn];
bool inQ[Maxn];
vector<int> g[Maxn];
vector<double> w[Maxn];

double getDis(int pos1, int pos2)
{
    double posX1 = posX[pos1];
    double posX2 = posX[pos2];
    double posY1 = posY[pos1];
    double posY2 = posY[pos2];
    return sqrt((posX1 - posX2) * (posX1 - posX2) + (posY1 - posY2) * (posY1 - posY2));
}

int main()
{
    Buff;
    cin >> strX >> strY;
    cin >> endX >> endY;
    posX[++cnt] = strX;
    posY[cnt] = strY;
    posX[++cnt] = endX;
    posY[cnt] = endY;
    int tempX, tempY;
    int preX, preY;
    preX = preY = -1;
    while (cin >> tempX >> tempY)
    {
        if (tempX == -1 && tempY == -1)
        {
            preX = preY = -1;
            continue;
        }
        posX[++cnt] = tempX;
        posY[cnt] = tempY;
        if (preX == -1 && preY == -1)
        {
            preX = tempX;
            preY = tempY;
            continue;
        }
        preX = tempX;
        preY = tempY;
        g[cnt-1].push_back(cnt);
        g[cnt].push_back(cnt-1);
        double nowDis = getDis(cnt-1,cnt) / (40000.0/60.0);
        w[cnt-1].push_back(nowDis);
        w[cnt].push_back(nowDis);
    }
    for (int i = 1; i <= cnt; i++)
        dis[i] = Inf;
    for (int i = 1; i <= cnt; i++)
    for (int j = i+1; j <= cnt; j++)
    {
        double nowDis = getDis(i,j) / (10000.0/60.0);
        g[i].push_back(j);
        g[j].push_back(i);
        w[i].push_back(nowDis);
        w[j].push_back(nowDis);
    }
    queue<int> Q;
    Q.push(1);
    dis[1] = 0;
    while (!Q.empty())
    {
        int nowNode = Q.front();
        Q.pop();
        inQ[nowNode] = false;
        for (int i = 0; i < g[nowNode].size(); i++)
        {
            int nextNode = g[nowNode][i];
            double nextDis = dis[nowNode] + w[nowNode][i];
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
    cout << fixed << setprecision(0) << dis[2] << endl;
    return 0;
}