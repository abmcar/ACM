#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
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
ll n,k;

int main()
{
    Buff;
    cin >> n >> k;
    ll base = 1;
    for(int i = 1; i <= k; i++)
        base *= 10;
    ll originN = n;
    n = max((ll)1,(base/n))*n;
    while(n % base != 0)
    {
        n += originN;
        // cout << n << " " << base << " " << n % base << endl;
    }
    cout << n;
    return 0;
}