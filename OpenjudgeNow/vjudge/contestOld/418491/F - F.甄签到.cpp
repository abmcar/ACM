#include<iostream>
#include<algorithm>
#include<string>
#define Maxn (int)267
using namespace std;

int t,n;
char bd[5][Maxn];
int ans;
int nx[8] = {0,1,0,-1,1,1,-1,-1};
int ny[8] = {1,0,-1,0,-1,1,1,-1};

void get()
{
    cin >> n;
    for(int i = 1; i <= 3; i++)
    for(int j = 1; j <= 3*n; j++)
        cin >> bd[i][j];
}

int find(int strx,int stry)
{
    int nowans = 0;
    for(int i = 0; i < 8; i++)
    {
        int nextx = strx + nx[i];
        int nexty = stry + ny[i];
        if(bd[nextx][nexty] == '*')
            nowans += 4;
    }
    return nowans;
}

void clear()
{
    for(int i = 0; i <= 3; i++)
    for(int j = 0; j <= 3*n+1; j++)
        bd[i][j] = '.';
}

void work()
{
    clear();
    get();
    ans = 0;
    int i = 2;
    for(int j = 1; j <= 3*n; j++)
    {
        if(j % 3 == 0)
        {
            if(bd[2][j-1] == '*')
                ans = max(ans,find(i,j-1)+4);
            else
                ans = max(ans,find(i,j-1));
        }
    }
    cout << ans << endl;
}

int main()
{
    cin >> t;
    for(int i = 1; i <= t; i++)
        work();
    return 0;
}