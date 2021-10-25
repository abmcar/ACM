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
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int d[Maxn];
int ans[Maxn];
int t;
int main()
{
    Buff;
    for (int i = 1; i <= Maxn; i++)
    for (int j = i; j <= Maxn; j += i)
            d[j] += i;
    for (int i = 1; i <= Maxn; i++)
    {
        if (d[i] > Maxn)
            continue;
        if (ans[d[i]])
            ans[d[i]] = min(ans[d[i]], i);
        else
            ans[d[i]] = i;
    }
    cin >> t;
    while (t--)
    {
        int temp;
        cin >> temp;
        if (ans[temp])
            cout << ans[temp] << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}