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
#define Endl "\n"
// #define Debug

using namespace std;

const ll Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

map<char,ll> M;
string oriString;
ll n;

ll quickPow(ll base, int x)
{
    ll res = 1;
    while (x)
    {
        if (x % 2 == 1)
        {
            res = res * base % Mod;
            x--;
        }
        base = base * base % Mod;
        x = x / 2;
    }
    return res;
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    cin >> oriString;
    for (ll i = 0; i < oriString.size(); i++)
        M[oriString[i]]++;
    ll max1, max2;
    max1 = max2 = 0;
    max1 = max(max1, M['A']);
    max1 = max(max1, M['T']);
    max1 = max(max1, M['G']);
    max1 = max(max1, M['C']);
    if (max1 == M['A'])
        max2++;
    if (max1 == M['T'])
        max2++;
    if (max1 == M['G'])
        max2++;
    if (max1 == M['C'])
        max2++;
    cout << quickPow(max2, n) << Endl;
    return 0;
}