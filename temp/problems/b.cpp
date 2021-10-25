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
// #include <ext/pb_ds/priority_queue.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
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

int t, n, k;

void work()
{
    cin >> n >> k;
    priority_queue<int,vector<int>,greater<int> > Q;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        Q.push(temp);
    }
    // cout << Q.top() << endl;
    for (int i = 1; i <= k; i++)
    {
        int t1 = Q.top();
        Q.pop();
        int t2 = Q.top();
        Q.pop();
        Q.push(t1+t2);
    }
    cout << Q.top() << endl;
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.out", "w", stdout);
    freopen("temp.in", "r", stdin);
#endif
    cin >> t;
    while (t--)
        work();
    // cout << 10000 << endl;
    // for (int i = 1; i <= 10000; i++)
    // {
    //     cout << "NO" << endl;
    //     // cout << 10 << Endl;
    //     // cout << "4 1 4 1 4 1 2 1 2 2" << endl;
    // }
    return 0;
}