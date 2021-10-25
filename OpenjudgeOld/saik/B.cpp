#include <iostream>
#define ll long long
using namespace std;

const int Maxn = 2333;
int f[Maxn][Maxn];
int n, ans, temp;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ans = 0;
        for (int j = 1; j <= n; j++)
        {
            cin >> temp;
            if (temp)
                f[i][j] = ans++;
            else
                f[i][j] = 1e9 + 10;
        }
    }
    for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
    {
        if (i != k)
        for (int j = 1; j <= n; j++)
            if (i != j && j != k)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    }
    if (f[1][n] == 1e9 + 10)
        f[1][n] = -1;
    cout << f[1][n];
    return 0;
}