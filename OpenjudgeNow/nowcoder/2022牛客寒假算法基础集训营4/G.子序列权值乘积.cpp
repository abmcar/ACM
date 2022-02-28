#include <bits/stdc++.h>

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
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int n, ans, fp;
vector<int> nums;
unordered_map<int, int> M, firPos;

ll ph(ll x)
{
    ll res = x, a = x;
    for (ll i = 2; i * i <= x; i++)
    {
        if (a % i == 0)
        {
            res = res / i * (i - 1);
            while (a % i == 0)
                a /= i;
        }
    }
    if (a > 1)
        res = res / a * (a - 1);
    return res;
}

ll quickPow(ll base, ll x, ll Mod)
{
    ll nowNum = 1;
    while (x)
    {
        if (x % 2)
            nowNum = nowNum * base % Mod;
        x = x / 2;
        base = base * base % Mod;
    }
    return nowNum;
}

ll quick_pow(ll base, ll x)
{
    return quickPow(base,quickPow(2,x,fp)+fp,Mod);
    // ll nowNum = 1;
    // // if (x != 0)
    // //     base = quickPow(base, x + 1);
    // for (int i = 1; i <= x; i++)
    // {
    //     base = base * base % Mod;
    // }
    // nowNum = nowNum * base % Mod;
    // return nowNum;
}

signed main()
{
    fp = ph(Mod);
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    ans = 1;
    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        int len1 = i;
        int len2 = n - i - 1;
        int nowNum;
        nowNum = quick_pow(nums[i], len1);
        nowNum = nowNum * quick_pow(nums[i], len2) % Mod;
        ans = ans * nowNum % Mod;
    }
    cout << ans << endl;
    return 0;
}