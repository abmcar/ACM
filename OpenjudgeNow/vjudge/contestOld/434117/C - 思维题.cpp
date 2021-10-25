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

const int Maxn = 1e6 + 10;
const ll Mod = 1e9 + 7;

int n, m;
int father[Maxn], deep[Maxn];
int fa[Maxn][32];
bool vised[Maxn];
vector<int> g[Maxn];

void dfs(int nowNode, int fatherNode)
{
    father[nowNode] = fatherNode;
    deep[nowNode] = deep[fatherNode] + 1;
    vised[nowNode] = true;
    fa[nowNode][0] = fatherNode;
    for (int i = 1; (1 << i) <= deep[nowNode]; i++)
        fa[nowNode][i] = fa[fa[nowNode][i - 1]][i - 1];
    for (int i = 0; i < g[nowNode].size(); i++)
    {
        int nextNode = g[nowNode][i];
        if (vised[nextNode])
            continue;
        dfs(nextNode, nowNode);
    }
}

int main()
{
    Buff;
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    dfs(1, 0);
    for (int i = 1; i <= m; i++)
    {
        int num;
        vector<int> nodes;
        map<int,bool> M;
        M[0] = true;
        int maxNum = 0;
        int maxPos;
        cin >> num;
        for (int j = 1; j <= num; j++)
        {
            int tempNum;
            cin >> tempNum;
            nodes.push_back(tempNum);
        }
        for (int j = 0; j < num; j++)
        {
            if (maxNum < deep[nodes[j]])
            {
                maxNum = deep[nodes[j]];
                maxPos = nodes[j];
            }
        }
        queue<int> Q;
        Q.push(maxPos);
        while (!Q.empty())
        {
            int nowNode = Q.front();
            Q.pop();
            // cout << nowNode << endl;
            M[nowNode] = true;
            for (int j = 0; j < g[nowNode].size(); j++)
            {
                int nextNode = g[nowNode][j];
                // cout << nowNode << " " << nextNode << endl;
                if (deep[nowNode] < deep[nextNode])
                    continue;
                // cout << nowNode << " " << nextNode << endl;
                // cout << deep[nowNode] << " " << deep[nextNode] << endl << endl;
                Q.push(nextNode);
            }
        }
        bool ok = true;
        for (int j = 0; j < num; j++)
        {
            // cout << nodes[j] << " " << father[nodes[j]] << endl;
            if (!M[father[nodes[j]]])
            {
                ok = false;
                break;
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}