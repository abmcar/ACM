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

int n;
int a[Maxn],t[Maxn];
int f[Maxn];
int tt;

struct Node
{
    int t1,t2;
    bool const operator < (const Node b) const
    {
        return t1 < b.t1;
    }
}node[Maxn];

void work()
{
    if(n == 0)
    {
        cout << 0 << endl;
        return;
    }
    int maxn = 0;
    int tot = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> node[i].t2 >> node[i].t1;
        maxn = max(maxn,node[i].t1);
        tot += node[i].t2;
    }
    sort(node+1,node+1+n);
    for(int i = 1; i <= n; i++)
    {
        t[i] = node[i].t1;
        a[i] = node[i].t2;
    }
    for(int i = 0; i <= maxn; i++)
        f[i] = 0;
    for(int i = 1; i <= n; i++)
    for(int j = t[i]; j >= 1; j--)
        f[j] = max(f[j],f[j-1] + a[i]);
    int minn = 0;
    // cout << "test:" << f[3] << endl;
    for(int i = 1; i <= maxn; i++)
        minn = max(minn,f[i]);
    cout << minn << endl;
}

int main()
{
    Buff;
    while(cin >> n)
        work();
    return 0;
}