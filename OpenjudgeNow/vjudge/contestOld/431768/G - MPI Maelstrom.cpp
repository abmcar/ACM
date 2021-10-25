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

int n, ans;
int dis[Maxn];
bool inQ[Maxn];
vector<int> g[Maxn], w[Maxn];

void init()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    for (int j = 1; j < i; j++)
    {
        string tempString;
        cin >> tempString;
        int temp = 0;
        if (tempString == "x")
            continue;
        for (int i = 0; i <= tempString.size() - 1; i++)
        {
            temp *= 10;
            temp += tempString[i] - '0';
        }
        // cout << i << " " << j << " " << tempString << " " << temp << endl;
        g[i].push_back(j);
        g[j].push_back(i);
        w[i].push_back(temp);
        w[j].push_back(temp);
    }
    for (int i = 1; i <= n; i++)
        dis[i] = Inf;
}

void work()
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
                    inQ[nextNode] = true;
                    Q.push(nextNode);
                }
            }
        }
    }
    for (int i = 2; i <= n; i++)
        ans = max(ans,dis[i]);
    cout << ans;
}

int main()
{
    Buff;
    init();
    work();
    return 0;
}