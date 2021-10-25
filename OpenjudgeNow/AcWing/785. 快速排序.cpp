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

ll n, arr[Maxn];

void init(ll arr[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
}

void quickSort(ll arr[], ll l, ll r)
{
    if (l >= r) return;
    int nowl = l - 1;
    int nowr = r + 1;
    int baseNum = arr[(l + r) / 2];
    while(nowl < nowr)
    {
        do nowl++; while(arr[nowl] < baseNum);
        do nowr--; while(arr[nowr] > baseNum);
        if(nowl < nowr) swap(arr[nowl], arr[nowr]);
    }
    quickSort(arr, l, nowr), quickSort(arr, nowr + 1, r);
}

void print(ll arr[])
{
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    init(arr);
    quickSort(arr, 1, n);
    print(arr);
    return 0;
}