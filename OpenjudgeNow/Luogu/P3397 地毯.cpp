#include<iostream>
#include<algorithm>

using namespace std;

int bd[2333][2333];
int pre[2333][2333];
int n,m;
int now;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1; i <= x2; i++)
            pre[i][y1]++,pre[i][y2+1]--;
    }
    for(int i = 0; i <= n+1; i++)
    for(int j = 0; j <= n+1; j++)
    {
        now+=pre[i][j];
        bd[i][j]+=now;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << bd[i][j] << " ";
        cout << endl;
    }
    return 0;
}