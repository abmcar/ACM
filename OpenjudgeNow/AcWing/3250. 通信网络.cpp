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
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

int n, m, ans;
vector<int> g[Maxn], gg[Maxn];
bool vis[Maxn];

inline int bfs(int strNode)
{
    // for (int i = 1; i <= n; i++)
    //     vis[i] = false;
    memset(vis,0,sizeof(vis));
    queue<int> q;
    unordered_set<int> S;
    q.push(strNode);
    while (q.size())
    {
        int nowNode = q.front();
        q.pop();
        S.insert(nowNode);
        if (S.size() == n)
            return n;
        for (auto nextNode : g[nowNode])
        {
            if (vis[nextNode])
                continue;
            vis[nextNode] = true;
            q.push(nextNode);
        }
    }
    // if (S.size() == n)
    //     return n;
    memset(vis,0,sizeof(vis));
    // for (int i = 1; i <= n; i++)
    //     vis[i] = false;
    q.push(strNode);
    while (q.size())
    {
        int nowNode = q.front();
        q.pop();
        S.insert(nowNode);
        if (S.size() == n)
            return n;
        for (auto nextNode : gg[nowNode])
        {
            if (vis[nextNode])
                continue;
            vis[nextNode] = true;
            q.push(nextNode);
        }
    }
    return S.size();
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        gg[t2].push_back(t1);
    }
    for (int i = 1; i <= n; i++)
        if (bfs(i) == n)
            ans++;
    cout << ans << endl;
    return 0;
}