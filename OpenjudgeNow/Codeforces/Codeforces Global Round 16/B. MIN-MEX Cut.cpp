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
// #include <ext/pb_ds/priority_queue.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
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
String oriString;

void work()
{
    cin >> oriString;
    int num0, num1;
    num0 = num1 = 0;
    char lastChar = '-';
    for (char nowChar : oriString)
    {
        if (lastChar == nowChar)
            continue;
        lastChar = nowChar;
        if (nowChar == '1')
            num1++;
        else
            num0++;
    }
    if (num1 == 0)
        cout << 1 << endl;
    else
    if (num0 == 0)
        cout << 0 << endl;
    else
    if (num0 == 1)
        cout << 1 << endl;
    else
        cout << 2 << endl;
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