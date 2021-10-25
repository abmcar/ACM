#include<iostream>
#include<algorithm>

using namespace std;

int n;
int bd[233][233];
int pre[233][233];
int ans;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
        cin >> bd[i][j];
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
        pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + bd[i][j];
    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= n; j++)
    //         cout << pre[i][j] << " ";
    //     cout << endl;
    // }
    for(int x2 = 1; x2 <= n; x2++)
    for(int y2 = 1; y2 <= n; y2++)
    for(int x1 = 1; x1 <= x2; x1++)
    for(int y1 = 1; y1 <= y2; y1++)
        ans = max(ans,pre[x2][y2]-pre[x2][y1-1]-pre[x1-1][y2]+pre[x1-1][y1-1]);
    cout << ans;
    return 0;
}