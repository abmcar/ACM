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
ll ans;

ll getSqrt(ll num)
{
    bool ok = false;
    ll temp = num;
    while(num != 0)
    {
        ll tempnum = num % 10;
        if(tempnum == 2 || tempnum == 0 || tempnum == 1 || tempnum == 9)
            ok = true;
        num = num / 10;
    }
    if(ok)
        return temp*temp;
    return 0;
}

int main()
{
    Buff;
    for(int i = 1; i <= 2019; i++)
        ans += getSqrt(i);
    cout << ans << endl;
    return 0;
}