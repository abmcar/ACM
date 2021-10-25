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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t;
int strPos, endPos;

bool num[10];
bool upKey, downKey, selectKey;
int ans;

struct Node
{
};

int simpleOpt(int strPos, int endPos)
{
    int ans = 1e9;
    if (strPos == endPos)
        return 0;
    if (upKey)
    {
        if (endPos >= strPos)
            ans = min(ans, endPos - strPos);
        else
            ans = min(ans, 99-strPos + endPos + 1);
    }
    if (downKey)
    {
        if (endPos <= strPos)
            ans = min(ans, strPos - endPos);
        else
            ans = min(ans, strPos + (99 - endPos) + 1);
    }
    return ans;
}


int calc(int strPos, int endPos)
{
    int ans = 1e9;
    if (strPos == endPos)
        return 0;
    if (upKey)
    {
        if (endPos >= strPos)
            ans = min(ans, endPos - strPos);
        else
            ans = min(ans, 99-strPos + endPos + 1);
    }
    if (downKey)
    {
        if (endPos <= strPos)
            ans = min(ans, strPos - endPos);
        else
            ans = min(ans, strPos + (99 - endPos) + 1);
    }
    if (selectKey)
    {
        int nowMin = 1e9;
        for (int i = 10; i <= 99; i++)
        {
            if (num[i % 10] && num[i / 10])
                nowMin = min(nowMin, simpleOpt(i,endPos) + 3);
        // cout << i << " " << nowMin << endl;
        }
        ans = min(ans, nowMin);
    }
    // if (ans >= 1234)
    //     ans = -1;
    return ans;
}


void work()
{
    ans = 1e9;
    cin >> num[1] >> num[2] >> num[3] >> upKey;
    cin >> num[4] >> num[5] >> num[6] >> downKey;
    cin >> num[7] >> num[8] >> num[9];
    cin >> selectKey >> num[0];
    cin >> strPos >> endPos;
    int ans = 1e9;
    ans = min(ans,calc(strPos,endPos));
    for (int i = 0; i < 9; i++)
    if (num[i])
        ans = min(ans,calc(i,endPos)+1);
    if (ans >= 12345)
        ans = -1;
    cout << ans << endl;
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