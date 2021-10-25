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
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const int Maxn = 1e5 + 10;
const ll Mod = 998244353;

int n, m;
map<int,map<int,int> > M[55];
int l[Maxn], r[Maxn];
ll ans;

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    for (int i = l[1]; i <= r[1]; i++)
        M[1][m-i][i]++;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= 1e5; j++)
        {
            for (auto it : M[i-1][j])
            {
                for (int k = l[i]; k <= r[i]; k++)
                {
                    int nowGcd = __gcd(k, it.first);
                    M[i][j-nowGcd][nowGcd] += it.second % Mod;
                }
            }
        }
    }
    for (int i = 1; i <= 1e5; i++)
    ans = (ans + M[n][i][1]) % Mod;
    cout << ans << endl;
    return 0;
}