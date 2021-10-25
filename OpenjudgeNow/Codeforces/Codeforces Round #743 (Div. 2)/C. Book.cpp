#include <iostream>
#include <unordered_map>
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
// using namespace __gnu_pbds;

const ll Maxn = 2e5 + 10;
const ll Mod = 1e9 + 7;

vector<ll> g[Maxn];
vector<ll> strNodes;
ll t, n;
ll r[Maxn];
ll rootNode;
ll ans;
ll totNode;

void bfs()
{
    unordered_map<ll,ll> nodeDeep;
    queue<ll> qN;
    for (ll i = 0; i < strNodes.size(); i++)
    {
        qN.push(strNodes[i]);
        nodeDeep[strNodes[i]] = 1;
    }
    while (!qN.empty())
    {
        ll nowNode = qN.front();
        ll nowDeep = nodeDeep[nowNode];
        qN.pop();
        ans = max(ans, nowDeep);
        // cout << t << " " << nowNode << " " << nowDeep << endl;
        for (ll i = 0; i < g[nowNode].size(); i++)
        {
            ll nextNode = g[nowNode][i];
            ll nextDeep = nowDeep + 1;
            if (nowNode < nextNode)
                nextDeep--;
            nodeDeep[nextNode] = max(nodeDeep[nextNode], nextDeep);
            r[nextNode]--;
            if (r[nextNode] == 0)
            {
                qN.push(nextNode);
                ans = max(ans, nextDeep);
            }
        }
    }
}

void work()
{
    rootNode = -1;
    ans = totNode = 0;
    cin >> n;
    strNodes.clear();
    for (ll i = 1; i <= n; i++)
        g[i].clear(), r[i] = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll k;
        cin >> k;
        r[i] = k;
        if (k == 0)
        {
            if (rootNode == -1)
                rootNode = i;
            strNodes.push_back(i);
        }
        else
        {
            for (ll j = 1; j <= k; j++)
            {
                ll tempNode;
                cin >> tempNode;
                g[tempNode].push_back(i);
            }
        }
    }
    // for (ll i = 1; i <= n; i++)
    //     cout << "  " << t << " " << i << " " << r[i] << endl;
    if (rootNode == -1)
    {
        cout << rootNode << endl;
        return;
    }
    bfs();
    bool ok = true;
    ll temp = 0;
    for (ll i = 1; i <= n; i++)
        if (r[i] > 0)
        {
            ok = false;
            temp++;
            // cout << "    :" << r[i] << endl;
        }
    // cout << "                "<< temp << endl;
    if (ok)
        cout << ans << endl;
    else
        cout << -1 << endl;
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