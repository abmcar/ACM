#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#define Maxn (int)1e3+10
using namespace std;

char bd[Maxn][Maxn];
bool used[Maxn][Maxn];
int strx,stry;
int ans;
int nx[8] = {0,1,0,-1,1,1,-1,-1};
int ny[8] = {1,0,-1,0,1,-1,1,-1};
int n,m;

void work()
{
    ans = 0;
    cin >> m;
    if(n == 0 && m == 0)
        return;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    {
        used[i][j] = 0;
        cin >> bd[i][j];
    }
    queue<int> qx,qy;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    {
        if(bd[i][j] == 'W' && used[i][j] == 0)
        {
            ans++;
            qx.push(i);
            qy.push(j);
            while (!qx.empty())
            {
                int nowx = qx.front();
                int nowy = qy.front();
                qx.pop();
                qy.pop();
                for(int i = 0; i < 8; i++)
                {
                    int nextx = nowx+nx[i];
                    int nexty = nowy+ny[i];
                    if(used[nextx][nexty] || bd[nextx][nexty] == '.')
                        continue;
                    if(nextx <= 0 || nexty <= 0 || nextx > n || nexty > m)
                        continue;
                    used[nextx][nexty] = 1;
                    qx.push(nextx);
                    qy.push(nexty);
                }
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    while(cin >> n)
        work();
    return 0;
}