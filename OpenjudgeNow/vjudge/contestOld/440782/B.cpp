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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll quick_pow(ll base, ll x)
{
    if (x == 0)
        return 1;
    // ll right = pow(base,x);
    ll now = 1;
    while (x != 0)
    {
        if (x % 2 == 0)
        {
            x = x / 2;
            base *= base;
            continue;
        }
        x--;
        now *= base;
    }
    // cout << right << " " << now << endl;
    return now;
}

ll t;
ll m , n;

void work()
{
    cin >> n >> m;
    if ((n+m) % 2 == 0)
        cout << 12 << endl;
    else
        cout << 2 << endl;
    // cout << __gcd((ll)(quick_pow(5,n)+quick_pow(7,n)),(ll)(quick_pow(5,m)+quick_pow(7,m))) << endl;
}

int main()
{
    Buff;
    // cin >> t;
    // while (t--)
    //     work();
    // cout << __gcd(901668,12) << endl;
    for (int i = 1; i <= 22; i++)
    {
        int temp = 0;
    for (int j = i; j <= 22; j++)
        if (__gcd(i,j) == 1)
        {
            cout << i << " " << j << " " << __gcd((quick_pow(5,i)+quick_pow(7,i)),(quick_pow(5,j)+quick_pow(7,j))) << endl;
            cout << i << " " << j << " " << __gcd((int)(pow(5,i)+pow(7,i)),(int)(pow(5,j)+pow(7,j))) << endl;
            cout << i << " " << j << " " << __gcd((ll)(pow(5,i)+pow(7,i)),(ll)(pow(5,j)+pow(7,j))) << endl;
            cout << (int)(pow(5,i)+pow(7,i)) << "  " << (quick_pow(5,i)+quick_pow(7,i)) << endl;
            cout << endl;
        }
        cout << temp << endl;
    }
        // cout << i << " " << j << " " << __gcd(i,j) << endl;
    return 0;
}
/*
2^5 2 2  2 2  2
4
*/