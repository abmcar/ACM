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

const int Maxn = 1e2 + 10;
const ll Mod = 1e9 + 7;

int values[Maxn];

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
//    freopen("makeData.in", "r", stdin);
//    freopen("makeData.yml", "w", stdout);
    String materialName = "钻剑核心";
    for (int i = 1; i <= 31; i++)
        cin >> values[i];
    values[0] = values[1];
    int nowSuccessRate = 100;
    for (int i = 0; i <= 31; i++)
    {
        cout << i << ":" << endl;
        cout << "  MaterialRequire:" << endl;
        if (i == 10)
            cout << "    - '警告：打造11及以上失败装备损坏！'" << endl;
        cout << "    - '§a §7所需材料:" + materialName + " * " << i << "'" << endl;
        cout << "  AddValue:" << endl;
        cout << "    - '§a §7数值变化:物理伤害 + " << values[i] << "'" << endl;
        cout << "  SuccessRate: " << nowSuccessRate << endl;
        cout << "  Broadcast: ";
        if (i >= 11)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        nowSuccessRate = nowSuccessRate*0.9;
    }
    return 0;
}