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

double getDis(int x, int y)
{
    return sqrt(x * x + y * y);
}

void work()
{
    int nowX, nowY;
    string s;
    double ans = 0;
    nowX = nowY = 0;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'U')
            nowY++;
        if (s[i] == 'D')
            nowY--;
        if (s[i] == 'L')
            nowX--;
        if (s[i] == 'R')
            nowX++;
        ans = max(ans,getDis(nowX,nowY));
    }
    cout << fixed << setprecision(10) << ans << endl;
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