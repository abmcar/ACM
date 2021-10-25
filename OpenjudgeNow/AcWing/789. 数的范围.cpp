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

int n, q, k;
int arr[Maxn];

// int bound(int val, int l, int r)
// {
//     if (l == r && arr[l] != val) return -1;
//     int mid = (l + r) / 2;
//     if (arr[mid] == val)
//         return mid;
//     if (arr[mid] < val)
//         return bound(val, mid + 1, r);
//     return bound(val, l, mid - 1);
// }

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= q; i++)
    {
        cin >> k;
        int pos1 = lower_bound(arr + 1, arr + 1 + n, k) - (arr+1);
        int pos2 = upper_bound(arr + 1, arr + 1 + n, k) - (arr+1) -1;
        pos2 = min(pos2,n-1);
        if (pos1 >= n || arr[pos1+1] != k)
            pos1 = pos2 = -1;
        cout << pos1 << " " << pos2 << endl;
    }
    return 0;
}