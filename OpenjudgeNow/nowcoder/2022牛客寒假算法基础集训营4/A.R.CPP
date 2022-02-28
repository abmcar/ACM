#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug
#define int long long
using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int n, k, ans;
string s;
vector<int> preAns, preP;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> k;
    cin >> s;
    preAns.resize(n + 1, 0);
    preP.resize(n + 1, 0);
    for (int i = 0; i < n; i++)
        preAns[i + 1] = preAns[i] + (s[i] == 'R');
    for (int i = 0; i < n; i++)
        preP[i + 1] = preP[i] + (s[i] == 'P');
    // for (int i = 0; i < n; i++)
    //     cout << preAns[i + 1] << " \n"[i == (n - 1)];
    // for (int i = 0; i < n; i++)
    //     cout << preP[i + 1] << " \n"[i == (n - 1)];
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == 'P')
            continue;
        int nextPos = lower_bound(preAns.begin(), preAns.end(), preAns[i] + k) - preAns.begin();
        if (s[i - 1] == 'R')
            nextPos = lower_bound(preAns.begin(), preAns.end(), preAns[i] + k - 1) - preAns.begin();
        int nextEndPos = lower_bound(preP.begin(), preP.end(), preP[i] + 1) - preP.begin();
        if (nextPos == n + 1)
            break;
        // cout << i << " " << nextPos << " " << nextEndPos << endl;
        if (nextPos > nextEndPos)
            continue;
        ans += (nextEndPos - nextPos);
    }
    cout << ans << endl;
    return 0;
}