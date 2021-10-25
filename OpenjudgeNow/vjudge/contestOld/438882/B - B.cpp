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
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const ll Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll maxb, minb;
ll maxg, ming;
ll n, m;
ll tot;
ll b[Maxn], g[Maxn];

int main()
{
    Buff;
    cin >> n >> m;
    minb = ming = 1e9;
    maxb = maxg = -1;
    for (ll i = 1; i <= n; i++)
    {
        ll temp;
        cin >> temp;
        b[i] = temp;
        maxb = max(temp, maxb);
        minb = min(temp, minb);
    }
    ll minnb = -1;
    bool isok = true;
    // cout << maxb << endl;
    for (ll i = 1; i <= n; i++)
        if (b[i] == maxb && isok == true)
        {
            isok = false;
            continue;
        }
        else
            minnb = max(minnb, b[i]);
    // cout << minnb << endl;
    for (ll i = 1; i <= m; i++)
    {
        ll temp;
        cin >> temp;
        g[i] = temp;
        maxg = max(temp, maxg);
        ming = min(temp, ming);
    }
    if (n == 1)
    {
        bool tempok = true;
        for (ll i = 1; i <= m; i++)
            if (g[i] != b[1])
                tempok = false;
        if (!tempok)
        {
            cout << "-1" << endl;
            return 0;
        }
        ll tempN = 0;
        for (ll i = 1; i <= m; i++)
            tempN += g[i];
        cout << tempN << endl;
        return 0;
    }
    if (m == 1)
    {
        bool tempok = true;
        for (ll i = 1; i <= n; i++)
            if (b[i] != g[1])
                tempok = false;
        if (!tempok)
        {
            cout << "-1" << endl;
            return 0;
        }else
        {
            cout << n*g[1] << endl;
            return 0;
        }
    }
    if (maxb > ming)
    {
        cout << "-1" << endl;
        return 0;
    }
    for (ll i = 1; i <= m; i++)
        tot += g[i] - maxb;
    for (ll i = 1; i <= n ;i++)
        tot += b[i] * m;
    // cout << minnb << endl;
    if (ming != maxb)
    {
        if (maxb == -1)
        {
            cout << "-1" << endl;
            return 0;
        }
        if (maxb != minnb)
        {
            // tot -= ming - maxb;
            // tot += ming - minnb;
            tot += maxb - minnb;
        }
    }
    cout << tot;
    return 0;
}