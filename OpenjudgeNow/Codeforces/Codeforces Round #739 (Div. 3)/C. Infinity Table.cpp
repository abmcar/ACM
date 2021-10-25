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
#include <unordered_map>
#include <unordered_set>
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
#define String string
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const ll Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll t, n;
ll totNum;
ll tempNum[Maxn];

void work()
{
    cin >> n;
    for (ll i = 1; i <= totNum; i++)
    {
        if (tempNum[i] == n)
        {
            cout << i << " 1" << endl;
            return;
        }
        if (n < tempNum[i+1])
        {
            ll d = n - tempNum[i];
            if (d <= i)
            {
                cout << d << " " << i+1 << endl;
                return;
            }else
            {
                cout << i+1 << " " << i*2-d+2 << endl;
                return;
            }
        }
    }
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    for (ll i = 1; i*i <= 2e9; i++)
    {
        tempNum[i] = i*i;
        totNum = i;
    }
    cin >> t;
    while(t--)
        work();
    return 0;
}