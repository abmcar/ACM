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
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;

int t;
ll n;

ll gcdSum(ll x)
{
    ll tempans = 0;
    ll tempnum = x;
    while (x != 0)
    {
        tempans += x % 10;
        x = x / 10;
    }
    return __gcd(tempnum,tempans);
}

int main()
{
    Buff;
    // cout << __gcd(11,2) << endl;
    cin >> t;
    while (t--)
    {
        cin >> n;
        // n++;
        for(ll i = n; i <= 1e19; i++)
        if(gcdSum(i) > 1)
        {
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}