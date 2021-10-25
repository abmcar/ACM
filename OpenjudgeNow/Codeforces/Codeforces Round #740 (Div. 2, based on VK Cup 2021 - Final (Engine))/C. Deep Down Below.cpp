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

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

map<vector<int>, int> M;
int t, n;

struct Node
{
    vector<int> monsters;
    int value;
    void getValue()
    {
        value = 0;
        for (int i = 0; i < monsters.size(); i++)
            value = max(value, monsters[i] - i);
    }
    const bool operator<(Node b) const
    {
        return value < b.value;
    }
} node[Maxn];

void work()
{
    M.clear();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        node[i].monsters.clear();
        int temp;
        cin >> temp;
        for (int j = 1; j <= temp; j++)
        {
            int tempNum;
            cin >> tempNum;
            node[i].monsters.push_back(tempNum);
        }
        node[i].getValue();
    }
    sort(node + 1, node + 1 + n);
    int ans = 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int nowValue : node[i].monsters)
        {
            ans = max(ans, nowValue - cnt + 1);
            cnt++;
        }
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