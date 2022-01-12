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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;

void work()
{
    vector<int> V(8);
    map<int, int> M;
    for (int i = 1; i <= 7; i++)
        cin >> V[i], M[V[i]]++;
    for (int i = 1; i <= 7; i++)
        for (int j = i + 1; j <= 7; j++)
            for (int k = j + 1; k <= 7; k++)
            {
                map<int, int> t;
                t[V[i]]++;
                t[V[j]]++;
                t[V[k]]++;
                t[V[i] + V[j]]++;
                t[V[i] + V[k]]++;
                t[V[k] + V[j]]++;
                t[V[i] + V[k] + V[j]]++;
                bool ok = true;
                for (auto it : t)
                    if (M[it.first] != it.second)
                        ok = false;
                if (ok)
                {
                    cout << V[i] << " " << V[j] << " " << V[k] << endl;
                    return;
                } 
            }
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