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

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;

int n,m,ans;
int father[Maxn];

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
    while(cin >> n)
    {
        ans = 0;
        if(n == 0)
            return 0;
        cin >> m;
        for(int i = 1; i <= n; i++)
            father[i] = i;
        for(int i = 1; i <= m; i++)
        {
            int ta,tb;
            cin >> ta >> tb;
            father[find(ta)] = find(tb);
        }
        for(int i = 1; i <= n; i++)
            if(find(i) == i)
                ans++;
        cout << ans-1 << "\n";
    }
    return 0;
}