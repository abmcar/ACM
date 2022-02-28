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
const ll Mod = 998244353;

int t, n, m, ans;

ll quick_pow(ll base, ll x)
{
    ll nowNum = 1;
    while (x)
    {
        if (x % 2)
            nowNum = nowNum * base % Mod;
        x = x / 2;
        base = base * base % Mod;
    }
    return nowNum;
}

void work()
{
    ans = 1;
    cin >> n;
    vector<int> nums(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    vector<pair<int, int>> V;
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            cnt++;
        }
        else
        {
            V.push_back({nums[i - 1], cnt + 1});
            cnt = 0;
        }
    }
    V.push_back({nums[n], cnt + 1});
    unordered_map<int, bool> used;
    cnt = 0;
    for (int i = 1; i < V.size(); i++)
    {
        if (V[i] > V[i - 1])
        {
            cnt += V[i].second;
            used[i] = true;
        }
        else
        {
            used[i - 1] = false;
            cnt = max(0LL, cnt - V[i - 1].second);
            ans = ans * quick_pow(2, cnt) % Mod;
            cnt = 0;
        }
    }
    ans = ans * quick_pow(2, max(0LL, cnt - V.back().second)) % Mod;
    cnt = 0;
    for (int i = 1; i < V.size(); i++)
    {
        if (V[i] < V[i - 1])
        {
            cnt += V[i].second;
            used[i] = true;
        }
        else
        {
            used[i - 1] = false;
            cnt = max(0LL, cnt - V[i - 1].second);
            ans = ans * quick_pow(2, cnt) % Mod;
            cnt = 0;
        }
    }
    ans = ans * quick_pow(2, max(0LL, cnt - V.back().second)) % Mod;
    cnt = 0;
    used[V.size() - 1] = false;
    for (int i = 0; i < V.size(); i++)
    {
        if (i == 0 || i == V.size() - 1)
        {
            ans = ans * (quick_pow(2, V[i].second) + Mod - 1) % Mod;
            continue;
        }
        if ((V[i] > V[i - 1] && V[i] > V[i + 1]) || (V[i] < V[i - 1] && V[i] < V[i + 1]))
            ans = ans * (quick_pow(2, V[i].second) + Mod - 1) % Mod;
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