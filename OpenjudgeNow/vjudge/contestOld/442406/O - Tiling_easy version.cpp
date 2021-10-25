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
const ll Mod = 1e9 + 7;

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
        for (int k = 0; k < mSize; k++)
            ans.setVal(i, j, (ans.getVal(i, j) + num[i][k] * b.getVal(k, j)) % Mod);
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

int t;
ll n;

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
    {
        cin >> n;
        Matrix nowMatrix(3);
        nowMatrix.setVal(0,0,1);
        nowMatrix.setVal(0,1,3);
        nowMatrix.setVal(0,2,5);
        Matrix muMatrix(3);
        muMatrix.setVal(1,0,1);
        muMatrix.setVal(2,1,1);
        muMatrix.setVal(1,2,2);
        muMatrix.setVal(2,2,1);
        nowMatrix = nowMatrix * quickPow(muMatrix,n-1);
        cout << nowMatrix.getVal(0,0) << Endl;
    }
    return 0;
}