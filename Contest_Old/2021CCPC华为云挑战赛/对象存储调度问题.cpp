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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t;
int n,m;
int a[Maxn], b[Maxn];

void work()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    __gnu_pbds::priority_queue<int,less<int> > Q;
    for (int i = 1; i <= m; i++)
        cin >> b[i], Q.push(b[i]);
    sort(a+1,a+1+n,greater<int>());
    // cout << a[1] << endl;
    bool ok = true;
    for (int i = 1; i <= n; i++)
    {
        if (Q.top() < a[i])
        {
            ok = false;
            break;
        }
        ll nowVal = Q.top() - a[i];
        Q.pop();
        Q.push(nowVal);
    }
    if (ok)
        cout << "Yes" << endl;
    else    
        cout << "No" << endl;
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