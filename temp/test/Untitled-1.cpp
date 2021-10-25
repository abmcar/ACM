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

// #include "M/test.cpp"
// import "M/test.cpp";

using namespace std;
using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int atk[123], heal[123];

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    freopen("temp.out", "w", stdout);
    // test t = *(new test());
    // test t1();
    // test t2(2);
    for (int i = 1; i <= 100; i++)
        cin >> atk[i];
    for (int i = 1; i <= 100; i++)
        cin >> heal[i];
    for (int i = 1; i <= 100; i++)
    {
        cout << "  "<< i << ":" << endl;
        cout << "  - \"物理伤害: +{" << atk[i] << "|" << atk[i] << "} @100\"" << endl;
        cout << "  - \"生命力: +{" << heal[i] << "|" << heal[i] << "} @100\"" << endl;
        // cout << "  - \"生命力: +" << heal[i] << " @100\"" << endl;;
    }
    return 0;
}