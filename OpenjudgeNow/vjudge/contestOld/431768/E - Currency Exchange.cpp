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

int n, m, s;
double strSum;
double dis[Maxn];
int updata[Maxn];
bool inQ[Maxn];
vector<int> g[Maxn];
vector<double> r[Maxn], c[Maxn];

int main()
{
    Buff;
    cin >> n >> m >> s >> strSum;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2;
        double t3, t4, t5, t6;
        cin >> t1 >> t2 >> t3 >> t4 >> t5 >> t6;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
        r[t1].push_back(t3);
        c[t1].push_back(t4);
        r[t2].push_back(t5);
        c[t2].push_back(t6);
    }
    dis[s] = strSum;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty())
    {
        int nowNode = Q.front();
        Q.pop();
        // cout << nowNode << " " << dis[nowNode] << endl;
        inQ[nowNode] = false;
        for (int i = 0; i < g[nowNode].size(); i++)
        {
            int nextNode = g[nowNode][i];
            if (dis[nowNode] < c[nowNode][i])
                continue;
            double nextDis = (dis[nowNode]-c[nowNode][i])*r[nowNode][i];
            if (nextDis > dis[nextNode])
            {
                dis[nextNode] = nextDis;
                if (!inQ[nextNode])
                {
                    inQ[nextNode] = true;
                    updata[nextNode]++;
                    if(updata[nextNode] >= n)
                    {
                        cout << "YES" << endl;
                        return 0;
                    }
                    Q.push(nextNode);
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}