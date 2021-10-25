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

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

int health[Maxn], mexp[Maxn], damage[Maxn], money[Maxn];

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    for (int i = 1; i <= 100; i++)
        cin >> mexp[i];
    for (int i = 1; i <= 100; i++)
        cin >> damage[i];
    for (int i = 1; i <= 100; i++)
        cin >> health[i];
    for (int i = 1; i <= 100; i++)
        cin >> money[i];
    for (int i = 1; i <= 100; i++)
    {
        cout << i << ":" << endl;
        cout << "  health: " << health[i] << endl;
        cout << "  damage: " << damage[i] << endl;
        cout << "  exp: " << mexp[i] << endl;
        cout << "  money: " << money[i] << endl;
    }
    return 0;
}