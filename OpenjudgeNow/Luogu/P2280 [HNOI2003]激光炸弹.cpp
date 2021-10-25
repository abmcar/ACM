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

const int Maxn = 5e3+10;
const ll Mod = 1e9+7;

int n,m;
int preans[Maxn][Maxn];
int ans;

int main()
{
    Buff;
    cin >> n >> m;
    for(int j = 1; j <= n; j++)
    {
        int tempx,tempy,tempv;
        cin >> tempx >> tempy >> tempv;
        preans[tempx+1][tempy+1] = tempv;
    }
    for(int i = 1; i <= 5e3+3; i++)
    for(int j = 1; j <= 5e3+3; j++)
        preans[i][j] = preans[i][j-1] + preans[i-1][j] - preans[i-1][j-1] + preans[i][j];
    for(int i = 1; i <= 5e3+3; i++)
    for(int j = 1; j <= 5e3+3; j++)
    {
        int nextx = i + m - 1;
        int nexty = j + m - 1;
        if(nextx > 5e3+3 || nexty > 5e3+3)
            continue;
        ans = max(ans,preans[nextx][nexty] - preans[nextx][j-1] - preans[i-1][nexty] + preans[i-1][j-1]);
    }
    cout << ans;
    return 0;
}