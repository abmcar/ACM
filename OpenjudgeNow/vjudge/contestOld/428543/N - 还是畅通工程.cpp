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

int n;
int dis[Maxn];
bool used[Maxn];
int ans;

void work()
{
    ans = 0;
    vector<int> g[Maxn];
    vector<int> w[Maxn];
    for(int i = 1; i <= n*(n-1)/2; i++)
    {
        int t1,t2,t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back(t2);
        w[t1].push_back(t3);
        g[t2].push_back(t1);
        w[t2].push_back(t3);
    }
    for(int i = 1; i <= n; i++)
        dis[i] = Inf, used[i] = false;
    dis[1] = 0;
    for(int i = 1; i <= n; i++)
    {
        int minPos = -1;
        int minVal = Inf;
        for(int j = 1; j <= n; j++)
        if(!used[j])
        if(minVal > dis[j])
        {
            minVal = dis[j];
            minPos = j;
        }
        if(minPos == -1)
            break;
        ans += minVal;
        // cout << minPos << " " << minVal << endl;
        used[minPos] = true;
        dis[minPos] = 0;
        for(int j = 0; j < g[minPos].size(); j++)
            dis[g[minPos][j]] = min(dis[g[minPos][j]],dis[minPos] + w[minPos][j]);
    }
    cout << ans << endl;
}

int main()
{
    Buff;
    while (cin >> n)
    {
        if(n == 0)
            break;
        work();
    }
    return 0;
}