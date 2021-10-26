#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 55;
const int mod = 1000000007;

mt19937 mrand(random_device{}());
ll qpow(ll B, ll E)
{
    ll A = 1;
    for (; E; E >>= 1, B = B * B % mod)
        E & 1 ? A = A * B % mod : 0;
    return A;
}
char s[N];
struct Point
{
    ll x, y, t;
    Point(ll x = 0, ll y = 0) : x(x), y(y) {}
    void r(int tt)
    {
        cin >> x >> y;
        t = tt;
    }
} a[N], b[N];
inline bool operator<(Point a, Point b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
inline bool operator==(Point a, Point b) { return (a.x - b.x) == 0 && (a.y - b.y) == 0; }

typedef Point Vector;
inline Vector operator-(Point A, Point B) { return Vector(A.x - B.x, A.y - B.y); }

inline ll Cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; } //A x B > 0表示A在B的顺时针方向上

vector<Point> ConvexHull(vector<Point> p)
{
    sort(p.begin(), p.end());
    int n = p.size();
    int m = 0;
    vector<Point> ch(n + 1);
    for (int i = 0; i < n; i++)
    {
        while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)
            m--;
        ch[m++] = p[i];
    }
    int k = m;
    for (int i = n - 2; i >= 0; i--)
    {
        while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)
            m--;
        ch[m++] = p[i];
    }
    if (n > 1)
        m--;
    ch.resize(m);
    return ch;
}

int solve(vector<Point> v)
{
    vector<Point> f = ConvexHull(v);
    if (f.size() == 4 && f[0].t == f[2].t)
        return 1;
    return 0;
}
int main()
{
    int n, m, t;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        a[i].r(1);

    for (int i = 1; i <= m; i++)
        b[i].r(2);
    random_shuffle(a + 1, a + 1 + n);
    random_shuffle(b + 1, b + 1 + n);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int f = 1; f <= m; f++)
            {
                for (int h = f + 1; h <= m; h++)
                {
                    cnt++;
                    if (solve({a[i], a[j], b[h], b[f]}))
                    {
                        puts("YES");
                        return 0;
                    }
                    if (cnt == 2000000)
                    {
                        puts("NO");
                        return 0;
                    }
                }
            }
        }
    }
    puts("NO");
    return 0;
}
