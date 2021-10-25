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
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll t, n;
ll ans[Maxn], minn;

void work()
{
    minn = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> ans[i];
    for (int l = 1; l <= n; l++)
    for (int r = l; r <= n; r++)
    for (int i = 0; i <= r-l; i++)
        ans[l+i] = min(ans[l+i],ans[l+i] & ans[r-i]);
    for (int i = 1; i <= n; i++)
        minn = max(minn, ans[i]);
    cout << minn << endl;
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