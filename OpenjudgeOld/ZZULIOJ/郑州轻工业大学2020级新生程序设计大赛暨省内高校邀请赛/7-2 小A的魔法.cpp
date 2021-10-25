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

const int Maxn = 1e3+10;
const ll Mod = 1e9+7;

int preans[Maxn][Maxn];
int bd[Maxn][Maxn];
int n,w,h;
int maxn;

int main()
{
    Buff;
    cin >> n >> w >> h;
    for(int i = 1; i <= n; i++)
    {
        int t1,t2;
        cin >> t1 >> t2;
        bd[t1][t2] = 1;
    }
    for(int i = 1; i <= 1e3; i++)
    for(int j = 1; j <= 1e3; j++)
        preans[i][j] = preans[i][j-1] + preans[i-1][j] - preans[i-1][j-1] + bd[i][j];
    for(int i = 0; i <= 1e3; i++)
    for(int j = 0; j <= 1e3; j++)
    {
        int nextx = i + w;
        int nexty = j + h;
        if(nextx <= 1e3 && nexty <= 1e3)
        {
            maxn = max(maxn, preans[nextx][nexty]-preans[i][nexty]-preans[nextx][j] + preans[i][j]);
            // cout << i << " " << j << " " << preans[nextx][nexty  ]-preans[i][nexty]-preans[nextx][j] + preans[i][j] << endl;
        }
        // nextx = i + h;
        // nexty = j + w;
        // if(nextx <= n && nexty <= n)
        // {
        //     maxn = max(maxn, preans[nextx][nexty]-preans[i][nexty]-preans[nextx][j] + preans[i][j]);
        // }
    }
    cout << maxn;
    return 0;
}