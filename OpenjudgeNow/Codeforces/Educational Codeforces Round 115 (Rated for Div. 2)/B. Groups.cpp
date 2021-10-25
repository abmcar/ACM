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
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n;
set<int> lesson[5];

void work()
{
    cin >> n;
    for (int i = 1; i <= 5; i++)
        lesson[i].clear();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            int temp;
            cin >> temp;
            if (temp == 1)
                lesson[j].insert(i);
        }
    }
    bool ok = false;
    for (int i = 1; i <= 5; i++)
        for (int j = i + 1; j <= 5; j++)
        {
            if (lesson[i].size() >= n/2 && lesson[j].size() >= n/2)
            {
                set<int> nowSet;
                for (auto now : lesson[i])
                    nowSet.insert(now);
                for (auto now : lesson[j])
                    nowSet.insert(now);
                if (nowSet.size() == n)
                    ok = true;
            }
        }
    if (ok)
        cout << "YES" << endl;
    else    
        cout << "NO" << endl;
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