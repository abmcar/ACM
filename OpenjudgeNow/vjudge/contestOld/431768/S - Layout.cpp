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

int n, ml, md;
int dis[Maxn], updata[Maxn];
bool inQ[Maxn];
vector<int> g[Maxn], w[Maxn];

bool spfa()
{
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
            int nextDis = dis[nowNode] + w[nowNode][i];
            if (nextDis < dis[nextNode])
            {
                dis[nextNode] = nextDis;
                if (!inQ[nextNode])
                {
                    updata[nextNode]++;
                    if (updata[nextNode] >= n)
                        return false;
                    inQ[nextNode] = true;
                    Q.push(nextNode);
                }
            }
        }
    }
    return true;
}

void init()
{
    cin >> n >> ml >> md;
    memset(dis,0x3f3f3f3f,sizeof(dis));
    for (int i = 1; i <= ml; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back(t2);
        w[t1].push_back(t3);
    }
    for (int i = 1; i <= md; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t2].push_back(t1);
        w[t2].push_back(t3*-1);
    }
}

void work()
{
    if (!spfa())
    {
        cout << "-1" << endl;
        return;
    }
    if (dis[n] == 0x3f3f3f3f)
        cout << "-2" << endl;
    else
        cout << dis[n] << endl;
}

int main()
{
    Buff;
    init();
    work();
    return 0;
}