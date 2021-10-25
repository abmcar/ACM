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

int t, n;
int costR[Maxn], costG[Maxn], costB[Maxn];
int cnt;
void work()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> costR[i] >> costG[i] >> costB[i];
    map<int, int> F[4];
    F[1][1] = costR[1];
    F[2][1] = costG[1];
    F[3][1] = costB[1];
    for (int i = 2; i <= n; i++)
    {
        F[1][i] = min(F[2][i - 1], F[3][i - 1]) + costR[i];
        F[2][i] = min(F[1][i - 1], F[3][i - 1]) + costG[i];
        F[3][i] = min(F[2][i - 1], F[1][i - 1]) + costB[i];
    }
    cout << "Case " << ++cnt << ": ";
    cout << min(F[1][n],min(F[2][n],F[3][n])) << Endl;
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