// #include <iostream>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <iomanip>
// #include <cmath>
// #include <ctime>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <climits>
// #include <ext/pb_ds/priority_queue.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#include <bits/extc++.h>
#include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll n, m;
struct Num
{
    ll pos, val;
    bool const operator< (Num b) const
    {
        return pos < b.pos;
    }
};

vector<Num> V;
unordered_map<ll,ll> M;
ll d[Maxn];

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m;
    V.push_back((Num){(ll)-1e12,0});
    while (n--)
    {
        ll x, c;
        cin >> x >> c;
        V.push_back({x,c});
    }
    V.push_back((Num){(ll)1e12,0});
    sort(V.begin(),V.end());
    for (int i = 1; i < V.size(); i++)
    {
        d[i] = d[i-1] + V[i].val;
    }
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        ll oril = l;
        ll orir = r;
        l = lower_bound(V.begin(),V.end(),(Num){l,0}) - V.begin();
        r = upper_bound(V.begin(),V.end(),(Num){r,0}) - V.begin();
        // if (oril > V[l-1].pos && orir < V[l].pos)
        // {
        //     cout << 0 << endl;
        //     continue;
        // }
        while (V[r].pos > orir)
            r--;
        // cout << l << " " << r << endl;
        cout << d[r] - d[l-1] << endl;
    }
    return 0;
}