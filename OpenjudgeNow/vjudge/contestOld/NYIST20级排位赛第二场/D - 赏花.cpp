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

int t;
vector<int> g[Maxn];
int preAns[23][23][23];

int n, m, k;
void dfs(int strNode, int endNode, int nowDeep)
{
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    while (cin >> n >> m)
    {
        for (int i = 1; i <= m; i++)
        {
            int t1, t2;
            cin >> t1 >> t2;
            g[t1].push_back(t2);
        }
        cin >> t;
        while (t--)
        {
            int t1, t2;
            cin >> t1 >> t2 >> k;
            dfs(t1, t2, k);
            cout << preAns[t1][t2][k] << endl;
        }
    }
    return 0;
}