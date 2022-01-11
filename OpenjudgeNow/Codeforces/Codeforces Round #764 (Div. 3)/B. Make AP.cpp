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
    ll a, b, c;
    cin >> a >> b >> c;
    if (c-b == b-a)
    {
        cout << "YES" << endl;
        return;
    }
    int nowDC = b - a;
    int targetC = b + nowDC;
    if (((targetC - c) % c == 0) && (targetC - c) / c > 0)
    {
        // cout << "1" << endl;
        cout << "YES" << endl;
        return;
    }
    int nowDB = (c - a) / 2;
    if ((c - a) % 2 == 0)
    {
        int targetB = a + nowDB;
        if (((targetB - b) % b == 0) && (targetB - b) / b > 0)
        {
            // cout << "2" << endl;
            cout << "YES" << endl;
            return;
        }
    }
    int nowDA = c - b;
    int targetA = b - nowDA;
    if (((targetA - a) % a == 0) && (targetA - a) / a > 0)
    {
        // cout << "3" << endl;
        cout << "YES" << endl;
        return;
    }
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