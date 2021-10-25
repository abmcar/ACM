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

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

int t, n;
int num[Maxn];

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
        bool ok = true;
        cin >> n;
        double ans = sqrt(n);
        int fans;
        if (ans - (int)ans > 0)
            fans = (int)ans+1;
        else
            fans = (int)ans;
        cout << fans << Endl;
    }
    return 0;
}