#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
// #define endl "\n"
// #define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n;

int query(int pos)
{
    cout << "? " << pos << " " << pos + 1 << " " << pos + 2 << endl;
    int tar;
    cin >> tar;
    return tar;
}

int query(int pos, int p1, int p2)
{
    cout << "? " << pos << " " << p1 << " " << p2 << endl;
    int tar;
    cin >> tar;
    return tar;
}

void work()
{
    cin >> n;
    vector<int> nums(n + 1);
    vector<int> qAns(n + 1);
    vector<int> ans(n + 1);
    for (int i = 1; i + 2 <= n; i++)
        qAns[i] = query(i);
    int p1, p2, p3;
    p1 = p2 = p3 = -1;
    for (int i = 1; i + 3 <= n; i++)
        if (qAns[i] != qAns[i + 1])
        {
            if (p1 == -1)
                p1 = i + 1;
        }
    for (int i = 1; i <= n; i++)
    {
        if (i == p1 || i == p1 + 1)
            continue;
        ans[i] = query(i, p1, p1 + 1);
    }
    for (int i = 1; i + 1 <= n; i++)
    {
        if (i == p1 || i == p1 + 1)
            continue;
        if (ans[i] == 0)
            p2 = i;
        else
            p3 = i;
    }
    ans[p1] = query(p1, p2, p3);
    ans[p1 + 1] = query(p1 + 1, p2, p3);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += ans[i];
    cout << "! " << n - cnt << " ";
    for (int i = 1; i <= n; i++)
        if (ans[i] == 0)
            cout << i << " ";
    cout << endl;
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
