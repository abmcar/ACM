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
#define Endl endl

using namespace std;

const int Maxn = 123;
const ll Mod = 9973;

struct Matrix
{
    ll num[Maxn][Maxn];
    ll size;
    Matrix const operator*(Matrix a) const
    {
        Matrix nowMatrix;
        nowMatrix.size = size;
        for (ll i = 0; i < size; i++)
            for (ll j = 0; j < size; j++)
            {
                nowMatrix.num[i][j] = 0;
                for (ll k = 0; k < size; k++)
                    nowMatrix.num[i][j] = (nowMatrix.num[i][j] + ((num[k][j]%Mod) * (a.num[i][k]%Mod))%Mod) % Mod;
            }
        return nowMatrix;
    }
    Matrix(ll nowSize)
    {
        size = nowSize;
        memset(num, 0, sizeof(num));
        for (ll i = 0; i < nowSize; i++)
            num[i][i] = 1;
    }
    Matrix()
    {
        memset(num, 0, sizeof(num));
    }
};

Matrix quickPow(Matrix base, ll x)
{
    if (x == 0)
        return Matrix(base.size);
    Matrix res = base;
    while (x)
    {
        if (x % 2 == 1)
        {
            base = base * res;
            x--;
        }
        res = res * res;
        x = x / 2;
    }
    return base;
}

int t, n, k;

int main()
{
    Buff;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        Matrix nowMatrix;
        nowMatrix.size = n;
        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> nowMatrix.num[i][j];
        Matrix ans = quickPow(nowMatrix, k-1);
        int numAns = 0;
        for (int i = 0; i < n; i++)
            numAns = (numAns + ans.num[i][i]) % Mod;
        cout << numAns << endl;
    }
    return 0;
}