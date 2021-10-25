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

const int Maxn = 1e5+10;
const ll Mod = 1e9+7;

int n;
int father[Maxn];
int rk[Maxn];
int p[Maxn];
int ans;

int find(int son)
{
    if(father[son] == son)
        return son;
    int temp = find(father[son]);
    rk[son] = rk[father[son]] + 1;
    return temp;
}

int main()
{
    Buff;
    cin >> n;
    for(int i = 1; i <= n; i++)
        father[i] = i;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    for(int i = 1; i <= n; i++)
    {
        if(p[i] == -1)
            continue;
        father[i] = p[i];
    }
    for(int i = 1; i <= n; i++)
    {
        find(i);
        ans = max(ans,rk[i]);
    }
    cout << ans+1;
    return 0;
}