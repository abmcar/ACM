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
ll a = 1;
ll b = 1;
ll c = 1;
ll ans;
int main()
{
    Buff;
    for(int i = 4; i <= 20190324; i++)
    {
        ans = (a+b+c) % 10000;
        a = b;
        b = c;
        c = ans;
    }
    cout << ans;
    return 0;
}