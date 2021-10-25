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
#define Endl "\n"
// #define Debug

using namespace std;

const int Maxn = 123;
ll Mod = 1e9 + 7;

class Matrix
{
private:
    ll num[Maxn][Maxn];
    ll mSize;

public:
    Matrix(int size, int type = 0);
    int size();
    ll getVal(int x, int y);
    void setVal(int x, int y, ll val);
    Matrix const operator*(Matrix b) const
    {
        Matrix ans(mSize);
        for (int i = 0; i < mSize; i++)
            for (int j = 0; j < mSize; j++)
            {
                if (num[i][j])
                for (int k = 0; k < mSize; k++)
                    ans.setVal(i, k, (ans.getVal(i, k) + num[i][j] * b.getVal(j, k) + 1000*Mod)%Mod);
            }
        return ans;
    }
};

Matrix::Matrix(int size, int type)
{
    mSize = size;
    memset(num, 0, sizeof(num));
    if (type == 0)
        return;
    for (int i = 0; i < mSize; i++)
        num[i][i] = 1;
}

int Matrix::size()
{
    return mSize;
}

ll Matrix::getVal(int x, int y)
{
    return num[x][y];
}

void Matrix::setVal(int x, int y, ll val)
{
    num[x][y] = val;
}

Matrix quickPow(Matrix base, int x)
{
    Matrix res(base.size(), 1);
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

ll n, m;

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    while (cin >> n >> m)
    {
        if (n + m == 0)
            break;
        Mod = m;
        Matrix nowMatrix(4), muMatrix(4);
        nowMatrix.setVal(0,0,1);
        nowMatrix.setVal(0,1,5);
        nowMatrix.setVal(0,2,11);
        nowMatrix.setVal(0,3,36);
        muMatrix.setVal(0,3,-1);
        muMatrix.setVal(1,0,1);
        muMatrix.setVal(1,3,1);
        muMatrix.setVal(2,1,1);
        muMatrix.setVal(2,3,5);
        muMatrix.setVal(3,2,1);
        muMatrix.setVal(3,3,1);
        nowMatrix = nowMatrix * quickPow(muMatrix, n-1);
        cout << nowMatrix.getVal(0,0) << Endl;
    }
    return 0;
}