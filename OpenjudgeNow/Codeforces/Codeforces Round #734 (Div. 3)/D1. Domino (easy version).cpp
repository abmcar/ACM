#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, m, k;

void work()
{
    cin >> n >> m >> k;
    if (m % 2 == 1)
    {
        swap(n, m);
        k = n * m / 2 - k;
    }
    bool ok = false;
    if (n % 2 == 0)
    {
        if (k % 2 == 0)
            ok = true;
    }
    else
    {
        k = k - m / 2;
        if (k >= 0 && k % 2 == 0)
                ok = true;
    }
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << Endl;
}

int main()
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