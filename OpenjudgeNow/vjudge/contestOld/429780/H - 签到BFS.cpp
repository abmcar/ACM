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

int n,m,k;
char bd[Maxn][Maxn];
short used[Maxn][Maxn];
int strX,strY,endX,endY;
int nx[5] = {0,1,0,-1,0};
int ny[5] = {0,0,1,0,-1};

bool check()
{
    queue<short> qX,qY,qT;
    qX.push(strX);
    qY.push(strY);
    qT.push(0);
    while(!qX.empty())
    {
        short nowx = qX.front();
        short nowy = qY.front();
        short nowt = qT.front();
        qX.pop();
        qY.pop();
        qT.pop();
        if(used[nowx][nowy] < nowt)
            continue;
        if(nowx == endX && nowy == endY)
            return true;
        for(short i = 1; i <= 4; i++)
        {
            short nextx = nowx + nx[i];
            short nexty = nowy + ny[i];
            short nextt = nowt + 1;
            if(nextx > n || nexty > m || nextx < 1 || nexty < 1)
                continue;
            if(bd[nextx][nexty] == '#')
                continue;
            if(used[nextx][nexty] <= nextt)
                continue;
            used[nextx][nexty] = nextt;
            qX.push(nextx);
            qY.push(nexty);
            qT.push(nextt);
        }
    }
    return false;
}

int main()
{
    Buff;
    cin >> n >> m >> k;
    for(short i = 1; i <= n; i++)
    for(short j = 1; j <= m; j++)
        cin >> bd[i][j], used[i][j] = 1e4;
    cin >> strX >> strY >> endX >> endY;
    if(!check())
    {
        cout << "-1" << endl;
        return 0;
    }
    for(short i = 1; i <= n; i++)
    for(short j = 1; j <= m; j++)
        used[i][j] = 1e4;
    queue<short> qX,qY,qT;
    qX.push(strX);
    qY.push(strY);
    qT.push(0);
    while(!qX.empty())
    {
        short nowx = qX.front();
        short nowy = qY.front();
        short nowt = qT.front();
        qX.pop();
        qY.pop();
        qT.pop();
        if(used[nowx][nowy] < nowt)
            continue;
        if(nowx == endX && nowy == endY)
        {
            cout << nowt << endl;
            return 0;
        }
        for(short i = 1; i <= 4; i++)
        for(short j = 1; j <= k; j++)
        {
            short nextx = nowx + nx[i]*j;
            short nexty = nowy + ny[i]*j;
            short nextt = nowt + 1;
            if(nextx > n || nexty > m || nextx < 1 || nexty < 1)
                break;
            if(bd[nextx][nexty] == '#')
                break;
            // if(used[nextx][nexty] <= nextt+2)
            //     break;
            if(used[nextx][nexty] <= nextt)
                continue;
            if(nextx == endX && nexty == endY)
            {
                cout << nextt << endl;
                return 0;
            }
            used[nextx][nexty] = nextt;
            qX.push(nextx);
            qY.push(nexty);
            qT.push(nextt);
        }
    }
    cout << "-1" << endl;
    return 0;
}
