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
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
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

int t, n, ans;
string r1, rn;

void work()
{
    ans = 0;
    cin >> n >> r1 >> rn;
    for (int i = 0; i < n; i++)
    {
        if (rn[i] == '1')
        {
            if (i > 0)
                if (r1[i - 1] == '1')
                {
                    r1[i - 1] = '2';
                    ans++;
                    continue;
                }
            if (r1[i] == '0')
            {
                r1[i] = '2';
                ans++;
                continue;
            }
            if (i < n - 1)
                if (r1[i + 1] == '1')
                {
                    r1[i + 1] = '2';
                    ans++;
                    continue;
                }
        }
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