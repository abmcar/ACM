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

using namespace std;

const int Maxn = 1e6+10;
const ll Mod = 1e9+7;
int l,r;
int n,q;
int father[Maxn];
int m;

struct Edge
{
    int from,to;
    ll val;
    bool const operator< (const Edge b) const
    {
        return val > b.val;
    }
}edge[Maxn];

int find(int son)
{
    if(father[son] == son)
        return son;
    father[son] = find(father[son]);
    return father[son];
}


bool check()
{
    for (int i = 2; i <= n; i++)
        if (find(i) != find(i - 1))
            return 0;
    return 1;
}

void work(int l,int r)
{
    priority_queue<Edge> qE;
    ll ans = 0;
    for(int i = 1; i <= n; i++)
        father[i] = i;
    for(int i = l; i <= r; i++)
        qE.push(edge[i]);
    while(!qE.empty())
    {
        Edge now = qE.top();
        qE.pop();
        if(find(now.from) != find(now.to))
        {
            ans += now.val;
            father[find(now.from)] = find(father[now.to]);
        }
    }
    if(check())
        cout << ans << endl;
    else
        cout << "Impossible"<< endl;
}

int main()
{
    Buff;
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++)
        cin >> edge[i].from >> edge[i].to >> edge[i].val;
    for(int i = 1; i <= q; i++)
    {
        int opt;
        int x,y,z,t;
        cin >> opt;
        if(opt == 2)
        {
            cin >> l >> r;
            work(l,r);
        }else
        {
            cin >> x >> y >> z >> t;
            edge[x].from = y;
            edge[x].to = z;
            edge[x].val = t;
        }
    }
    return 0;
}