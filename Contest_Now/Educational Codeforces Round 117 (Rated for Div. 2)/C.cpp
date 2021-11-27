#include "bits/stdc++.h"

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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, k, x;
vector<int> V;

int cal(int x)
{
    int tot = x;
    x--;
    tot += 2 * x * (x + 1) / 2;
    return tot;
}

int cal1(int x)
{
    return x * (x + 1) / 2;
}

// y*(y+1) = x*2

void work()
{
    cin >> k >> x;
    int num = cal(k);
    if (x >= num)
    {
        cout << 2 * k - 1 << Endl;
        return;
    }
    if (x <= cal1(k))
    {
        ll nowAns = sqrt(2 * x);
        // cout << x << " " << nowAns << endl;
        if ((nowAns * (nowAns+1)) < 2*x)
            nowAns++;
        // cout << x << " " << nowAns << endl;
        cout << nowAns << endl;
        return;
    }
    ll temp = 2*(cal(k)-x);
    // cout << "te" << temp << endl;
    temp = sqrt(temp);
    // cout << "te" << temp << endl;
    cout << 2*k-temp << Endl;
}
signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif

    // init();
    cin >> t;
    while (t--)
        work();
    return 0;
}
