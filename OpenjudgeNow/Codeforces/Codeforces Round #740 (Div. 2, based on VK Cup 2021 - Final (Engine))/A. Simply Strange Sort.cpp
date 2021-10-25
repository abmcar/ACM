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

const int Maxn = 1e4 + 10;
const ll Mod = 1e9 + 7;

int t, n;
int num[Maxn];
int finNum[Maxn];

bool check()
{
    for (int i = 1; i <= n; i++)
        if (finNum[i] != num[i])
            return false;
    return true;
}

void work()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i], finNum[i] = num[i];
    sort(finNum+1,finNum+1+n);
    int res = 0;
    while (1)
    {
        // cout << res << Endl;
        if (check())
        {
            cout << res << endl;
            return;
        }
        res++;
        if (res % 2 == 0)
        {
            for (int i = 2; i <= n-1; i = i + 2)
                if (num[i] > num[i+1])
                    swap(num[i],num[i+1]);
        }else
        {
            for (int i = 1; i <= n-2; i = i + 2)
                if (num[i] > num[i+1])
                    swap(num[i],num[i+1]);
        }
        if (check())
        {
            cout << res << endl;
            return;
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
    cin >> t;
    while (t--)
        work();
    return 0;
}