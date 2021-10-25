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

const int Maxn = 10;
const ll Mod = 1e4;

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

int n;

int main()
{
    Buff;
    while (cin >> n)
    {
        if (n == -1)
            break;
        if (n == 0)
        {
            cout << "0" << endl;
            continue;
        }
        Matrix nowMatrix;
        nowMatrix.num[0][0] = 1;
        nowMatrix.num[0][1] = 1;
        nowMatrix.num[1][0] = 1;
        nowMatrix.size = 2;
        cout << quickPow(nowMatrix,n).num[0][1] << endl;
    }
    return 0;
}