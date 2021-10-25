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
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf ll_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const ll Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;
ll n;
vector<ll> N;
unordered_map<ll, ll> M;
vector<int> primes;
int vis[Maxn];

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    for (int i = 2; i <= 1e6; i++)
    {
        if (vis[i] == 0)
            primes.push_back(i);
        for (int j = 2; j*i <= 1e6; j++)
            vis[i*j] = true;
    }
    // cout << primes.size() << endl;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll temp;
        cin >> temp;
        N.push_back(temp);
        M[temp]++;
    }
    ll nowGcd = __gcd(N[0], N[1]);
    for (ll i = 2; i < n; i++)
        nowGcd = __gcd(nowGcd, N[i]);
    if (nowGcd != 1)
    {
        cout << "not coprime" << endl;
        return 0;
    }
    for (int i = 0; i < primes.size(); i++)
    {
        int nowCnt = 0;
        for (int j = 1; j*primes[i] <= 1e6; j++)
            nowCnt = nowCnt + M[j*primes[i]];
        if (nowCnt > 1)
        {
            cout << "setwise coprime" << endl;
            return 0;
        }
    }
    cout << "pairwise coprime" << endl;
    return 0;
}