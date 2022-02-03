#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

#define int long long
const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

int n;
int px[Maxn], py[Maxn];
int preX[Maxn], preY[Maxn];
int pre[3][3][Maxn];
int preA[3][3][3][3];

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> px[i] >> py[i];
        pre[abs(px[i]) % 2][abs(py[i]) % 2][i]++;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        pre[0][0][i] = pre[0][0][i - 1] + pre[0][0][i];
        pre[0][1][i] = pre[0][1][i - 1] + pre[0][1][i];
        pre[1][0][i] = pre[1][0][i - 1] + pre[1][0][i];
        pre[1][1][i] = pre[1][1][i - 1] + pre[1][1][i];
        int n1 = abs(px[i]) % 2;
        int n2 = abs(py[i]) % 2;

        ans += preA[n1][!n2][!n1][!n2];
        ans += preA[!n1][!n2][n1][!n2];
        ans += preA[n1][!n2][!n1][n2];

        ans += preA[!n1][n2][!n1][!n2];
        ans += preA[!n1][!n2][!n1][n2];
        ans += preA[!n1][n2][n1][!n2];
        // cout << i << "      " << ans << " " << preA[0][0][0][1] << endl;
        preA[0][0][n1][n2] += pre[0][0][i - 1];
        preA[0][1][n1][n2] += pre[0][1][i - 1];
        preA[1][0][n1][n2] += pre[1][0][i - 1];
        preA[1][1][n1][n2] += pre[1][1][i - 1];
    }
    cout << ans << endl;
    return 0;
}