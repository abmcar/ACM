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

const int Maxn = 1e4+10;
const ll Mod = 1e9+7;

int nextx[5] = {0,1,-1,0,0};
int nexty[5] = {0,0,0,1,-1};
int bd[Maxn][Maxn];
int used[Maxn][Maxn];
int r,c;
int strX,strY;
int ans;

int dfs(int nowx,int nowy)
{
    int maxans = 1;
    for(int i = 1; i <= 4; i++)
    {
        int nx = nowx + nextx[i];
        int ny = nowy + nexty[i];
        if(nx < 1 || ny < 1 || nx > r || ny > c)
            continue;
        if(bd[nowx][nowy] <= bd[nx][ny])
            continue;
        if(used[nx][ny])
        {
            maxans = max(maxans,1+used[nx][ny]);
            continue;
        }
        used[nx][ny] = dfs(nx,ny);
        maxans = max(maxans,1+used[nx][ny]);
    }
    return maxans;
}


int main()
{
    Buff;
    cin >> r >> c;
    int tempMaxn = 0;
    for(int i = 1; i <= r; i++)
    for(int j = 1; j <= c; j++)
    {
        cin >> bd[i][j];
        if(tempMaxn < bd[i][j])
            tempMaxn = bd[i][j];
    }
    for(int i = 1; i <= r; i++)
    for(int j = 1; j <= c; j++)
    {
        {
            strX = i;
            strY = j;
            ans = max(ans,dfs(i,j));
        }
    }
    cout << ans;
    return 0;
}