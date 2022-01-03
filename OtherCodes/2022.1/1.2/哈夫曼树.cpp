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

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n;
    while (cin >> n)
    {
        priority_queue<int, vector<int>, greater<int>> Q;
        for (int i = 1; i <= n; i++)
        {
            int temp;
            cin >> temp;
            Q.push(temp);
        }
        int ans = 0;
        while (Q.size() > 1)
        {
            int a = Q.top();
            Q.pop();
            int b = Q.top();
            Q.pop();
            ans += a + b;
            Q.push(a + b);
        }
        cout << ans << endl;
    }
    return 0;
}