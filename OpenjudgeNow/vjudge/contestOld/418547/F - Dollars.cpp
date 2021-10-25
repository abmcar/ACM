#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <iomanip>
#define ll long long

using namespace std;

const int Maxn = 30010;
const ll Mod = 1e9+7;
double n;
int v[12] = {0,10000,5000,2000,1000,500,200,100,50,20,10,5};
ll f[Maxn];

int main()
{
    std::ios::sync_with_stdio(false);
    f[0] = 1;
    for(int i = 1; i <= 11; i++)
    for(int j = v[i]; j <= Maxn; j++)
        f[j] += f[j-v[i]];
    while(cin >> n)
    {
        if(n == 0)
            return 0;
        printf("%6.2lf%17lld\n",n,f[(int)(n*100+0.5)]);
        // cout << fixed << setprecision(2) << n << setprecision(0) << setw(17) << f[(int)(n*100+0.5)] << endl;
    }
    return 0;
}