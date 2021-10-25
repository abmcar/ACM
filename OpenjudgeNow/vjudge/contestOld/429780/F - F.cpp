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

int t, n;
struct Node
{
    int x,y;
    bool const operator < (Node b) const
    {
        return x < b.x;
    }
}node[Maxn];

void work()
{
    ll ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> node[i].x;
    for(int i = 1; i <= n; i++)
        cin >> node[i].y;
    sort(node+1,node+1+n);
    if(node[1].x != 1)
    {
        node[++n].x = 1;
        node[n].y = 1;
        sort(node+1,node+1+n);
    }
    for(int i = 1; i < n; i++)
    {
        if(node[i].y != node[i+1].y)
        {
            if(node[i+1].y > node[i].y)
            {
                if(node[i+1].y - node[i].y == node[i+1].x - node[i].x)
                {
                    if((node[i].x+node[i].y) % 2 == 0)
                        ans += node[i+1].y - node[i].y;
                    // cout << node[i].x << " " << node[i].y << endl;
                    continue;
                }
                if((node[i].x+node[i].y) % 2 == 0)
                {
                    node[i].x++;
                    node[i].x += node[i+1].y - node[i].y;
                }
            }else
            {
                ans += node[i].y - node[i+1].y;
                node[i].x += node[i].y - node[i+1].y;
            }
        }
        if((node[i].x+node[i].y) % 2 == 0)
            node[i].x++;
        ans += (node[i+1].x - node[i].x + 1)/2;
    }
    cout << ans << endl;
}

int main()
{
    Buff;
    cin >> t;
    while(t--)
        work();
    return 0;
}