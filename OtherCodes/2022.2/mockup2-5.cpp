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

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

int n, ans;
int r[Maxn];
int nT[Maxn];
vector<int> g[Maxn];
unordered_map<int, int> val;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

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
        cin >> val[i] >> r[i];
        for (int j = 0; j < r[i]; j++)
        {
            int temp;
            cin >> temp;
            g[temp].push_back(i);
        }
        if (r[i] == 0)
            Q.push((pair<int, int>){0, i});
    }
    while (Q.size())
    {
        pair<int, int> nowNode = Q.top();
        Q.pop();

        // cout << nowNode.first << " " << nowNode.second << endl;
        ans = max(ans, nowNode.first + val[nowNode.second]);
        for (int i = 0; i < g[nowNode.second].size(); i++)
        {
            int nextNode = g[nowNode.second][i];
            int nextTime = max(nT[nextNode], nowNode.first + val[nowNode.second]);
            nT[nextNode] = nextTime;
            r[nextNode]--;
            if (r[nextNode] == 0)
                Q.push((pair<int, int>){nextTime, nextNode});
        }
    }
    cout << ans << endl;
    return 0;
}