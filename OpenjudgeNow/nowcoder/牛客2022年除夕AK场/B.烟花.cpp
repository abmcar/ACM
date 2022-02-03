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

int n;

char bd[666][666];

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n * 2 + 1; i++)
        for (int j = 1; j <= n * 2 + 1; j++)
            bd[i][j] = ' ';
    for (int i = 1; i <= n * 2 + 1; i++)
        bd[i][i] = '\\';
    for (int i = 1; i <= n * 2 + 1; i++)
        bd[i][n * 2 + 1 - i+1] = '/';
    for (int i = 1; i <= n * 2 + 1; i++)
        bd[n + 1][i] = '-';
    for (int i = 1; i <= n * 2 + 1; i++)
        bd[i][n + 1] = '|';
    bd[n + 1][n + 1] = 'O';
    for (int i = 1; i <= n * 2 + 1; i++)
    {
        for (int j = 1; j <= n * 2 + 1; j++)
            cout << bd[i][j];
        cout << Endl;
    }
    return 0;
}