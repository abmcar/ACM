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

const int Maxn = 1000000;
const ll Mod = 1e9 + 7;

int n, t, ans;
vector<int> fTime(Maxn);
vector<int> d1, d2;
string s;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> t;
    cin >> s;
    d1.resize(Maxn);
    d2.resize(Maxn);
    for (int i = 0; i < n; i++)
        cin >> fTime[i];
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B')
        {
            d1[fTime[i]]++;
            d1[fTime[i] + t]--;
        }
        else
        {
            d2[fTime[i]]++;
            d2[fTime[i] + t]--;
        }
    }
    int nowD1 = 0, nowD2 = 0;
    for (int i = 0; i < Maxn; i++)
    {
        nowD1 += d1[i];
        nowD2 += d2[i];
        if (nowD1 && nowD2 == 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}