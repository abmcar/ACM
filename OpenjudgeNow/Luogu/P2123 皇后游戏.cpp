#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
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

struct Node
{
    ll a,b,d;
    bool const operator< (Node c) const
    {
        if(d != c.d)
            return d < c.d;
        if(d <= 0)
            return a < c.a;
        return b > c.b;
    }
}node[Maxn];
int n;

int main()
{
    Buff;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> node[i].a >> node[i].b;
            if(node[i].a > node[i].b)
                node[i].d = 1;
            else
            if(node[i].a < node[i].b)
                node[i].d = -1;
            else
                node[i].d = 0;
        }
        sort(node+1,node+1+n);
        ll ans = node[1].a + node[1].b;
        ll preans = node[1].a;
        for(int i = 2; i <= n; i++)
        {
            preans += node[i].a;
            ans = max(preans,ans) + node[i].b;
        }
        cout << ans << endl;
    }
    return 0;
}
/*
cn = max(cn-1+bn-1,a1+a2+...+an+bn);
a1 b1 
a2 b2

c2 = max(a1+b1+b2,a1+a2+b2) (b1,a2)
c1 = max(a2+b2+b1,a1+a2+b1) (b2,a1)



*/