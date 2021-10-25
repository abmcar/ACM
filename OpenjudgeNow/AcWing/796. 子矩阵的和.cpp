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
#include <bits/extc++.h>
#include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

int n, m, q;
int bd[Maxn][Maxn];
int preAns[Maxn][Maxn];

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    for (int j=  1; j <= m; j++)
        cin >> bd[i][j];
    for (int i = 1; i <= n; i++)
    for (int j=  1; j <= m; j++)
        preAns[i][j] = preAns[i-1][j] + preAns[i][j-1] - preAns[i-1][j-1] + bd[i][j];
    while (q--)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << preAns[x2][y2] - preAns[x2][y1-1] - preAns[x1-1][y2] + preAns[x1-1][y1-1] << endl;
    }
    return 0;
}