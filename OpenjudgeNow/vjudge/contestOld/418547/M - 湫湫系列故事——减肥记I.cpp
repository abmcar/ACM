#include <iostream>
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
ll n,m;
ll v[Maxn],w[Maxn];
ll f[Maxn];

void work()
{
    // memset(f,0,sizeof(f));
    for(int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    cin >> m;
    for(int i = 1; i <= m; i++)
        f[i] = 0;
    for(int i = 1; i <= n; i++)
    for(int j = v[i]; j <= m; j++)
        f[j] = max(f[j],f[j-v[i]]+w[i]);
    cout << f[m] << endl;
}

int main()
{
    Buff;
    while(cin >> n)
        work();
    return 0;
}