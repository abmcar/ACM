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

ll tot;
int n;
vector<int> Q1, Q2;
vector<int> QQ1, QQ2;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll temp;
        cin >> temp;
        if (temp < 0)
        {
            if (temp % 2)
                QQ1.push_back(temp);
            else
                QQ2.push_back(temp);
        }
        else
        {
            tot += temp;
            if (temp % 2)
                Q1.push_back(temp);
            else
                Q2.push_back(temp);
        }
    }
    sort(Q1.begin(), Q1.end());
    sort(Q2.begin(), Q2.end());
    sort(QQ1.begin(), QQ1.end());
    sort(QQ2.begin(), QQ2.end());
    if (tot % 2)
    {
        cout << tot << endl;
        return 0;
    }
    ll temp1 = (Q1.empty()) ? -1e10 : Q1[0]*-1;
    ll temp2 = (QQ1.empty()) ? -1e10 : QQ1[QQ1.size()-1];
    ll temp3 = max(temp1,temp2);
    if (temp3 == -1e10)
    {
        cout << -1 << endl;
        return 0;
    }
    tot += temp3;
    cout << tot << endl;
    return 0;
}