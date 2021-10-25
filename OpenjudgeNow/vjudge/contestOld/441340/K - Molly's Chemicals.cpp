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
#define Inf ll_MAX
#define endl "\n"

using namespace std;

const ll Maxn = 1e6 + 10;
const ll Mod = 1e9 + 7;

ll n, k, ans;
ll num[Maxn], preAns[Maxn];
map<ll,ll> M;
vector<ll> w;

void init()
{
    ll tempAns = 0;
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
        cin >> num[i], tempAns += num[i];
    for (ll i = 1; i <= n; i++)
        preAns[i] = preAns[i-1] + num[i];
    if (k == 1)
    {
        w.push_back(1);
        return;
    }
    if (k == -1)
    {
        w.push_back(1);
        w.push_back(-1);
        return;
    }
    ll nowBase = 1;
    while (nowBase <= 2e14)
    {
        w.push_back(nowBase);
        nowBase *= k;
        // cout << nowBase << endl;
    }
    // cout << w.size() << endl;
}
// pr - pl = w
// pr = w + pl
void work()
{
    M[0]++; 
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < w.size(); j++)
            ans += M[preAns[i]-w[j]];
        // cout << i << " " << ans << endl;
        M[preAns[i]]++;
    }
    cout << ans << endl;
}

int main()
{
    Buff;
    init();
    work();
    return 0;
}