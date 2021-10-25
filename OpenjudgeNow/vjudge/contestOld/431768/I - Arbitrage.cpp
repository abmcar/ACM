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

int t;
int n, m;
map<string,int> M;
double dis[Maxn];
int updata[Maxn];
bool inQ[Maxn];
vector<int> g[Maxn];
vector<double> w[Maxn];

bool spfa()
{
    queue<int> Q;
    Q.push(1);
    dis[1] = 10;
    inQ[1] = true;
    while (!Q.empty())
    {
        int nowNode = Q.front();
        Q.pop();
        // cout << nowNode << " " << updata[nowNode] << endl;
        inQ[nowNode] = false;
        for (int i = 0; i < g[nowNode].size(); i++)
        {
            int nextNode = g[nowNode][i];
            double nextDis = dis[nowNode]*w[nowNode][i];
            // cout << dis[nextNode] << " " << nextDis << " " << nowNode << " " << nextNode << endl;
            if (dis[nextNode] < nextDis)
            {
                dis[nextNode] = nextDis;
                if (!inQ[nextNode])
                {
                    updata[nextNode]++;
                    if (updata[nextNode] >= n)
                        return false;
                    Q.push(nextNode);
                    inQ[nextNode] = true;
                }
            }
        }
    }
    return true;
}

void work()
{
    M.clear();
    for (int i = 1; i <= n; i++)
        dis[i] = 0, inQ[i] = false, updata[i] = 0, g[i].clear(), w[i].clear();
    for (int i = 1; i <= n; i++)
    {
        string tempString;
        cin >> tempString;
        M[tempString] = i;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        string s1,s2;
        int t1, t2;
        double t3;
        cin >> s1 >> t3 >> s2;
        t1 = M[s1];
        t2 = M[s2];
        g[t1].push_back(t2);
        w[t1].push_back(t3);
    }
    if (spfa())
        cout << "Case " << ++t << ": No" << endl;
    else
        cout << "Case " << ++t << ": Yes" << endl;
}

int main()
{
    Buff;
    while (cin >> n && n)
        work();
    return 0;
}