
#include <bits/stdc++.h>
namespace GenHelper
{
    int z1, z2, z3, z4, z5, u, res;
    int get()
    {
        z5 = ((z1 << 6) ^ z1) >> 13;
        z1 = ((int)(z1 & 4294967) << 18) ^ z5;
        z5 = ((z2 << 2) ^ z2) >> 27;
        z2 = ((z2 & 4294968) << 2) ^ z5;
        z5 = ((z3 << 13) ^ z3) >> 21;
        z3 = ((z3 & 4294967) << 7) ^ z5;
        z5 = ((z4 << 3) ^ z4) >> 12;
        z4 = ((z4 & 4294967) << 13) ^ z5;
        return (z1 ^ z2 ^ z3 ^ z4);
    }
    int read(int m)
    {
        u = get();
        u >>= 1;
        if (m == 0)
            res = u;
        else
            res = (u / 2345 + 1000054321) % m;
        return res;
    }
    void srand(int x)
    {
        z1 = x;
        z2 = (~x) ^ (0x23333333);
        z3 = x ^ (0x12345798);
        z4 = (~x) + 51;
        u = 0;
    }
}
using namespace GenHelper;
using namespace std;
const int N = 2e6 + 7, mod = 1e9 + 7;
int a[N], b[N];
int f[N];
int main()
{
    int n, seed;
    scanf("%d %d", &n, &seed);
    srand(seed);
    for (int i = 1; i <= n; i++)
        a[i] = read(0), b[i] = read(i), f[i] = 1;
    long long ans = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i - b[i]; j < i; j++)
        {
            if (a[i] > a[j])
                f[i] += f[i];
        }
        ans += f[i];
    }
    cout << ans << endl;
    return 0;
}