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
// #include <bits/extc++.h>
#include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
// #define endl "\n"
// #define Endl "\n"
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;
map<int,int> M;
int t = 1, n;

void pre()
{
M[6 ]  =  6;
M[28]  =  28;
M[220  ] = 284;
M[284  ] = 220;
M[496  ] = 496;
M[1184 ] = 1210;
M[1210 ] = 1184;
M[2620 ] = 2924;
M[2924 ] = 2620;
M[5020 ] = 5564;
M[5564 ] = 5020;
M[6232 ] = 6368;
M[6368 ] = 6232;
M[8128 ] = 8128;
M[10744] = 10856;
M[10856] = 10744;
M[12285] = 14595;
M[14595] = 12285;
M[17296] = 18416;
M[18416] = 17296;
M[63020] = 76084;
M[66928] = 66992;
M[66992] = 66928;
M[67095] = 71145;
M[69615] = 87633;
M[71145] = 67095;
M[76084] = 63020;
M[79750] = 88730;
M[87633] = 69615;
M[88730] = 79750;
}

int l , r;

int main()
{
    Buff;
    pre();
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    // while (t--)
    //     work();
    cin >> l >> r;
    for (auto i : M)
    {
        if (i.first == i.second)
            continue;
        if (i.first >= l && i.second <= r)
        if (i.second >= l && i.second <= r)
        {
            cout << i.first << " " << i.second << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}