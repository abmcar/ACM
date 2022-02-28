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

int n, m, d, ds, ans;
unordered_map<string,bool> vis;
unordered_map<string, pair<int, int>> dis;
struct Product
{
    int price;
    vector<string> tags;
} product[Maxn];

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        product[i].tags.resize(m);
        cin >> product[i].price;
        for (int j = 0; j < m - 1; j++)
            cin >> product[i].tags[j];
    }
    cin >> d >> ds;
    for (int i = 1; i <= d; i++)
    {
        string dName;
        int type, amount;
        cin >> dName;
        cin >> type >> amount;
        vis[dName] = true;
        dis[dName] = {type, amount};
    }
    for (int i = 1; i <= n; i++)
    {
        int oriPrice = product[i].price;
        int nowAns = oriPrice;
        for (int j = 0; j < m - 1; j++)
        {
            if (product[i].tags[j] == "EMPTY")
                continue;
            if (!vis[product[i].tags[j]])
                continue;
            int nowType = dis[product[i].tags[j]].first;
            int nowAmount = dis[product[i].tags[j]].second;
            if (nowType == 0)
                nowAns = min(nowAns, nowAmount);
            if (nowType == 1)
                nowAns = min(nowAns, (oriPrice * (100 - nowAmount) + 50) / 100);
            if (nowType == 2)
                nowAns = min(nowAns, oriPrice - nowAmount);
        }
        ans += nowAns;
        // cout << nowAns << endl;
    }
    cout << ans << endl;
    return 0;
}