#include "bits/stdc++.h"

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug
#define int double

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n;
void work()
{
    cin >> n;
    map<int, int> M;
    vector<int> V(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> V[i], M[V[i]]++;
    int cnt = 1e9;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            double nowD = (V[j] - V[i]) * 1.0 / (j - i);
            int nowAns = n;
            for (int k = 1; k <= n; k++)
            {
                if (abs(V[k] - (V[i] + nowD * (k - i))) < 1e-2)
                    nowAns--;
                // cout << V[k] << " " << V[i]+nowD*(k-i) << " " << nowD << " " << nowAns << endl;
            }
            cnt = min(cnt, nowAns);
        }
    for (int i = 1; i <= n; i++)
        cnt = min(cnt,n-M[V[i]]);
    cout << cnt << endl;
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