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

const int Maxn = 123;
const ll Mod = 1e9+7;

int dis[Maxn][Maxn];
int father[Maxn];
int n, ans;

struct Edge
{
    int from,to,val;
    bool const operator < (Edge b) const
    {
        return val > b.val;
    }
};
priority_queue<Edge> q;

int find(int son)
{
    if(father[son] == son)
        return son;
    father[son] = find(father[son]);
    return father[son];
}

void work()
{
    ans = 0;
    for(int i = 1; i <= n; i++)
        father[i] = i;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    {
        cin >> dis[i][j];
        if(i == j)
            continue;
        Edge temp;
        temp.from = i;
        temp.to = j;
        temp.val = dis[i][j];
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
        ans += nowEdge.val;
    }
    cout << ans << endl;
}

int main()
{
    Buff;
    while(cin >> n)
        work();
    return 0;
}