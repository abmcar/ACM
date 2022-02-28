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

const int Maxn = 2e6 + 10;
const ll Mod = 1e9 + 7;

int n, k, w, q, ans;
string oriS;
vector<int> days;
int nextP[Maxn];

signed main()
{
    // Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    cin >> oriS;
    for (int i = 0; i < oriS.size(); i++)
        if (oriS[i] == '0')
            days.push_back(i);
    cin >> k >> w >> q;
    for (int i = 0; i < days.size(); i++)
    {
        int nowAns = 0;
        int prePos = lower_bound(days.begin(), days.end(), days[i] - k) - days.begin();
        if (prePos == i)
            prePos--;
        if (prePos > 0)
            if (abs(k - abs(days[prePos] - days[i])) > abs(k - abs(days[prePos - 1] - days[i])))
                prePos--;
        if (prePos < i && prePos >= 0)
        {
            nowAns = w - abs(k - abs(days[prePos] - days[i])) * q;
            ans = max(ans, nowAns);
        }
        int aftPos = lower_bound(days.begin(), days.end(), days[i] + k) - days.begin();
        if (aftPos == i)
            aftPos++;
        if (aftPos >= days.size())
            aftPos = days.size() - 1;
        if (aftPos > 0)
            if (abs(k - abs(days[aftPos] - days[i])) > abs(k - abs(days[aftPos - 1] - days[i])))
                aftPos--;
        if (aftPos > i && aftPos < days.size() && aftPos >= 0)
        {
            int tAns = nowAns;
            nowAns = w - abs(k - abs(days[aftPos] - days[i])) * q;
            ans = max(ans, nowAns);
            tAns += nowAns;
            ans = max(ans, tAns);
        }
    }
    cout << ans << endl;
    return 0;
}