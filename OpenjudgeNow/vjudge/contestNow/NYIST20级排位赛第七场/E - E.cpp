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

String oriString;

char nextChar(char nowChar)
{
    nowChar += 1;
    if (nowChar > 'z')
        nowChar = 'a';
    return nowChar;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> oriString;
    int nowSize = oriString.size();
    for (int i = 0; i < nowSize-2; i++)
    {
        if (oriString[i] == oriString[i+1] && oriString[i] == oriString[i+2])
            oriString[i+1] = nextChar(oriString[i+1]);
    }
    for (int i = 0; i < oriString.size()-1; i++)
    {
        if (oriString[i] == oriString[i+1])
        {
            oriString[i+1] = nextChar(oriString[i+1]);
            if (i + 2 < nowSize)
            if (oriString[i+1] == oriString[i+2])
                oriString[i+1] = nextChar(oriString[i+1]);
        }
    }
    cout << oriString;
}