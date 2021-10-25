#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#define Maxn 999

using namespace std;

int n,m;
char bd[Maxn][Maxn];
int ans[Maxn][Maxn];
int nx[4] = {1,0,-1,0};
int ny[4] = {0,1,0,-1};

queue<int> qx,qy;

void bfs()
{
    bool used[Maxn][Maxn];
    memset(used,0,sizeof(used));
    while(!qx.empty())
    {
        int nowx = qx.front();
        int nowy = qy.front();
        qx.pop();
        qy.pop();
        // cout << nowx << ' ' << nowy << endl;
        for(int i = 0; i < 4; i++)
        {
            int nextx = nowx + nx[i];
            int nexty = nowy + ny[i];
            if(nextx < 1 || nexty < 1 || nextx > n || nexty > m)
                continue;
            int nexttime = ans[nowx][nowy] + 1;
            if(nexttime >= ans[nextx][nexty])
                continue;
            ans[nextx][nexty] = nexttime;
            qx.push(nextx);
            qy.push(nexty);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    {
        cin >> bd[i][j];
            ans[i][j] = 1e8;
    }
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    if(bd[i][j] == '0')
    {
        qx.push(i);
        qy.push(j);
        ans[i][j] = 0;
        // used[i][j] = true;
    }
    bfs();
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}