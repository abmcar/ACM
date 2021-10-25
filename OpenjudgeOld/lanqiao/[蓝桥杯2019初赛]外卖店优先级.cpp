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

const int Maxn = 1e6+10;
const ll Mod = 1e9+7;

struct Order
{
    int time,id;
    bool const operator< (const Order b) const
    {
        return time < b.time;
    }
}order[Maxn];
int lastOrder[Maxn];
ll nowLevel[Maxn];
ll orders[Maxn];
bool ok[Maxn];
int n,m,t;
int main()
{
    Buff;
    cin >> n >> m >> t;
    for(int i = 1; i <= m; i++)
        cin >> order[i].time >> order[i].id;
    sort(order+1,order+1+m);
    int ans = 0;
    for(int i = 1; i <= m; i++)
    {
        int nowId = order[i].id;
        int nowTime = order[i].time;
        if(nowTime != lastOrder[nowId])
        nowLevel[nowId] = max((ll)0,nowLevel[nowId]-(nowTime-lastOrder[nowId]-1));
        if(nowLevel[nowId] <= 3)
            ok[nowId] = false;
        nowLevel[nowId] += 2;   
        if(nowLevel[nowId] > 5)
            ok[nowId] = true;
        lastOrder[nowId] = nowTime;
    }
    for(int i = 1; i <= n; i++)
    {
        if(lastOrder[i] != t)
        {
            nowLevel[i] = max((ll)0,nowLevel[i]-(t-lastOrder[i]));
            if(nowLevel[i] <= 3)
                ok[i] = false;
        }
    }
    for(int i = 1; i <= n; i++)
        if(ok[i])
            ans++;
    cout << ans;
    return 0;
}