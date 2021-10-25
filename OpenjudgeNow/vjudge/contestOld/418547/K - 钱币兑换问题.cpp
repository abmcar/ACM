#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#define ll long long

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
long long f[Maxn];
int coins[6] = {0,1,2,3};
int n;

int main()
{
    std::ios::sync_with_stdio(false);
    f[0] = 1;
    for(int i = 1; i <= 3; i++)
    for(int j = coins[i]; j <= 1e5; j++)
        f[j] += f[j-coins[i]];
    while(cin >> n)
        cout << f[n] << endl;
    return 0;
}