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
const double esp = 1e-6;

double n, X0, Y0, x, y;
double ans = 1e9;

double getDis(int nowX, int nowY)
{
    return sqrt((nowX - x) * (nowX - x) + (nowY - y) * (nowY - y));
}

struct point
{
    double x, y;
};

struct line
{
    point st, ed;
    double k, b;
};

int sign(double x)
{
    if (fabs(x) < esp)
        return 0;
    return x > 0 ? 1 : -1;
}

double dis(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double cmult(point a, point b, point c)
{
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

double pmult(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

double pldis(point a, line l)
{
    point s1, s2, s3;
    s1.x = l.ed.x - l.st.x, s1.y = l.ed.y - l.st.y;
    s2.x = a.x - l.st.x, s2.y = a.y - l.st.y;
    s3.x = a.x - l.ed.x, s3.y = a.y - l.ed.y;
    if (l.st.x == l.ed.x && l.st.y == l.ed.y)
        return dis(a, l.st);
    if (sign(pmult(s1, s2)) < 0)
        return dis(a, l.st);
    else if (sign(pmult(s1, s3)) > 0)
        return dis(a, l.ed);
    else
        return fabs(cmult(l.st, a, l.ed)) / dis(l.st, l.ed);
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> X0 >> Y0 >> x >> y;
    ans = getDis(X0, Y0);
    point targetPoint{x, y};
    for (int i = 1; i <= n; i++)
    {
        point p1, p2;
        p1 = {X0, Y0};
        int nx, ny;
        cin >> nx >> ny;
        X0 += nx;
        Y0 += ny;
        p2 = {X0, Y0};
        ans = min(pldis(targetPoint, {p1, p2}), ans);
    }
    cout << fixed << setprecision(8) << ans << endl;
    return 0;
}