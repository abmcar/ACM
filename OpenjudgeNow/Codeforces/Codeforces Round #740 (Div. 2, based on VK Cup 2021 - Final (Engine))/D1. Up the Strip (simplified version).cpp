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
#define Inf ll_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const ll Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll finNum[Maxn];
ll M[Maxn];
ll work(ll num)
{
    // map<ll,ll> M;
    M[num] = 1;
    for (ll i = num; i > 1; i--)
    {
        for (ll j = i-1; j >= 1; j--)
            M[j] += M[i];
        for (ll j = 2; j <= i; j++) 
            M[i/j] += M[i];
    }
    finNum[num] = M[1];
    cout << num <<  " " << M[1] << " " << " " << finNum[num-1] << " " << M[1]-finNum[num-1] <<" " <<  M[1]-2*finNum[num-1] << endl;
    // for (ll i = 1; i <= num; i++)
    //     cout << num << " " << i << " "  <<  M[i] << endl;
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    work(100000);
    // for (ll i = 1; i <= 32; i++)
    //     work(i);
    return 0;
}
/*
2 4 6 10 12 16 18 22 28 
  2 2  4  2  4  2  4  6
*/