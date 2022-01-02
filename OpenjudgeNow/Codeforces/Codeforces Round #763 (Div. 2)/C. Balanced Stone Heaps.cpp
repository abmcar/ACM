#include "bits/stdc++.h"

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;
vector<int> h;

int t, n;

bool check(int x)
{
    vector<int> nowH(n + 1);
    nowH = h;
    for (int i = n; i >= 1; i--)
    {
        if (nowH[i] < x)
            return false;
        if (i < 3)
            continue;
        int nowMore = nowH[i] - x;
        int nowD = nowMore / 3;
        int oriMax = h[i]/3;
        nowD = min(oriMax,nowD);
        nowH[i] = nowH[i] - 3*nowD;
        nowH[i - 1] += nowD;
        nowH[i - 2] += 2 * nowD;
    }
    // for (int i = 1; i <= n; i++)
    //     cout << nowH[i] << " ";
    // cout << endl;
    return true;
}

void work()
{
    cin >> n;
    h.resize(n+1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    int l = 0;
    int r = h[n];
    int ans;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else
            r = mid - 1;
    }
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