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
const ll Mod = 998244353;

int n;
int ans[11];
vector<int> nums(11);
vector<int> preC(1e5 + 10);

int fun(int x)
{
    while (x >= 10)
    {
        int temp = 0;
        while (x)
        {
            temp += x % 10;
            x = x / 10;
        }
        x = temp;
    }
    return x;
}

ll quickPow(ll base, ll x)
{
    ll now = 1;
    while (x)
    {
        if (x % 2)
            now = now * base % Mod;
        base = base * base % Mod;
        x = x / 2;
    }
    return now % Mod;
}

ll inverse(ll num)
{
    return quickPow(num, Mod - 2) % Mod;
}

int getC(int r, int n)
{
    int ans;
    ans = (preC[n] * inverse(preC[r]) % Mod * inverse(preC[n - r]) % Mod) % Mod;
    return ans;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    // srand(time(0));
    preC[0] = 1;
    for (int i = 1; i <= 1e5; i++)
        preC[i] = preC[i - 1] * i % Mod;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        temp = fun(temp);
        nums[temp]++;
    }
    ans[0] = 1;
    for (int i = 1; i <= 9; i++)
    {
        vector<int> temp(11);
        for (int j = 1; j <= nums[i]; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                int nextNum = (k + j * i) % 9;
                if (nextNum == 0)
                    nextNum = 9;
                temp[nextNum] = (temp[nextNum] + getC(j, nums[i]) * ans[k] % Mod) % Mod;
            }
        }
        for (int i = 1; i <= 9; i++)
            ans[i] = (ans[i] + temp[i]) % Mod;
    }
    for (int i = 1; i <= 9; i++)
        cout << ans[i] << " ";
    // for (int i = 1; i <= 100; i++)
    //     cout << i << " " << fun(i) << endl;
    return 0;
}