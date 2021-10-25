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

ll t, a, b;

void work()
{
    cin >> a >> b;
    ll totNum = a + b;
    set<int> Ans;
    int maxn = 2*min(a,b);
    int d = abs(a-b) / 2;
    int d1 = (abs(a-b)+1) / 2;
    // cout << "   "<< maxn << Endl;
    while (maxn >= 0)
    {
        Ans.insert(maxn+d1);
        Ans.insert(maxn+d);
        maxn = maxn - 2;
    }
    // reverse(Ans.begin(),Ans.end());
    // unique(Ans.begin(),Ans.end());
    cout << Ans.size() << endl;
    for (int i : Ans)
        if (i >= 0)
        cout << i << " ";
    cout << endl;
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