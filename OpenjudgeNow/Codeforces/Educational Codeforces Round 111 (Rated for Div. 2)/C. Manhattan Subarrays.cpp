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

const int Maxn = 1e6 + 10;
const ll Mod = 1e9 + 7;

int t, n;
int num[Maxn];

int check(int l, int r)
{
    int t1 = num[l];
    int t2 = num[l + 1];
    int t3 = num[l + 2];
    int t4 = num[l + 3];
    if (r - l == 3)
    {
        if ((t1 <= t2 && t2 <= t3) || (t1 >= t2 && t2 >= t3))
            return 0;
        else
            return 1;
    }
    if (
        //123 124 134 234
        (t1 <= t2 && t2 <= t3) || (t1 <= t3 && t3 <= t4) || (t2 <= t3 && t3 <= t4) || (t1 <= t2 && t2 <= t4) ||
        (t1 >= t2 && t2 >= t3) || (t1 >= t3 && t3 >= t4) || (t2 >= t3 && t3 >= t4) || (t1 >= t2 && t2 >= t4)
        )
        return 0;
    // cout << l << " " << r << "     1" << endl;
    return 1;
}

void work()
{
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    for (int size = 1; size <= 4; size++)
        for (int i = 1; i + size - 1 <= n; i++)
        {
            if (size == 1 || size == 2)
                ans++;
            else
                ans += check(i, i + size);
        }
    cout << ans << endl;
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}