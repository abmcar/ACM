#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
// #define endl "\n"
// #define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

int t, n, m, start, base_move_count;

vector<int> g[Maxn];

void work()
{
    srand(1919810);
    cin >> n >> m >> start >> base_move_count;
    for (int i = 1; i <= m; ++i)
    {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    string s;
    while (cin >> s)
    {
        if (s == "AC")
            return;
        int cnt;
        cin >> cnt;
        vector<pair<int, int>> nums;
        int totAns = 0;
        for (int i = 1; i <= cnt; i++)
        {
            int nowD, flag;
            cin >> nowD >> flag;
            if (flag == 0)
            {
                nums.push_back({nowD, i});
                totAns += nowD;
            }
        }
        if (nums.size() == 0)
        {
            int nextPos = rand() % cnt + 1;
            cout << nextPos << endl;
        }
        else
        {
            cout << nums[0].second << endl;
        }
    }
}

signed main()
{
    // Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}