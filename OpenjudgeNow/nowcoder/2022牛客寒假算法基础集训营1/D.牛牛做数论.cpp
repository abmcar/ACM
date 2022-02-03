#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;
vector<int> magicNum = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

bool check(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

void work()
{
    cin >> n;
    if (n == 1)
    {
        cout << -1 << endl;
        return;
    }
    ll nowMin = 1;
    for (int it : magicNum)
    {
        if (it * nowMin > n)
            break;
        nowMin *= it;
    }
    ll nowMax = n;
    while (!check(nowMax))
        nowMax--;
    cout << nowMin << " " << nowMax << endl;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    // vector<int> E(1000);
    // for (int i = 2; i < 100; i++)
    // {
    //     if (!E[i])
    //         for (int j = i; j < 100; j += i)
    //         {
    //             if (!E[j])
    //                 E[j] = j;
    //             E[j] = E[j] / i * (i - 1);
    //         }
    // }
    // for (int i = 2; i < 100; i++)
    //     cout << i << " " << E[i] << endl;
    cin >> t;
    while (t--)
        work();
    return 0;
}