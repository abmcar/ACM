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

int n,m;
ll ans;
ll c[Maxn];
int father[Maxn];
bool ok[Maxn];

int find(int son)
{
    if(father[son] == son)
        return son;
    father[son] = find(father[son]);
    return father[son];
}

int main()
{
    Buff;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> c[i], father[i] = i;
    for(int i = 1; i <= m; i++)
    {
        int t1,t2;
        cin >> t1 >> t2;
        if(t1 == t2)
            continue;
        int fa1 = find(t1);
        int fa2 = find(t2);
        c[fa2] = min(c[fa2],c[fa1]);
        father[fa1] = fa2;
    }
    for(int i = 1; i <= n; i++)
    if(!ok[find(i)])
        ans += c[find(i)], ok[find(i)] = true;
    cout << ans;
    return 0;
}