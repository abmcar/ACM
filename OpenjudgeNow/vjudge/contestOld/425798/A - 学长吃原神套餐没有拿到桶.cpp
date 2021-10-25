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
int n,k;
bool used[10];
vector<int> r[10];

int dfs(int deep)
{
    int ans = 0;
    int ok = 0;
    for(int i = 1; i <= n; i++)
        if(used[i])
            ok++;
    if(ok == k)
        return 1;
    if(deep == n+1)
        return 0;
    ans += dfs(deep+1);
    for(int i = 0; i < r[deep].size(); i++)
    {
        if(used[r[deep][i]])
            continue;
        used[r[deep][i]] = true;
        ans += dfs(deep+1);
        used[r[deep][i]] = false;
    }
    return ans;
}

void work()
{
    int ans = 0;
    for(int i = 1; i <= 8; i++)
        r[i].clear();
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    {
        char tempChar;
        cin >> tempChar;
        if(tempChar == '#')
            r[i].push_back(j);
    }
    ans = dfs(1);
    cout << ans << endl;
}

int main()
{
    Buff;
    while(cin >> n >> k)
    {
        if(n+k == -2)
            break;
        work();
    }
    return 0;
}