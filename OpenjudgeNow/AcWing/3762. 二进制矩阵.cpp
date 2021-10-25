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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;
string bd[123];

void printPos(int x, int y, int type)
{

    if (type == 1)
    {
        cout << x << " " << y << " " << x + 1 << " " << y << " " << x << " " << y + 1 << endl;
    }
    if (type == 2)
    {
        cout << x << " " << y << " " << x + 1 << " " << y << " " << x << " " << y - 1 << endl;
    }
    if (type == 3)
    {
        cout << x << " " << y << " " << x - 1 << " " << y << " " << x << " " << y + 1 << endl;
    }
    if (type == 4)
    {
        cout << x << " " << y << " " << x - 1 << " " << y << " " << x << " " << y - 1 << endl;
    }
}

void work()
{
    int res = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> bd[i], bd[i] = "a" + bd[i];
    for (int i = 1; i <= n; i++)
    for (char j : bd[i])
        if (j == '1')
            res++;
    cout << res*3 << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (bd[i][j] == '0')
                continue;
            res++;
            if (i == 1)
            {
                if (j == 1)
                {
                    printPos(i, j, 1);
                    printPos(i+1, j, 3);
                    printPos(i, j+1, 2);
                }
                else if (j == m)
                {
                    printPos(i, j, 2);
                    printPos(i+1, j, 4);
                    printPos(i, j-1, 1);
                }
                else
                {
                    printPos(i, j, 1);
                    printPos(i+1, j, 3);
                    printPos(i, j+1, 2);
                }
            }
            else if (i == n)
            {
                if (j == 1)
                {
                    printPos(i, j, 3);
                    printPos(i-1, j, 1);
                    printPos(i, j+1, 4);
                }
                else if (j == m)
                {
                    printPos(i, j, 4);
                    printPos(i-1, j, 2);
                    printPos(i, j-1, 3);
                }
                else
                {
                    printPos(i, j, 3);
                    printPos(i-1, j, 1);
                    printPos(i, j+1, 4);
                }
            }
            else if (j == 1)
            {
                    printPos(i, j, 1);
                    printPos(i+1, j, 3);
                    printPos(i, j+1, 2);
            }
            else
            {
                    printPos(i, j, 2);
                    printPos(i+1, j, 4);
                    printPos(i, j-1, 1);
            }
        }
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