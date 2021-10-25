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
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 5e3 + 10;
const ll Mod = 1e9 + 7;

int n, m;
ll num[Maxn];
ll ans[Maxn][Maxn];

int main()
{
    Buff;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    for (int k = 1; k <= n; k++)
    for (int i = 1; i+k <= n; i++)
    {
        int j = i + k;
        ans[i][j] = max(ans[i][j], ans[i][j-1]);
        ans[i][j] = max(ans[i][j], ans[i+1][j]);
        ans[i][j] = max(ans[i][j], num[i] xor num[j]);
    }
    for (int i = 1; i <= m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        cout << ans[t1][t2] << endl;
    }
    return 0;
}