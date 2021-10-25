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
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t;
ll l, r;

void work()
{
    cin >> l >> r;
    ll min = l;
    ll max = r;
    int i = 0;
    while ((min | ((ll)1 << i)) <= r)
        max = max | ((ll)1 << i), i++;
        // , cout << min << endl;
    // for (int i = 0; i <= 18; i++)
    // {
    //     // if (min & (1 << i))
    //     // {
    //     //     max = max | (1 << i);
    //     //     continue;
    //     // }
    //     ll nowMin = min | ((ll)1 << i);
    //     // cout << nowMin << endl;
    //     if (nowMin <= r)
    //         max = max | ((ll)1 << i);
    // }
    cout << max << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}