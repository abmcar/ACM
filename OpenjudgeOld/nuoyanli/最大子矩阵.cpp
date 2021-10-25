#include<iostream>
#include<algorithm>

using namespace std;

int t;
int n,m,x,y;
int bd[1234][1234];
long long pre[1234][1234];

inline void work()
{
    cin >> n >> m >> x >> y;
    long long ans = -1e15;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    {
        cin >> bd[i][j];
        pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + bd[i][j];
    }
    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= m; j++)
    //         cout << pre[i][j] << " ";
    //     cout << endl;
    // }
    for(int i = 1; i <= n-x+1; i++)
    for(int j = 1; j <= m-y+1; j++)
    {
        int x1 = i+x-1;
        int y1 = j+y-1;
        if(pre[x1][y1]-pre[i-1][y1]-pre[x1][j-1]+pre[i-1][j-1] > ans)
            ans = pre[x1][y1]-pre[i-1][y1]-pre[x1][j-1]+pre[i-1][j-1];
        //ans = max(ans,pre[x1][y1]-pre[i-1][y1]-pre[x1][j-1]+pre[i-1][j-1]);
    }
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    for(int i = 1; i <= t; i++)
        work();
    return 0;
}