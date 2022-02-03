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

const int Maxn = 1e6 + 10;
const ll Mod = 1e9 + 7;

int n, q;
int tarPos[Maxn];
vector<int> nums(Maxn);
vector<int> ans(Maxn);
string s;
ll tot;

ll quickPow(ll base, ll x)
{
    ll now = 1;
    while (x)
    {
        if (x % 2)
            now = now * base % Mod;
        base = base * base % Mod;
        x = x / 2;
    }
    return now % Mod;
}

ll inverse(ll num)
{
    return quickPow(num, Mod - 2) % Mod;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> q;
    cin >> s;
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    int cnt = 0;
    int pos = 2;
    ans[cnt] = nums[1];
    for (char it : s)
    {
        if (it == '+')
        {
            tarPos[pos] = ++cnt;
            ans[cnt] = nums[pos++];
            continue;
        }
        else
        {
            tarPos[pos] = cnt;
            ans[cnt] = ans[cnt] * nums[pos++] % Mod;
        }
    }
    for (int i = 0; i <= cnt; i++)
        tot = (tot + ans[i]) % Mod;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        tot = tot - ans[tarPos[x]];
        ans[tarPos[x]] = ans[tarPos[x]] * inverse(nums[x]) % Mod;
        ans[tarPos[x]] = ans[tarPos[x]] * y % Mod;
        nums[x] = y;
        tot = (tot + ans[tarPos[x]] + Mod) % Mod;
        cout << tot << endl;
    }
    return 0;
}