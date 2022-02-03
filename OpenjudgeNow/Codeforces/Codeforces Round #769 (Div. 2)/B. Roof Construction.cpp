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
    cin >> n;
    int cnt = 1;
    while (cnt * 2 < n)
        cnt *= 2;
    for (int i = cnt-1; i >= 0; i--)
        cout << i << " ";
    for (int i = cnt; i < n; i++)
        cout << i << " \n"[i == n-1];
}

signed main()
{
    // for (int i = 1; i <= 10; i++)
    //     for (int j = 1; j <= 10; j++)
    //         cout << i << " " << j << " " << (i xor j) << endl;
    // vector<int> V = {2,3,4,5,1,6,7,0,8,9};
    // vector<int> V = {4,6,3,2,0,8,9,1,7,5};
    // for (int i = 0; i < V.size()-1; i++)
    //     cout << (V[i] xor V[i+1]) << endl;
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