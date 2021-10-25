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

int c,d;
int ans;
int now;

int main()
{
    Buff;
    cin >> c >> d;
    d = 240 - d;
    for(ans = 1; ans <= c; ans++)
    {
        now += ans*5;
        if(now > d)
            break;
        // cout << now << " " << d << endl;
    }
    cout << ans-1;
    return 0;
}