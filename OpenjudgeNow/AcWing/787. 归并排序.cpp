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

int n;
int arr[Maxn];

void mergeSort(int arr[], int l, int r)
{
    // cout << l << " " << r << endl;
    if (r <= l)
        return;
    int mid = (l + r) / 2;
    int nowl = l;
    int nowr = mid + 1;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    vector<int> V;
    // cout << mid << " " << nowl << " " << nowr << endl;
    for (int k = l; k <= r; k++)
    {
        // cout << nowl << " " << nowr <<  " " << arr[nowl] << " " << arr[nowr] << endl;
        if ((arr[nowl] < arr[nowr] && nowl != mid + 1) || nowr == r + 1)
        {
            V.push_back(arr[nowl]);
            nowl++;
        }
        else
        {
            V.push_back(arr[nowr]);
            nowr++;
        }
    }
    for (int i = l; i <= r; i++)
        arr[i] = V[i - l];
}

void print(int arr[], int l, int r)
{
    for (int i = l; i <= r; i++)
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
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    mergeSort(arr, 1, n);
    print(arr, 1, n);
    return 0;
}