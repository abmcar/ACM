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
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n;

void work()
{
    cin >> n;
    if (n % 2 == 0)
    {
        cout << n / 2 << " " << n / 2 - 1 << " " << 1 << endl;
    }
    else
    {
        int nowNum = n / 2;
        if (nowNum % 2)
            cout << nowNum - 2 << " " << nowNum + 2 << " " << 1 << endl;
        else
            cout << nowNum - 1 << " " << nowNum + 1 << " " << 1 << endl;
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