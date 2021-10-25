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
#define Inf ll_MAX
#define endl "\n"

using namespace std;

const ll Maxn = 10;
const ll Mod = 1e9 + 7;

ll t, n;

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
        // for (ll i = 0; i < nowSize; i++)
        //     num[i][i] = 1;
    }
    Matrix()
    {
        memset(num, 0, sizeof(num));
    }
};

Matrix quickPow(Matrix base, ll x)
{
    Matrix res(base.size);
    res.num[0][1] = 1;
    res.num[1][2] = 1;
    res.num[2][3] = 1;
    res.num[3][1] = 1;
    res.num[3][3] = 1;
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

int main()
{
    Buff;
    cin >> t;
    while (t--)
    {
        cin >> n;
        Matrix nowMatrix;
        nowMatrix = 4;
        nowMatrix.num[0][0] = 2;
        nowMatrix.num[1][0] = 3;
        nowMatrix.num[2][0] = 4;
        nowMatrix.num[3][0] = 6;
        cout << quickPow(nowMatrix,n-1).num[0][0] << endl;
    }
    return 0;
}