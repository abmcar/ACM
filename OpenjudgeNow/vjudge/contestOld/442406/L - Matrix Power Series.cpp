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
#define Endl endl
// #define Debug

using namespace std;

const ll Maxn = 65;
ll Mod = 32768;

ll n, k, m;

struct Matrix
{
    ll num[Maxn][Maxn];
    ll size;
    Matrix const operator*(Matrix a) const
    {
        Matrix nowMatrix;
        nowMatrix.size = size;
        // memset(nowMatrix.num,0,sizeof(nowMatrix.num));
        for (ll i = 0; i < size; i++)
            for (ll j = 0; j < size; j++)
            {
                if (num[i][j])
                for (ll k = 0; k < size; k++)
                    nowMatrix.num[i][k] = (nowMatrix.num[i][k] + num[i][j] * a.num[j][k]) % Mod;
            }
        return nowMatrix;
    }
    Matrix()
    {
        memset(num, 0, sizeof(num));
    }
};
    // Matrix Muti(Matrix a, Matrix b)
    // {
    //     Matrix nowMatrix;
    //     nowMatrix.size = a.size;
    //     for (ll i = 0; i < a.size; i++)
    //         for (ll j = 0; j < a.size; j++)
    //         {
    //             nowMatrix.num[i][j] = 0;
    //             for (ll k = 0; k < a.size; k++)
    //                 nowMatrix.num[i][j] = (nowMatrix.num[i][j] + a.num[i][k] * b.num[k][j]) % Mod;
    //         }
    //     return nowMatrix;
    // }

Matrix quickPow(Matrix base, ll x)
{
    Matrix res;
    for (ll i = 0; i < 2 * n; i++)
        res.num[i][i] = 1;
    res.size = base.size;
    if (x == 0)
        return res;
    //     for (ll j = 0; j < 2*n; j++)
    // {
    // for (ll i = 0; i < 2*n; i++)
    //         cout << base.num[i][j] << " ";
    //     cout << endl;
    // }
    while (x)
    {
        if (x % 2 == 1)
        {
            res = res * base;
            // res = Muti(res, base);
            x--;
        }
        base = base * base;
        // base = Muti(base, base);
        x = x / 2;
    }
    return res;
}

int main()
{
    // Buff;
// #ifdef Debug
//     freopen("temp.in", "r", stdin);
//     freopen("temp.out", "w", stdout);
// #endif

    // cin >> n >> k >> m;
    scanf("%lld %lld %lld",&n,&k,&m);
    Mod = m;
    Matrix nowMatrix, muMatrix;
    nowMatrix.size = muMatrix.size = 2 * n;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
        {
            // cin >> nowMatrix.num[i][j], muMatrix.num[i][j] = nowMatrix.num[i][j];
            scanf("%lld",&nowMatrix.num[i][j]);
            nowMatrix.num[i][j] = nowMatrix.num[i][j] % Mod;
            muMatrix.num[i][j] = nowMatrix.num[i][j];

        }

    for (ll i = 0; i < n; i++)
        for (ll j = n; j < 2 * n; j++)
            muMatrix.num[i][j] = 0;
    for (ll i = n; i < 2 * n; i++)
        for (ll j = 0; j < n; j++)
            muMatrix.num[i][j] = nowMatrix.num[i - n][j];
    for (ll i = n; i < 2 * n; i++)
        muMatrix.num[i][i] = 1;
    for (ll i = 0; i < n; i++)
        nowMatrix.num[i][i + n] = 1;

    nowMatrix = nowMatrix * quickPow(muMatrix, k - 1);
    // nowMatrix = Muti(nowMatrix, quickPow(muMatrix, k - 1));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
            printf("%lld ",nowMatrix.num[i][j]);
            // cout << nowMatrix.num[i][j] << " ";
        // cout << Endl;
        printf("\n");
    }
    return 0;
}