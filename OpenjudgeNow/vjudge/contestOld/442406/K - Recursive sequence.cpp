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
// #define Debug

using namespace std;

const int Maxn = 123;
const ll Mod = 2147493647;

ll t, n, a, b;

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
    Matrix()
    {
        memset(num, 0, sizeof(num));
    }
};

Matrix quickPow(Matrix base, ll x)
{
    Matrix res;
    res.size = base.size;
    res.num[0][0] = 1;
    res.num[1][0] = 1;
    res.num[1][1] = 1;
    res.num[2][0] = 1;
    res.num[2][1] = 2;
    res.num[2][2] = 1;
    res.num[3][0] = 1;
    res.num[3][1] = 3;
    res.num[3][2] = 3;
    res.num[3][3] = 1;
    res.num[4][0] = 1;
    res.num[4][1] = 4;
    res.num[4][2] = 6;
    res.num[4][3] = 4;
    res.num[4][4] = 1;
    res.num[5][6] = 1;
    res.num[6][7] = 1;
    res.num[7][6] = 2;
    res.num[7][7] = 1;
    res.num[7][4] = 1;
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
    #ifdef Debug
        freopen("temp.in","r",stdin);
        freopen("temp.out","w",stdout);
    #endif
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b;
        Matrix nowMatrix;
        nowMatrix.size = 8;
        nowMatrix.num[0][0] = 1;
        nowMatrix.num[1][0] = 4;
        nowMatrix.num[2][0] = 16;
        nowMatrix.num[3][0] = 64;
        nowMatrix.num[4][0] = 256;
        nowMatrix.num[5][0] = a;
        nowMatrix.num[6][0] = b;
        // cout << nowMatrix.num[6][0] << endl;
        nowMatrix.num[7][0] = 2*a+b+81;
        // cout << nowMatrix.num[7][0] << endl;
        if (n == 1)
        {
            cout << a << endl;
            continue;
        }
        if (n == 2)
        {
            cout << b << endl;
            continue;
        }
        if (n == 3)
        {
            cout << 2*a+b+81 << endl;
            continue;
        }
        cout << quickPow(nowMatrix, n-3).num[7][0] << endl;
    }
    return 0;
}