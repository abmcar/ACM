#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 123;
const ll Mod = 1000;

int n, m, t;

struct Matrix
{
    int num[Maxn][Maxn];
    int size;
    Matrix const operator*(Matrix a) const
    {
        Matrix nowMatrix;
        nowMatrix.size = size;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
            {
                for (int k = 0; k < size; k++)
                    nowMatrix.num[i][j] = (nowMatrix.num[i][j] + num[i][k] * a.num[k][j] % Mod) % Mod;
            }
        return nowMatrix;
    }
    Matrix(int nowSize)
    {
        size = nowSize;
        memset(num, 0, sizeof(num));
        for (int i = 0; i < nowSize; i++)
            num[i][i] = 1;
    }
    Matrix()
    {
        memset(num, 0, sizeof(num));
    }
};

Matrix quickPow(Matrix base, int x)
{
    Matrix res(base.size);
    while (x)
    {
        if (x % 2 == 1)
        {
            res = res * base;
            x--;
        }
        base = base * base;
        x = x / 2;
    }
    return res;
}

void work()
{
    Matrix nowMatrix;
    nowMatrix.size = n;
    while (m--)
    {
        int t1, t2;
        cin >> t1 >> t2;
        nowMatrix.num[t1][t2] = 1;
    }
    cin >> t;
    while (t--)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        Matrix ans = quickPow(nowMatrix, t3);
        // ans.size = nowMatrix.size;
        // for (int i = 0; i < ans.size; i++)
        // {
        //     for (int j = 0; j < ans.size; j++)
        //         cout << ans.num[i][j] << " ";
        //     cout << endl;
        // }
        cout << ans.num[t1][t2]%Mod << endl;
    }
}

int main()
{
    Buff;
    while (cin >> n >> m)
    {
        if (n + m == 0)
            break;
        work();
    }
    return 0;
}