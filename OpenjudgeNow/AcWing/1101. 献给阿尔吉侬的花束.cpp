#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#define ll long long

using namespace std;

const int Maxn = 233;
const ll Mod = 1e9+7;

int t,r,c;
char bd[Maxn][Maxn];
bool used[Maxn][Maxn];
int strx,stry;
int nx[5] = {0,1,0,-1,0};
int ny[5] = {0,0,1,0,-1};

void work()
{
    memset(used,0,sizeof(used));
    cin >> r >> c;
    for(int i = 1; i <= r; i++)
    for(int j = 1; j <= c; j++)
    {
        cin >> bd[i][j];
        if(bd[i][j] == 'S')
            strx = i, stry = j;
    }
    used[strx][stry] = true;
    queue<int> qx,qy,qt;
    qx.push(strx);
    qy.push(stry);
    qt.push(0);
    while(!qx.empty())
    {
        int nowx = qx.front();
        int nowy = qy.front();
        int nowt = qt.front();
        qx.pop();
        qy.pop();
        qt.pop();
        if(bd[nowx][nowy] == 'E')
        {
            cout << nowt << endl;
            return;
        }
        for(int i = 1; i <= 4; i++)
        {
            int nextx = nowx + nx[i];
            int nexty = nowy + ny[i];
            int nextt = nowt + 1;
            if(nextx > r || nextx < 1 || nexty > c || nexty < 1)
                continue;
            if(used[nextx][nexty])
                continue;
            if(bd[nextx][nexty] == '#')
                continue;
            used[nextx][nexty] = true;
            qx.push(nextx);
            qy.push(nexty);
            qt.push(nextt);
        }
    }
    cout << "oop!" << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    while(t--)
        work();
    return 0;
}