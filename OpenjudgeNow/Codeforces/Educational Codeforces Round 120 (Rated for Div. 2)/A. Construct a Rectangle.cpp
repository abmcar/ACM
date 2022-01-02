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

int t;
int num[4];

void work()
{
    cin >> num[1] >> num[2] >> num[3];

    if (num[1] + num[2] == num[3] || num[1] + num[3] == num[2] || num[2] + num[3] == num[1])
        cout << "Yes" << Endl;
    else if ((num[1] == num[2] && num[3] % 2 == 0) || (num[1] == num[3] && num[2] % 2 == 0) || (num[2] == num[3] && num[1] % 2 == 0))
        cout << "Yes" << Endl;
    else
        cout << "NO" << endl;
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