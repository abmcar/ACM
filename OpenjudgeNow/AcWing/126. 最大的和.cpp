#include <iostream>
#include <algorithm>
#include <cstring>
#define Maxn 123

using namespace std;

int n;
int bd[Maxn][Maxn];
int preans[Maxn][Maxn];
int ans = -1e8;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
        cin >> bd[i][j];
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
        preans[i][j] = preans[i-1][j] + preans[i][j-1] - preans[i-1][j-1] + bd[i][j];
    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= n; j++)
    //         cout << preans[i][j] << " ";
    //     cout << endl;
    // }
    for(int strx = 1; strx <= n; strx++)
    for(int stry = 1; stry <= n; stry++)
    for(int endx = strx; endx <= n; endx++)
    for(int endy = stry; endy <= n; endy++)
    {
        int nowans = preans[endx][endy] - preans[strx-1][endy] - preans[endx][stry-1] + preans[strx-1][stry-1];
        // cout << nowans << endl;
        ans = max(nowans,ans);
    }
    cout << ans;
    return 0;
}