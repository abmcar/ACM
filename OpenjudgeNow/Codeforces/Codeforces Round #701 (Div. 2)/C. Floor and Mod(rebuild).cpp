#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;
ll x, y;
ll ans;
int t;
int main()
{
    Buff;
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> x >> y;
        for (ll b = 2; b <= min(y, (ll)sqrt(x + 1)); b++)
            ans += b - 1;
        ll l, r;
        for (l = sqrt(x + 1) + 1; l <= min(x, y); l = r + 1)
        {
            if (x / (l + 1) <= 0) 
                break;
            r = min(y, min(x, x / (x / (l + 1))-1));
            ans += (r - l + 1) * (x / (l + 1));
        }
        cout << ans << endl;
    }
    return 0;
}