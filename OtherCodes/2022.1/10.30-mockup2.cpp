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

const int Maxn = 1e6 + 10;
const ll Mod = 1e9 + 7;

int n, t;
queue<int> targets[Maxn];
int ans[Maxn];

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        targets[i].push(temp);
    }
    while (t--)
    {
        vector<int> unp[Maxn];
        for (int i = 1; i <= n; i++)
        {
            if (targets[i].empty())
                continue;
            ans[i] = targets[i].front();
            targets[i].pop();
            unp[ans[i]].push_back(i);
        }
        for (int i = 1; i <= n; i++)
            for (int it : unp[i])
                targets[i].push(it);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}