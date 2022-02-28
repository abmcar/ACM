#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define int long long
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 2e3 + 10;
const ll Mod = 1e9 + 7;

int n, s, k;
int tot;
string res[Maxn][Maxn];
vector<int> V[Maxn];
vector<pair<int, int>> ans[Maxn];

void init()
{
    cin >> n >> s;
    if (s != 0)
        tot = n / s;
    else
        tot = n;
    for (int i = 1; i <= tot; i++)
    {
        V[i].resize(s + 1);
        for (int j = 1; j <= s; j++)
            cin >> V[i][j];
    }
    for (int i = 1; i <= (s - 1) * n / 2; i++)
    {
        int t1, t2;
        string r;
        cin >> t1 >> t2 >> r;
        if (r == "W")
        {
            res[t1][t2] = "W";
            res[t2][t1] = "L";
        }
        else if (r == "L")
        {
            res[t2][t1] = "W";
            res[t1][t2] = "L";
        }
        else
            res[t1][t2] = res[t2][t1] = "T";
    }
    cin >> k;
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

void work()
{
    for (int i = 1; i <= tot; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            int cnt = 0;
            for (int k = 1; k <= s; k++)
            {
                if (j == k)
                    continue;
                if (res[V[i][j]][V[i][k]] == "W")
                    cnt += 3;
                else if (res[V[i][j]][V[i][k]] == "T")
                    cnt++;
            }
            ans[i].push_back({V[i][j], cnt});
        }
        if (s == 1)
            ans[i].push_back({V[i][1], 0});
        sort(ans[i].begin(), ans[i].end(), cmp);
        cout << ans[i][k - 1].first << " ";
    }
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    init();
    work();
    return 0;
}
