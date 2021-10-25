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
  
const int Maxn = 1234;
const ll Mod = 1e9+7;
 
ll n,x;
ll nowused;
ll now;
struct Node
{
    ll a,b;
    bool const operator < (Node c) const
    {
        return b > c.b;
    }
}node[Maxn];
  
int main()
{
    Buff;
    cin >> n >> x;
    for(ll i = 1; i <= n; i++)
        cin >> node[i].a >> node[i].b;
    sort(node+1,node+1+n);
    for(ll i = 1; i < n; i++)
    {
        if(node[i].a == 0)
            continue;
        for(ll j = 1; j <= n; j++)
        {
            if(i == j)
                continue;
            if(node[j].a == 0 || node[i].a == 0)
                continue;
            // cout << node[i].a << " " << node[i].b << endl << node[j].a << " " << node[j].b << " " << nowused << endl;
            if((node[i].b+node[j].b)*min(node[i].a,node[j].a) >= x)
            {
                ll temp = x / ((node[i].b+node[j].b));
                // cout << temp << endl;
                if(temp * (node[i].b+node[j].b) == x)
                {
                    ll ans = nowused + temp*2;
                    cout << ans;
                    return 0;
                }else
                {
                    if(x - temp * (node[i].b+node[j].b) > node[i].b)
                        nowused++;
                    ll ans = nowused + temp*2 + 1;
                    cout << ans;
                    return 0;
                }
            }else
            {
                ll less = min(node[i].a,node[j].a);
                node[i].a -= less;
                node[j].a -= less;
                nowused += less*2;
                x = x - (node[i].b+node[j].b)*less;
            }
        }
    }
    cout << "-1";
    return 0;
}