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
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll unsigned long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e5 + 10;
const ll Mod = 998244353;

int n;
ll a[Maxn], b[Maxn];
ll totb;

int main()
{
    Buff;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 2; i <= n; i++)
        totb = (totb + b[i]) % Mod;
    for (int i = 1; i <= 3; i++)
    {
        ll nowNum = 0;
        if (i == 1)
        for (int j = 2; j <= n; j++)
        {
            nowNum = nowNum + a[j]*totb%Mod;
            if (nowNum % Mod != 0)
                nowNum = nowNum % Mod;
        }
        if (i == 2)
        {
            nowNum = a[1]*b[1];
            if (nowNum % Mod != 0)
                nowNum = nowNum % Mod;
            for (int j = 3; j <= n; j++)
            {
                nowNum = nowNum + (b[1]*a[j])%Mod + (a[1]*b[j])%Mod;
                if (nowNum % Mod != 0)
                    nowNum = nowNum % Mod;
            }
        }
        if (i == 3)
            nowNum = a[1]*b[2] + b[1]*a[2];
        if (nowNum % Mod != 0)
            nowNum = nowNum % Mod;
        cout << nowNum << " ";
    }
    for (int i = 4; i <= n; i++)
        cout << "0 ";
    return 0;
}
/*
c0 = a1*(b1+b2+b3+...+bn) + a2*(b1+b2+b3+...+bn) +....
c1 = a0*(b2+b3+b4+...+bn) + b0*(a2+..+an)
c2 = a0*b1 + a1*b0
*/