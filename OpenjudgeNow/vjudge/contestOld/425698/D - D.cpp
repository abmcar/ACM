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

const int Maxn = 233;
const ll Mod = 1e9+7;

int n,m;
int a[Maxn][Maxn];
int f[Maxn][Maxn];

int main()
{
    Buff;
    while(cin >> n >> m)
    {
        int ans = 0;
        if(n == 0 && m == 0)
            break;
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
        for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            f[i][j] = 0;
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        for(int k = m; k >= j; k--)
            f[i][k] = max(max(f[i][k],f[i-1][k]),f[i-1][k-j]+a[i][j]);
        for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            ans = max(ans,f[i][j]);
        cout << ans << endl;
    }
    return 0;
}