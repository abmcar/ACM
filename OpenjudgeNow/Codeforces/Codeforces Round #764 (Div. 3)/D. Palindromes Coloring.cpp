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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;

void work()
{
    map<int, int> oriN, aftN;
    cin >> n >> m;
    string oriS;
    cin >> oriS;
    for (char it : oriS)
        oriN[it]++;
    for (char i = 'a'; i <= 'z'; i++)
        aftN[i] = oriN[i] / 2;
    int tot1, tot2;
    tot1 = tot2 = 0;
    for (char i = 'a'; i <= 'z'; i++)
        tot1 += oriN[i] % 2;
    for (char i = 'a'; i <= 'z'; i++)
        tot2 += aftN[i];
    int ans = tot2 / m * 2;
    if (tot1 + tot2 % m * 2 >= m)
        ans++;
    // if (tot1 && (tot2 % m * 2 >= m))
    //     ans++;
    cout << ans << endl;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}