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

int t, n, m;

void work()
{
    cin >> n;
    vector<int> na(n), nb(n);
    vector<pair<int, int>> nd(n);
    for (int i = 0; i < n; i++)
        cin >> na[i];
    for (int i = 0; i < n; i++)
        cin >> nb[i];
    unordered_map<int, int> dp[n];
    dp[0][na[0]] = na[0] - nb[0];
    dp[0][nb[0]] = nb[0] - na[0];
    for (int i = 1; i < n; i++)
    {
        for (auto it : dp[i - 1])
        {
            dp[i][it.first + na[i]] = 1e15;
            dp[i][it.first + nb[i]] = 1e15;
        }
        for (auto it : dp[i - 1])
        {
            dp[i][it.first + na[i]] = min(dp[i][it.first + na[i]], it.second + na[i] - nb[i]);
            dp[i][it.first + nb[i]] = min(dp[i][it.first + nb[i]], it.second + nb[i] - na[i]);
        }
    }
    int d = 1e15;
    int totA, totB;
    for (auto it : dp[n - 1])
    {
        if (abs(it.second) < d)
        {
            d = abs(it.second);
            totA = it.first;
            totB = it.first - it.second;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += na[i] * na[i] + nb[i] * nb[i];
    ans *= (n - 2);
    ans += totA * totA + totB * totB;
    cout << ans << endl;
    // for (int i = 0; i < n; i++)
    //     nd[i] = {abs(na[i] - nb[i]), i};
    // sort(nd.begin(), nd.end(), greater<pair<int, int>>());
    // totA = totB = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << nd[i].first << endl;
    //     if (totA >= totB)
    //     {
    //         totB += nd[i].first;
    //         int nowPos = nd[i].second;
    //         if (na[nowPos] > nb[nowPos])
    //             swap(na[nowPos], nb[nowPos]);
    //         // pos[nd[i].second] = 1;
    //     }
    //     else
    //     {
    //         totA += nd[i].first;
    //         int nowPos = nd[i].second;
    //         if (na[nowPos] < nb[nowPos])
    //             swap(na[nowPos], nb[nowPos]);
    //         // pos[nd[i].second] = 0;
    //     }
    // }
    // totA = totB = 0;
    // for (int i = 0; i < n; i++)
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         totA += (na[i] + na[j]) * (na[i] + na[j]);
    //         totB += (nb[i] + nb[j]) * (nb[i] + nb[j]);
    //     }
    // cout << totA + totB << Endl;
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