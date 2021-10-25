#include<iostream>
#include<algorithm>
#define MAXN (int)1e3+10

using namespace std;

int n,m,c;
long long bd[MAXN][MAXN],pre[MAXN][MAXN];
long long ans = -(int)1e15;
int finx,finy;

int main()
{
    cin >> n >> m >> c;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        cin >> bd[i][j];
    // cout << endl;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + bd[i][j];
    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= m; j++)
    //         cout << pre[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;
    for(int x = 1; x <= n-c+1; x++)
    for(int y = 1; y <= m-c+1; y++)
    {
        int x2 = x+c-1;
        int y2 = y+c-1;
        //cout << x << " " << y << " " << x2 << " " << y2 << " " << pre[x2][y2]-pre[x-1][y2]-pre[x2][y-1]-pre[x-1][y-1] << endl;
        if(ans < pre[x2][y2]-pre[x-1][y2]-pre[x2][y-1]+pre[x-1][y-1])
        {
            finx = x;
            finy = y;
            ans = pre[x2][y2]-pre[x-1][y2]-pre[x2][y-1]+pre[x-1][y-1];
        }
    }
    cout << finx << " " << finy;
    return 0;
}