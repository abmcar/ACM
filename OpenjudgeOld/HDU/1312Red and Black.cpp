#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#define Maxn (int)1e3
using namespace std;

char bd[Maxn][Maxn];
bool used[Maxn][Maxn];
int strx,stry;
int ans;
int nx[4] = {0,1,0,-1};
int ny[4] = {1,0,-1,0};
int n,m;

void work()
{
    ans = 0;
    cin >> m;
    if(n == 0 && m == 0)
        return;
    for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++)
    {
        used[i][j] = 0;
        cin >> bd[i][j];
        if(bd[i][j] == '@')
        {
            strx = i;
            stry = j;
        }
    }
    used[strx][stry] = 1;
    queue<int> qx,qy;
    qx.push(strx);
    qy.push(stry);
    while (!qx.empty())
    {
        int nowx = qx.front();
        int nowy = qy.front();
        qx.pop();
        qy.pop();
        if(bd[nowx][nowy] == '.')
            ans++;
        for(int i = 0; i < 4; i++)
        {
            int nextx = nowx+nx[i];
            int nexty = nowy+ny[i];
            if(used[nextx][nexty] || bd[nextx][nexty] == '#')
                continue;
            if(nextx <= 0 || nexty <= 0 || nextx > m || nexty > n)
                continue;
            used[nextx][nexty] = 1;
            qx.push(nextx);
            qy.push(nexty);
        }
    }
    cout << ans+1 << endl;
}

int main()
{
    while(cin >> n)
        work();
    return 0;
}