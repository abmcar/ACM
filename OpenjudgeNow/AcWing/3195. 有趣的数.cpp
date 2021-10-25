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
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;

const ll Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

ll n;
ll C[Maxn][Maxn];
ll ans;

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    for (ll i = 0; i <= n; i++)
    for (ll j = 0; j <= i; j++)
        if (!j)
            C[i][j] = 1;
        else
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % Mod;
    for (ll k = 2; k <= n-2; k++)
        ans = (ans + C[n-1][k] * (k-1) * (n-k-1) % Mod) %Mod;
    cout << ans;
    return 0;
}