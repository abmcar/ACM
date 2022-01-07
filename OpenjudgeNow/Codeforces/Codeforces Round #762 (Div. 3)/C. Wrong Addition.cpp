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
// #include <ext/pb_ds/priority_queue.h>
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define int long long
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t;
string a, b, s;

int getSNum(int pos)
{
    return (s[pos + 1] - '0') * 10 + s[pos] - '0';
}

void dfs(int p1, int p2, string nowAns)
{
    if (p1 == s.size())
    {
        if (p2 >= a.size())
        b = nowAns;
        // cout << nowAns << endl;
    }
    if (p1 >= s.size())
        return;
    if (p1 < s.size() - 1 && s[p1 + 1] != '0')
    {
        int oriNum = getSNum(p1);
        int nowNum = p2 < a.size() ? a[p2] - '0' : 0;
        if (oriNum - nowNum >= 0 && oriNum - nowNum < 10)
            dfs(p1 + 2, p2 + 1, nowAns + (char)(oriNum - nowNum + '0'));
    }
    int oriNum = s[p1] - '0';
    int nowNum = p2 < a.size() ? a[p2] - '0' : 0;
    if (oriNum - nowNum >= 0 && oriNum - nowNum < 10)
        dfs(p1 + 1, p2 + 1, nowAns + (char)(oriNum - nowNum + '0'));
}

void work()
{
    cin >> a >> s;
    reverse(a.begin(), a.end());
    reverse(s.begin(), s.end());
    b = "-1";
    dfs(0, 0, "");
    reverse(b.begin(), b.end());
    while (b[0] == '0' && b.size() > 0)
        b.erase(0, 1);
    if (b == "1-")
        b = "-1";
    cout << b << endl;
}

signed main()
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