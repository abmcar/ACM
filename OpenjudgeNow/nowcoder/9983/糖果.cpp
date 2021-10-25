#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#define ll long long

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
int father[Maxn];
int sons[Maxn];
ll havenum[Maxn];
ll ans;
int n,m;

int find(int son)
{
    if(father[son] == son)
        return son;
    father[son] = find(father[son]);
    return father[son];
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> havenum[i],father[i] = i;
    fill(sons+1,sons+1+n,1);
    for(int i =  1; i <= m; i++)
    {
        int a,b;
        cin >> a >> b;
        if(find(a) == find(b))
            continue;
        ll nowhave = havenum[find(a)];
        ll nowsons = sons[find(a)];
        father[find(a)] = find(b);
        sons[find(b)] += nowsons;
        havenum[find(b)] = max(havenum[find(b)],nowhave);
    }
    for(int i = 1; i <= n; i++)
        if(father[i] == i)
            ans += havenum[i]*sons[i];
    cout << ans;
    return 0;
}