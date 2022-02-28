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

int n, k, s, ans;
vector<int> targetRank;
vector<int> max1, max2;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> k >> s;
    targetRank.resize(n + 1);
    max1.resize(n + 1);
    max2.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> targetRank[i];
    for (int i = 1; i <= n; i++)
    {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        max1[i] = max(A, B);
        max2[i] = max({A, B, C, D});
    }
    array<int,5> AR;
    otfa
    for (int i = 1; i < (1 << n); i++)
    {
        // cout << i << " " << (1 << n) << endl;
        if (__builtin_popcount(i) != k)
            continue;
        vector<int> nowNum(n);
        for (int j = 0; j < n; j++)
            if ((1 << j) & i)
                nowNum[j] = max2[j + 1];
            else
                nowNum[j] = max1[j + 1];
        sort(nowNum.begin(), nowNum.end(), greater<int>());
        int nowRank = s;
        int Fun = 0;
        for (int j = 0; j < n; j++)
        {
            nowRank += nowNum[j];
            if (nowRank >= targetRank[j+1])
                Fun++;
        }
        ans = max(ans, Fun);
    }
    cout << ans << endl;
    return 0;
}