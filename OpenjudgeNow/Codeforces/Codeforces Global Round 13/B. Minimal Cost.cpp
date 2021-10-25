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
int t,n;
ll u,v;


void work()
{
    cin >> n >> u >> v;
    int now,pre;
    int maxn = 0;
    pre = -100;
    cin >> pre;
    for(int i = 2; i <= n; i++)
    {
        cin >> now;
        maxn = max(maxn,abs(now-pre));
        pre = now;
    }
    ll ans;
    if(maxn == 0)
        ans = min(u+v,v+v);
    if(maxn == 1)
        ans = min(u,v);
    if(maxn > 1)
        ans = 0;
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