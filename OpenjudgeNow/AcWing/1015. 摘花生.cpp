#include <algorithm>
#include <iostream>
#include <cstring>
#define Maxn (int)123

using namespace std;

int t;
int bd[Maxn][Maxn];
int f[Maxn][Maxn];
int r,c;

void work()
{
    cin >> r >> c;
    for(int i = 1; i <= r; i++)
    for(int j = 1; j <= c; j++)
        cin >> bd[i][j];
    memset(f,0,sizeof(f));
    for(int i = 1; i <= r; i++)
    for(int j = 1; j <= c; j++)
        f[i][j] = max(f[i-1][j],f[i][j-1])+bd[i][j];
    cout << f[r][c] << endl;
}

int main()
{
    cin >> t;
    for(int i = 1; i <= t; i++)
        work();
    return 0;
}