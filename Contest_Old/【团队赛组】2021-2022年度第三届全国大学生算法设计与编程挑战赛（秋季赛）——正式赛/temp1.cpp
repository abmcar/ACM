#include <bits/stdc++.h>
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 5e3 + 10;
const ll Mod = 1e9 + 7;

// map<int,char> temps[Maxn];

char temps[Maxn][Maxn];
char a[Maxn][Maxn];
const int add = 20;
int n = 70 + add, m = 70 + add;

bool testin(int x, int y, int stx, int sty, int edx, int edy)
{
    if (stx <= x)
        if (x <= edx)
            if (sty <= y)
                if (y <= edy)
                    return true;
    return false;
}

char solve(ll y, ll x)
{
    if (x <= 31 && y <= 15)
        return a[y + add][x + add];
    for (ll i = 5; i <= 60; i++)
    {
        ll len = (1ll << i);
        if (x < (1ll << i) && y < (1ll << (i - 1)))
        {
            ll stx = 0, sty = 0;
            ll edx = len / 2 - 1, edy = len / 4 - 1;
            if (testin(x, y, stx, sty, edx, edy))
                return solve(y - sty, x - stx);
            stx = len / 2, sty = 0;
            edx = len - 1, edy = len / 4 - 1;
            if (testin(x, y, stx, sty, edx, edy))
                return solve(y - sty, x - stx);
            stx = len / 4, sty = len / 4;
            edx = len / 4 + len / 2 - 1, edy = len / 2 - 1;
            if (testin(x, y, stx, sty, edx, edy))
                return solve(y - sty, x - stx);
            return '.';
        }
    }
}

bool check1(int i, int j, bool flag)
{
    if (i >= 1 && j >= 2)
        if (!a[i - 1][j - 1] && a[i][j - 2] && a[i][j - 2] != flag)
            return true;
    return false;
}

bool check2(int i, int j, bool flag)
{
    if (i >= 1 && j >= 2)
        if (!a[i][j - 2] && a[i - 1][j - 1] && a[i - 1][j - 1] != flag)
            return true;
    return false;
}
void preWork()
{
    a[add][add] = 'A';
    for (int t = 2; t <= 32; t++)
    {
        int flag = 'A';
        if (!(t & 1))
        {
            flag = 'B';
        }
        for (int i = 0; i <= n + add; i++)
        {
            for (int j = 0; j <= m + add; j++)
            {
                if (check1(i, j, flag))
                    a[i][j] = flag;
                if (check2(i, j, flag))
                    a[i][j] = flag;
            }
        }
    }
    for (int i = 0; i <= n + add; i++)
        for (int j = 0; j <= m + add; j++)
        {
            check1(i, j, 1);
            if (!a[i][j])
                a[i][j] = '.';
            check2(i, j, 1);
        }
}

int matestin()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    preWork();
    ll t, x0, y0, a, b;
    while (cin >> t >> x0 >> y0 >> a >> b)
    {
        memset(temps, 0, sizeof temps);
        for (ll y = 0; y < b; y++)
        {
            for (ll x = 0; x < a; x++)
            {
                temps[y][x] = solve(y + y0, x + x0);
                if (temps[y][x] != '.' && (y + y0 + x + x0) / 2 >= t)
                    temps[y][x] = '.';
            }
        }
        for (int i = b - 1; i >= 0; i--)
            cout << temps[i] << endl;
    }

    return 0;
}