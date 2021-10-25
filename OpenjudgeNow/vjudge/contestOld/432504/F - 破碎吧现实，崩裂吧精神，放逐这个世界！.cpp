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

const int Maxn = 1e4 + 10;
const ll Mod = 1e9 + 7;

int n, m, ans, nowPos;
int dis[Maxn];

void work()
{
    ans = nowPos = 0;
    for (int i = 1; i <= m+1; i++)
    {
        cin >> dis[i];
        dis[i] = dis[i] + dis[i-1];
        // cout << i << "         " << dis[i] << " " << endl;
    }
    while (nowPos != m+1)
    {
        // cout << nowPos << endl;
        if (dis[nowPos] + n >= dis[m+1])
            break;
        int nextPos = upper_bound(dis+1,dis+2+m,dis[nowPos]+n) - dis;
        // cout << nowPos << " " << nextPos << " " << dis[nowPos] << " " << dis[nextPos] << endl;
        while (dis[nextPos] - dis[nowPos] > n)
        {
            nextPos--;
            if (nextPos == nowPos)
            {
                cout << "No Solution!" << endl;
                return;
            }
        }
        nowPos = nextPos;
        ans++;
    }
    cout << ans << endl;
}

int main()
{
    Buff;
    while (cin >> n >> m)
        work();
    return 0;
}