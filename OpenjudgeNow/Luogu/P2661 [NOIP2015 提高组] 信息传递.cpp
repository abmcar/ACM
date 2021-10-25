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

int n;
int father[Maxn];
int dis[Maxn];
int minn = Inf;
int find(int son)
{
    if(father[son] == son)
        return son;
    int temp = father[son];
    father[son] = find(father[son]);
    dis[son] += dis[temp];
    return father[son];
}

int main()
{
    Buff;
    cin >> n;
    for (int i = 1; i <= n; i++)
        father[i] = i;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        int f1 = find(i);
        int f2 = find(t);
        if (f1 != f2)
        {
            father[f1] = f2;
            dis[i] = dis[t] + 1;
        }else
            minn = min(minn,dis[i] + dis[t] + 1);
    }
    cout << minn;
    return 0;
}