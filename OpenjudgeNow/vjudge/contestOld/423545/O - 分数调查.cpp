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

int father[Maxn];
int n,m,q;
int rk[Maxn];

int find(int son)
{
    if(father[son] == son)
        return son;
    int temp = find(father[son]);
    rk[son] += rk[father[son]];
    father[son] = temp;
    return father[son];
}

int main()
{
    Buff;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        father[i] = i;
    for(int i = 1; i <= m; i++)
    {
        int x,y,s;
        cin >> x >> y >> s;
        int fx = find(x);
        int fy = find(y);
        if(fx == fy)
            continue;
        father[fx] = fy;
        rk[fx] += s-rk[x]+rk[y];
        //
    }
    for(int i = 1; i <= q; i++)
    {
        int x,y;
        cin >> x >> y;
        if(find(x) != find(y))
        {
            cout << "-1" << endl;
            continue;
        }
        cout << rk[x] - rk[y] << endl;
    }
    return 0;
}