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

int ans1[1234], ans2[1234];
bool ok1, ok2;
int m,s;

void dfs1(int deep, int nowLess)
{
    int tempNext = m - deep;
    if (tempNext*9 < nowLess)
        return;
    if (ok1)
        return;
    if (deep == m && nowLess == 0)
    {
        ok1 = true;
        return;
    }
    for (int i = 9; i >= 0; i--)
    {
        if (nowLess >= i)
        {
            if (deep == 0 && i == 0)
                continue;
            ans1[deep] = i;
            dfs1(deep+1,nowLess-i);
        }
        if (ok1)
            return;
    }
}

void dfs2(int deep, int nowLess)
{
    int tempNext = m - deep;
    if (tempNext*9 < nowLess)
        return;
    if (ok2)
        return;
    if (deep == m)
    {
        ok2 = true;
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (nowLess >= i)
        {
            if (deep == 0 && i == 0)
                continue;
            ans2[deep] = i;
            dfs2(deep+1,nowLess-i);
        }
        if (ok2)
            return;
    }
}

int main()
{
    Buff;
    cin >> m >> s;
    if (m == 1 && s == 0)
    {
        cout << "0 0";
        return 0;
    }
    dfs1(0,s);
    dfs2(0,s);
    if (!ok2)
        cout << "-1";
    else
    for (int i = 0; i < m; i++)
        cout << ans2[i];
    cout << " ";
    if (!ok1)
        cout << "-1";
    else
    for (int i = 0; i < m; i++)
        cout << ans1[i];
    return 0;
}