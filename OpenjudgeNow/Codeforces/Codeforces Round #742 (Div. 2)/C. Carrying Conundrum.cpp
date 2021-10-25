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
#define Inf ll_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const ll Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

String oriString;
ll t;
ll ans1, ans2;

// void dfs(ll deep, ll nowNum, ll nowAns)
// {
//     // cout << oriString << " " << deep << " " << nowNum << " "  << nowAns << endl;;
//     if (deep > oriString.size())
//         return;
//     if (nowNum == 1)
//     {
//         if (deep + 2 <= oriString.size())
//             dfs(deep + 2, oriString[deep + 1] - '0' + 10, nowAns);
//         // return;
//     }
//     ll divNum = nowNum;
//     // if (deep > 0)
//     //     divNum++;
//     divNum = min(9,divNum);
//     if (deep == oriString.size() - 1)
//         ans += nowAns*divNum;
//     else
//         dfs(deep + 1, oriString[deep] - '0',divNum);
// }

void work()
{
    ans1 = ans2 = 0;
    cin >> oriString;
    for (ll i = 0; i < oriString.size(); i++)
    {
        char nowChar = oriString[i];
        if (i % 2)
            ans1 = ans1 * 10 + nowChar - '0';
        else
            ans2 = ans2 * 10 + nowChar - '0';
    }
    cout << ans1 * ans2 + ans1 + ans2 - 1 << endl;

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