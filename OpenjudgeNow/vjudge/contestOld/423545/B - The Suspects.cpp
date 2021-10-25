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
#include <sstream>
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e5    +10;
const ll Mod = 1e9+7;
int n,m;
int father[Maxn];

int find(int son)
{
    // cout << son;
    if(father[son] == son)
        return son;
    father[son] = find(father[son]);
    return father[son];
}

void work()
{
    int ans = 0;
    for(int i = 0; i < n; i++)
        father[i] = i;
    for(int i = 1; i <= m; i++)
    {
        int t;
        cin >> t;
        int fir;
        cin >> fir;
        for(int j = 2; j <= t; j++)
        {
            int temp;
            cin >> temp;
            if(find(fir) != find(temp))
                father[find(fir)] = find(temp);
        }
    }
    for(int i = 0; i < n; i++)
    if(find(i) == find(0))
        ans++;
    cout << ans << endl;
}

int main()
{
    Buff;
    while(cin >> n >> m)
    {
        if(n+m == 0)
            break;
        work();
    }
    return 0;
}