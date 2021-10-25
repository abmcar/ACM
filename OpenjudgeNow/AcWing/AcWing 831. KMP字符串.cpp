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
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

string s, p;
int n, m;
int nextPos[Maxn];

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    // cin >> n >> p >> m >> s;
    cin >> s >> p;
    n = p.size();
    m = s.size();
    p = "-" + p;
    s = "-" + s;
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && p[i] != p[j+1]) j = nextPos[j];
        if (p[i] == p[j+1]) j++;
        nextPos[i] = j;
    }    

    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j && s[i] != p[j+1]) j = nextPos[j];
        if (s[i] == p[j+1]) j++;
        if (j == n)
        {
            cout << i-n+1 << endl;
            j = nextPos[j];
        }
    }
    for (int i = 1; i <= n; i++)
        cout << nextPos[i] << " ";
    // cout << endl;
    return 0;
}