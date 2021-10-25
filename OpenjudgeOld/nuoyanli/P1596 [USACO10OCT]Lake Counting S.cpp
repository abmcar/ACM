#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

#define Maxn (int)1e3+10
using namespace std;

char bd[Maxn][Maxn];
int nextx[10] = {0,0,1,1,1,0,-1,-1,-1};
int nexty[10] = {0,1,1,0,-1,-1,-1,0,1};
int ans;
int l,r;

void bfs(int nowx,int nowy)
{
    queue<int> tx,ty;
    tx.push(nowx);
    ty.push(nowy);
    while (!tx.empty())
    {
        int nowx = tx.front();
        int nowy = ty.front();
        tx.pop();
        ty.pop();
        for(int i = 1; i <= 8; i++)
        {
            int nextxx = nowx + nextx[i];
            int nextyy = nowy + nexty[i];
            if(nextxx <= 0 || nextyy <= 0 || nextxx > l || nextyy > r)
                continue;
            if(bd[nextxx][nextyy] == 'W')
            {
                bd[nextxx][nextyy] = '.';
                tx.push(nextxx);
                ty.push(nextyy);
            }
        }
    }
    
}

int main()
{
    cin >> l >> r;
    for(int i = 1; i <= l; i++)
    for(int j = 1; j <= r; j++)
        cin >> bd[i][j];
    for(int i = 1; i <= l; i++)
    for(int j = 1; j <= r; j++)
        if(bd[i][j] == 'W')
            bfs(i,j),ans++;
    cout << ans;
    return 0;
}