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
const ll Mod = 10007;

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
                for (ll k = 0; k < size; k++)
                    nowMatrix.num[i][j] = (nowMatrix.num[i][j] + (num[i][k]%Mod) * (a.num[k][j] % Mod)) % Mod;
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
ll n, X, Y;

Matrix quickPow(Matrix base, ll x)
{
    Matrix res;
    res.num[0][0] = 1;
    res.num[0][1] = 1;
    res.num[0][2] = 1;
    res.num[0][3] = 1;
    res.size = 4;
    base.size = 4;
    base.num[0][0] = 1;
    base.num[1][0] = 1;
    base.num[1][1] = X*X;
    base.num[1][2] = 1;
    base.num[1][3] = X;
    base.num[2][1] = Y*Y;
    base.num[3][1] = 2*X*Y;
    base.num[3][3] = Y;
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
    cout << quickPow(nowMatrix,n).num[0][0]%Mod << endl;
}

int main()
{
    // Buff;
    while (cin >> n >> X >> Y)
        work();
    return 0;
}