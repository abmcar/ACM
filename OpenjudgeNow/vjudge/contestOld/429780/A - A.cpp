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

ll t, n, m;
ll pos;

void work()
{
    cin >> n >> m >> pos;
    ll r = pos / n;
    ll c = pos % n;
    // cout << r << " " << c << endl;
    if(c == 0)
    {
        c = n;
        r--;
    }
    cout << (c-1)*m+r+1 << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}