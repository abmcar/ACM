// #include <iostream>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <iomanip>
// #include <cmath>
// #include <ctime>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <climits>
// #include <ext/pb_ds/priority_queue.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#include <bits/extc++.h>
#include <bits/stdc++.h>
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

int n, t;

void work()
{
    unordered_map<int,int> M,Pos;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tempNum;
        cin >> tempNum;
        M[tempNum]++;
        Pos[tempNum] = i;
    }
    int ans = 1e9;
    int pos;
    for (auto it : M)
    {
        if (it.second == 1)
        {
            if (it.first < ans)
            {
                ans = it.first;
                pos = Pos[it.first];
            }
        }
    }
    if (ans == 1e9)
        pos = -1;
    cout << pos << endl;
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