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
int t,n,m;
int father[Maxn];

int find(int son)
{
    if(father[son] == son)
        return son;
    father[son] = find(father[son]);
    return father[son];
}

void work()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        father[i] = i;
    for(int i = 1; i <= m; i++)
    {
        int ta,tb;
        cin >> ta >> tb;
        if(find(ta) != find(tb))
            father[find(ta)] = find(tb);
    }
    map<int,bool> M;
    int ans = 0;
    for(int i = 1; i <= n; i++)
    if(M[find(i)] == false)
    {
        ans++;
        M[find(i)] = true;
    }
    cout << ans << endl;
}

int main()
{
    Buff;
    cin >> t;
    while(t--)
        work();
    return 0;
}