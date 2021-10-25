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
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const ll Maxn = 100010;
const ll Mod = 1e9 + 7;

ll n;
unsigned long long res;
int arr[Maxn];

void mergeSort(ll l, ll r)
{
    // cout << l << " " << r << endl;
    if (r <= l)
        return;
    ll mid = (l + r) / 2;
    ll nowl = l;
    ll nowr = mid + 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    vector<ll> V;
    // cout << mid << " " << nowl << " " << nowr << endl;
    while (nowl <= mid && nowr <= r)
    {
        // cout << nowl << " " << nowr <<  " " << arr[nowl] << " " << arr[nowr] << endl;
        if (arr[nowl] <= arr[nowr])
        {
            V.push_back(arr[nowl]);
            nowl++;
        }
        else
        {
            V.push_back(arr[nowr]);
            nowr++;
            res = res + (mid - nowl + 1LL);
            // if (res > 1499304400)
            //     cout << "1231            2" << endl;
        }
    }
    while (nowl <= mid)
    {
        V.push_back(arr[nowl]);
        nowl++;
    }
    while (nowr <= r)
    {
        V.push_back(arr[nowr]);
        nowr++;
    }
    for (ll i = l; i <= r; i++)
        arr[i] = V[i - l];
}

// void mergeSort(int array[], int l, int r)
// {
//     if (l >= r)
//         return;
//     int mid = (l + r) / 2;
//     mergeSort(array, l, mid);
//     mergeSort(array, mid + 1, r);
//     int temp[r - l + 1];
//     int lptr = l;
//     int rptr = mid + 1;
//     int tempptr = 0;
//     while (lptr <= mid && rptr <= r)
//     {
//         if (array[lptr] <= array[rptr])
//         {
//             temp[tempptr++] = array[lptr++];
//         }
//         else
//         {
//             temp[tempptr++] = array[rptr++];
//             res += (mid - lptr + 1); //注意这里，是直接加的，后面的不需要比较了。
//         }
//     }
//     while (lptr <= mid)
//     {
//         temp[tempptr++] = array[lptr++];
//     }
//     while (rptr <= r)
//     {
//         temp[tempptr++] = array[rptr++];
//     }
//     for (int i = l, j = 0; i <= r; i++, j++)
//     {
//         array[i] = temp[j];
//     }
// }

void prll(ll l, ll r)
{
    for (ll i = l; i <= r; i++)
        cout << arr[i] << " ";
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> arr[i];
    mergeSort( 1, n);
    // prll(n - 1000, n);
    // cout << endl;
    cout << res << endl;
    return 0;
}