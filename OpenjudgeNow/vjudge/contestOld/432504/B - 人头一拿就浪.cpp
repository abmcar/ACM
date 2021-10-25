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

const int Maxn = 1010;
const ll Mod = 1e9 + 7;

int t;
int fn, fk;
ll used[Maxn][Maxn][2];

ll dfs(int n,int k, int d)
{
    if(k == 1)
        return 1;
    if(used[n][k][d] != 0)
        return used[n][k][d];
    int ans = 2;
    if(d == 1)
    {
        if(n > 1)
            ans = (ans + dfs(n-1,k-1,1-d)-1) % Mod;
        if(n < fn)
            ans = (ans + dfs(n+1,k,d)-1) % Mod;  
    }else
    {
        if(n < fn)
            ans = (ans + dfs(n+1,k-1,1-d)-1) % Mod;
        if(n > 1)
            ans = (ans + dfs(n-1,k,d)-1) % Mod;  
    }
    used[n][k][d] = ans;
    return ans;
}


void work()
{
    cin >> fn >> fk;
    for (int i = 0; i <= fk+3; i++)
    for (int j = 0; j <= fn+3; j++)
        used[i][j][0] = used[i][j][1] = 0;
    // memset(used, 0, sizeof(used));
    cout << dfs(1, fk, 1) << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}