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
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, h, w;
bool bd[23][23];
bool vis[23][23];

void fill(int x, int y)
{
    for (int i = max(1, x - 1); i <= min(h, x + 1); i++)
    for (int j = max(1, y - 1); j <= min(w, y + 1); j++)
        vis[i][j] = true;
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
    {
        cin >> h >> w;
        memset(bd, 0, sizeof(bd));
        memset(vis, 0, sizeof(vis));

        for (int i = 1; i <= w; i++)
            if (!vis[1][i])
            {
                bd[1][i] = true;
                fill(1, i);
            }
        for (int i = 1; i <= h; i++)
            if (!vis[i][1])
            {
                bd[i][1] = true;
                fill(i, 1);
            }
        for (int i = 1; i <= h; i++)
            if (!vis[i][w])
            {
                bd[i][w] = true;
                fill(i, w);
            }
        for (int i = 1; i <= w; i++)
            if (!vis[h][i])
            {
                bd[h][i] = true;
                fill(h, i);
            }
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
                if (bd[i][j])
                    cout << 1;
                else    
                    cout << 0;
            cout << Endl;
        }
        cout << endl;
    }
    return 0;
}