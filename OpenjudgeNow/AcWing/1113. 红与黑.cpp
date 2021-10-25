#include<iostream>
#include<queue>
#define Maxn (int)66

using namespace std;

char bd[Maxn][Maxn];
bool vis[Maxn][Maxn];
int nextx[5] = {0,1,0,-1,0};
int nexty[5] = {0,0,1,0,-1};
int w,h;
int strx,stry;
int ans = 1;

int main()
{
    while(cin >> h >> w)
    {
        if(h == 0 && w == 0)
            return 0;
        ans = 1;
        for(int i = 1; i <= w; i++)
        for(int j = 1; j <= h; j++)
        {
            vis[i][j] = 0;
            cin >> bd[i][j];
            if(bd[i][j] == '@')
            {
                strx = i;
                stry = j;
            }
        }
        queue<int> qx,qy;
        qx.push(strx);
        qy.push(stry);
        vis[strx][stry] = 1;
        while(!qx.empty())
        {
            int nowx = qx.front();
            int nowy = qy.front();
            // cout << nowx << " " << nowy << endl;
            qx.pop();
            qy.pop();
            for(int i = 1; i <= 4; i++)
            {
                int nx = nextx[i] + nowx;
                int ny = nexty[i] + nowy;
                if(bd[nx][ny] == '#' || vis[nx][ny])
                    continue;
                if(nx > w || ny > h || nx < 1 || ny < 1)
                    continue;
                vis[nx][ny] = 1;
                ans++;
                qx.push(nx);
                qy.push(ny);
            }
        }
        cout << ans << endl;
    }
}