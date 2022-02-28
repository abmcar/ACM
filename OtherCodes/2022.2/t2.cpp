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

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

int n, order, ans;
int inventory[Maxn];
unordered_map<int, int> M;
priority_queue<pair<int, int>, vector<pair<int, int>>> Q;
signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> inventory[i];
        M[inventory[i]]++;
    }
    for (auto it : M)
        Q.push(it);
    cin >> order;
    while (order)
    {
        int nowAmount = Q.top().second;
        int nowTop = Q.top().first;
        Q.pop();
        // cout << nowAmount << " " << nowTop << " " << ans << " " << order << endl;
        int costAmount = min(order, nowAmount);
        ans += nowTop * costAmount;
        order -= costAmount;
        if (Q.empty())
            break;
        if (Q.top().first == nowTop - 1)
        {
            auto nexTop = Q.top();
            Q.pop();
            nexTop.second += nowAmount;
            Q.push(nexTop);
        }
        else
        {
            Q.push({nowTop - 1, nowAmount});
        }
    }
    cout << ans << endl;
    return 0;
}