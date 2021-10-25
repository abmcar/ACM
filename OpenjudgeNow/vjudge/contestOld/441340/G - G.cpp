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
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf ll_MAX
#define endl "\n"

using namespace std;

const ll Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll t;
ll nx[5] = {0,-1,0,1,0};
ll ny[5] = {0,0,1,0,-1};
ll id[1203][1023];
bool vis[1023][1203];

void bfs()
{
    queue<ll> qX, qY, qI;
    qX.push(100);
    qY.push(100);
    qI.push(1);
    ll nowId = -1;
    while (!qX.empty())
    {
        ll nowX = qX.front();
        ll nowY = qY.front();
        qX.pop();
        qY.pop();
        qI.pop();
        if (vis[nowX][nowY])
            continue;
        id[nowX][nowY] = ++nowId;
        vis[nowX][nowY] = true;
        for (ll i = 1; i <= 4; i++)
        {
            ll nextX = nowX + nx[i];
            ll nextY = nowY + ny[i];
            ll nextId = nowId + 1;
            if (vis[nextX][nextY] || nextX > 120 || nextY > 120 || nextX < 80 || nextY < 80)
                continue;
            qX.push(nextX);
            qY.push(nextY);
            qI.push(nextId);
        }
    }
    for (ll i = 90; i <= 110; i++)
    {
        for (ll j = 90; j <= 110; j++)
            cout << setw(5) << id[i][j] << " ";
        cout << endl;
    }
}
/*
X1 + 1 = X2
X4 = X1 + h*3
X4 + 2 = X3

*/

ll getId(ll x, ll y)
{
    if (x > 0 && y == 0)
        return 2 * x*x;
    if (x > 0 && y == 1)
        return getId(x, 0) + 4*x;
    if (x > 0 && y > 1)
        return getId(x, 1) + (y-1)*(4*(x+1)+4*(x+(y-1)))/2;
    if (x < 0 && y > 0)
        return getId(-x,y)+1;
    if (x == 0 && y == 1)
        return 1;
    if (x == 0 && y > 0)
        return getId(0,1) + (y-1)*(4*(x+1)+4*(x+(y-1)))/2;
    if (x > 0 && y < 0)
        return getId(x,-y) - y * 3; 
    if (x < 0 && y < 0)
        return getId(-x,y) - 2*x;
    if (x == 0 && y < 0)
        return getId(x,-y+1) + y - 1;
    if (x < 0 && y == 0)
        return getId(-x+1,y) - 2*x;
}

ll nowx, nowy;

struct Pos
{
    ll x, y;
};

Pos getPos(ll id)
{
    Pos pos;
    pos.y = pos.x = 0;
    if (id == 0)
        return pos;
    if (id == 1)
        return (Pos){0,1};
    if (id == 2)
        return (Pos){1,0};
    if (id == 3)
        return (Pos){0,-1};
    if (id == 4)
        return (Pos){-1,0};
    if (id == 5)
        return (Pos){0,2};
    if (id == 6)
        return (Pos){1,1};
    if (id == 7)
        return (Pos){-1,1};
    // cout << "(id/2) / sqrt(id/2) " << sqrt(id/2 ) << " " << max((double)1,sqrt(id/2)) << endl;
    ll tempId = sqrt(id/2);
    if ((id/2) / sqrt(id/2) * (id/2) / sqrt(id/2) * 2 == id)
    {
        pos.x = (id/2) / sqrt(id/2);
        pos.y = 0;
        return pos;
    }
    ll temp = id - 2*tempId*tempId;
    // cout << "temp: " << temp << endl;
    pos.x = max((ll)1,tempId);
    pos.y = 0;
    ll nowx = tempId;
    // cout << "nowx: " << nowx << endl;
    // for (ll i = 1; i <= nowx; i++)
    // {
    //     temp--;
    //     pos.x--;
    //     pos.y--;
    //     if (temp == 0)
    //         return pos;
    // }
    ll nowD = min(nowx,temp);
    pos.x = pos.x - nowD;
    pos.y = pos.y - nowD;
    temp = temp - nowD;
    if (temp == 0)
        return pos;
    // cout << " " << pos.x << "  " << pos.y << endl;
    // for (ll i = 1; i <= nowx; i++)
    // {
    //     temp--;
    //     pos.x--;
    //     pos.y++;
    //     if (temp == 0)
    //         return pos;
    // }
    nowD = min(nowx,temp);
    pos.x = pos.x - nowD;
    pos.y = pos.y + nowD;
    temp = temp - nowD;
    if (temp == 0)
        return pos;
    // cout << " " << pos.x << "  " << pos.y << endl;
    temp--;
    pos.x = 0;
    pos.y = nowx+1;
    if (temp == 0)
        return pos;
    // cout << " " << pos.x << "  " << pos.y << endl;
    // for (ll i = 1; i <= 2*nowx; i++)
    // {
    //     temp--;
    //     pos.x = pos.x * -1;
    //     if (i % 2 == 1)
    //         pos.x++,pos.y--;
    //     if (temp == 0)
    //         return pos;
    // }
    // cout << pos.x << "    " << pos.y << endl;
    nowD = min(nowx*2,temp)/2;
    pos.x = pos.x + nowD;
    pos.y = pos.y - nowD;
    // cout << nowD << endl;
    if (min(nowx*2,temp) % 2 == 1)
    {
        pos.x++;
        pos.y--;
        // cout << pos.x << " 0   " << pos.y << endl;
        // pos.x *= -1;
    }else
        pos.x *= -1;

    // if (temp == 0)
        return pos;
}

int main()
{
    // Buff;
    // cin >> t;
    scanf("%lld",&t);
    while (t--)
    {
        ll opt, arg1, arg2;
        // cin >> opt;
        scanf("%lld",&opt);
        if (opt == 1)
        {
            // cin >> arg1;
            scanf("%lld",&arg1);
            Pos tempPos = getPos(arg1);
            printf("%lld %lld\n",tempPos.x-nowx,tempPos.y-nowy);
            // cout << tempPos.x-nowx << " " << tempPos.y-nowy << endl;
            nowx = tempPos.x;
            nowy = tempPos.y;
            // cout << "now: " << nowx <<  " " << nowy << endl;
        }
        if (opt == 2)
        {
            // cin >> arg1 >> arg2;
            scanf("%lld %lld",&arg1,&arg2);
            printf("%lld\n",getId(arg1,arg2));
            // cout << getId(arg1,arg2) << endl;
            nowx = arg1;
            nowy = arg2;
        }
    }
    // bfs();
    // cout << getId(-8,8);
    return 0;
}