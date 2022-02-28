#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug
#define int long long
using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;
bool re;

vector<int> ax, ay;

void pt(int x, int y)
{
    if (re)
    {
        ax.push_back(y);
        ay.push_back(x);
    }
    else
    {
        ax.push_back(x);
        ay.push_back(y);
    }
}

void work()
{
    cin >> n >> m;
    if (n > m)
    {
        swap(n, m);
        re = true;
    }
    if (n + 2 >= m)
    {
        cout << "NO" << endl;
        return;
    }
    // else
    //     cout << "YES" << endl;
    int bg = (n + 2);
    while ((m - bg) % 11)
        bg--;
    // cout << bg << endl;
    if (bg >= 11)
    {
        n = n - (bg - 2);
        m = m - bg;
        pt(bg - 2, bg);
    }
    if (m % 11)
    {
        cout << "NO" << endl;
        return;
    }
    else
        cout << "YES" << endl;
    while (m)
    {
        int t1 = min(n, 9LL);
        n = n - t1;
        m = m - 11;
        cout << n << " " << m << endl;
        pt(t1, 11);
    }
    cout << ax.size() << endl;
    for (int i = 0; i < ax.size(); i++)
        cout << ax[i] << " " << ay[i] << endl;
    ax.clear();
    ay.clear();
}

signed main()
{
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