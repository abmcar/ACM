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

int t, n, k;
int arr[Maxn];
map<int,int> M,MP;

void work()
{
    M.clear();
    MP.clear();
    int nowK = 1;
    int nowValue = 2e9;
    cin >> n >> k;
    for (int i = 1;i <= n; i++)
        cin >> arr[i], M[arr[i]] = 1;
    int res = 0;
    for (auto it : M)
        MP[it.first] = ++res;
    for (int i = 1; i < n; i++)
    {
        if (MP[arr[i]] != MP[arr[i+1]] - 1)
        {
            nowK++;
        }
    }
    if (nowK <= k)
        cout <<"Yes" << endl;
    else    
        cout << "No" << endl;
    // cout << nowK << endl;
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