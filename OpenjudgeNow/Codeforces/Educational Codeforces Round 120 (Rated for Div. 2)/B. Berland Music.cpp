#include "bits/stdc++.h"

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n;

struct Node
{
    int pos, val;
    bool operator<(Node b)
    {
        return val < b.val;
    }
};

void work()
{
    cin >> n;
    vector<int> rat(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> rat[i];
    String s;
    cin >> s;
    vector<Node> dislike, like;
    for (int i = 0; i < n; i++)
        if (s[i] == '0')
            dislike.push_back({i + 1, rat[i + 1]});
        else
            like.push_back({i + 1, rat[i + 1]});
    vector<int> ans(n + 1);
    sort(dislike.begin(), dislike.end());
    sort(like.begin(), like.end());
    for (int i = 0; i < dislike.size(); i++)
        ans[dislike[i].pos] = i + 1;
    for (int i = 0; i < like.size(); i++)
        ans[like[i].pos] = dislike.size() + i + 1;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
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