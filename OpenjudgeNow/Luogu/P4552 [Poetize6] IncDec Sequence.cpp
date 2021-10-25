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

ll n;
ll num[Maxn];
ll d[Maxn];
ll ans1,ans2;

int main()
{
    Buff;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    d[1] = num[1];
    for(int i = 2; i <= n; i++)
    {
        d[i] = num[i] - num[i-1];
        if(d[i] > 0)
            ans1 += d[i];
        else
            ans2 -= d[i];
    }
    cout << max(ans1,ans2) << endl << std::abs(ans1-ans2)+1;
    return 0;
}