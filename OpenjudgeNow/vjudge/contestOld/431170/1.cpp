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

int t, m ,n;

int dfs(int lastnum, int num, int deep)
{
    if(num == 0)
        return 1;
    if(deep == n)
        return 0;
    // cout << num << " " << deep << endl;
    ll ans = 0;
    for (int i = min(num,lastnum); i >= 0; i--)
        ans += dfs(i,num-i,deep+1);
    return ans;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        cout << dfs(m,m,0) << endl;
    }
    return 0;
}