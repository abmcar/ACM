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

const int Maxn = 1e6 + 10;
const ll Mod = 1e9 + 7;

int t, n, tota, totb;
int a[Maxn], b[Maxn];
int prea[Maxn], preb[Maxn];

void work()
{
    // memset(prea,0,sizeof(prea));
    // memset(preb,0,sizeof(preb));
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        prea[i] = prea[i - 1] + a[i];
        preb[i] = preb[i - 1] + b[i];
    }
    tota = prea[n];
    totb = preb[n];
    // cout << tota << "   " << totb << Endl;
    int ans = 0;
    int orin = n;
    for (int i = 0; i <= n; i++)
    {
        tota = prea[n] - prea[(n + i) / 4] + i * 100;
        totb = preb[n] - preb[max(0, (n + i) / 4 - i)];
        if (tota >= totb)
        {
            cout << i << endl;
            return;
        }
    }
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