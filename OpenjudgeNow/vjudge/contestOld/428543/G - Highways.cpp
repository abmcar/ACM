#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;

int n, m;
int father[Maxn];
int ans;
int posX[Maxn], posY[Maxn];

int find(int son)
{
    if (father[son] == son)
        return son;
    father[son] = find(father[son]);
    return father[son];
}

double getDis(int pos1, int pos2)
{
    double tx1 = posX[pos1];
    double tx2 = posX[pos2];
    double ty1 = posY[pos1];
    double ty2 = posY[pos2];
    return (tx1-tx2)*(tx1-tx2) + (ty1-ty2)*(ty1-ty2);
}

struct Edge
{
    int from, to;
    double val;
    bool const operator < (Edge b) const
    {
        return val > b.val;
    }
}edge[Maxn];

int main()
{
    Buff;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> posX[i] >> posY[i], father[i] = i;
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        int t1,t2;
        cin >> t1 >> t2;
        int f1 = find(t1);
        int f2 = find(t2);
        if(f1 == f2)
            continue;
        father[f1] = f2;
        // cout << "   " << i << ' ' << m << endl;
    }
    priority_queue<Edge> q;
    for(int i = 1; i <= n; i++)
    for(int j = i+1; j <= n; j++)
    {
        if(find(i) == find(j))
            continue;
        Edge temp;
        temp.from = i;
        temp.to = j;
        temp.val = getDis(i,j);
        q.push(temp);
    }
    while(!q.empty())
    {
        Edge nowEdge = q.top();
        q.pop();
        int f1 = find(nowEdge.from);
        int f2 = find(nowEdge.to);
        if(f1 == f2)
            continue;
        father[f1] = f2;
        cout << nowEdge.from << " " << nowEdge.to << endl;
    }
    return 0;
}