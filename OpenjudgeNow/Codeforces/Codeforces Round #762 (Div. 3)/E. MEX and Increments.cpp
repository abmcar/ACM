#include "bits/stdc++.h"

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

int t, n;

void work()
{
    cin >> n;
    unordered_map<int, int> M;
    vector<int> V(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> V[i], M[V[i]]++;
    priority_queue<int> Q;
    vector<int> ans(n + 1, -1);
    int cnt = 0;
    for (int i = 0; i <= n; i++)
    {
        ans[i] = cnt + M[i];
        while (M[i]--)
            Q.push(i);
        if (!Q.empty())
        {
            cnt += i - Q.top();
            Q.pop();
        }
        else
            break;
    }
    for (int i = 0; i <= n; i++)
        cout << ans[i] << " ";
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

/*
5
3
0 1 3
7
0 1 2 3 4 3 2
4
3 0 0 0
7
4 6 2 3 5 0 5
5
4 0 1 0 4
 */