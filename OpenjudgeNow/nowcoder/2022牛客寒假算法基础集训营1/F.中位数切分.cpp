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
int nums[Maxn], preAns[Maxn];
bool isOk[Maxn];

int getNum(int l, int r)
{
    return preAns[r] - preAns[l - 1];
}

int getSize(int l, int r)
{
    return r - l + 1;
}

bool check(int l, int r)
{
    if (getNum(l, r) * 2 <= getSize(l, r))
        return false;
    return true;
}

int fun(int l, int r)
{
    if (!check(l, r))
        return -1;
    int ex = 0;
    for (int i = l; i < r; i++)
    {
        if (check(l, i) && check(i + 1, r))
        {
            ex += fun(l, i) + fun(i + 1, r);
            break;
        }
    }
    if (!ex)
        return 1;
    return ex;
}

void work()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        isOk[i] = nums[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        if (nums[i] >= m)
            isOk[i] = true;
    }
    for (int i = 1; i <= n; i++)
        preAns[i] = preAns[i - 1] + isOk[i];
    cout << fun(1, n) << endl;
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