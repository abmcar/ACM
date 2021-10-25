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

int nextx[5] = {0,1,0,-1,0};
int nexty[5] = {0,0,1,0,-1};
int r,c;
char bd[Maxn][Maxn];
int strX,strY;
int endX,endY;
bool used[Maxn][Maxn];
int mint = Inf;
int ans;

int main()
{
    Buff;
    cin >> r >> c;
    for(int i = 1; i <= r; i++)
    for(int j = 1; j <= c; j++)
    {
        cin >> bd[i][j];
        if(bd[i][j] == 'S')
            strX = i, strY = j;
        if(bd[i][j] == 'E')
            endX = i, endY = j;
    }
    queue<int> qx,qy,qt;
    qx.push(strX);
    qy.push(strY);
    qt.push(0);
    while (!qx.empty())
    {
        int nowx = qx.front();
        int nowy = qy.front();
        int nowt = qt.front();
        qx.pop();
        qy.pop();
        qt.pop();
        if(nowx == endX && nowy == endY)
        {
            mint = nowt;
            break;
        }
        for(int i = 1; i <= 4; i++)
        {
            int nx = nowx + nextx[i];
            int ny = nowy + nexty[i];
            int nt = nowt + 1;
            if(nx < 1 || ny < 1 || nx > r || ny > c)
                continue;
            if(used[nx][ny])
                continue;
            if(bd[nx][ny] == 'T')
                continue;
            used[nx][ny] = true;
            qx.push(nx);
            qy.push(ny);
            qt.push(nt);
        }
    }
    while (!qx.empty())
        qx.pop(),qy.pop(),qt.pop();
    for(int i = 1; i <= r; i++)
    for(int j = 1; j <= c; j++)
        used[i][j] = false;
    qx.push(endX);
    qy.push(endY);
    qt.push(0);
    while (!qx.empty())
    {
        int nowx = qx.front();
        int nowy = qy.front();
        int nowt = qt.front();
        qx.pop();
        qy.pop();
        qt.pop();
        if(bd[nowx][nowy] >= '1' && bd[nowx][nowy] <= '9')
        {
            if(nowt <= mint)
                ans += bd[nowx][nowy] - '0';
        }
        for(int i = 1; i <= 4; i++)
        {
            int nx = nowx + nextx[i];
            int ny = nowy + nexty[i];
            int nt = nowt + 1;
            if(nx < 1 || ny < 1 || nx > r || ny > c)
                continue;
            if(used[nx][ny])
                continue;
            if(bd[nx][ny] == 'T')
                continue;
            used[nx][ny] = true;
            qx.push(nx);
            qy.push(ny);
            qt.push(nt);
        }
    }
    cout << ans;
    return 0;
}