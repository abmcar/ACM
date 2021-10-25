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

const int Maxn = 1e4 + 10;
const ll Mod = 1e9 + 7;

int n, ans, res;
vector<int> g[Maxn], w[Maxn];
int num[Maxn], len[Maxn];

void dfs(int nowNode, int fatherNode)
{
    num[nowNode] = 1;
    for (int i = 0; i < g[nowNode].size(); i++)
    {
        int nextNode = g[nowNode][i];
        if (nextNode == fatherNode)
            continue;
        dfs(nextNode, nowNode);
        int temp = len[nextNode] + w[nowNode][i];
        if (len[nowNode] + temp > ans)
        {
            ans = len[nowNode] + temp;
            res = num[nowNode] * num[nextNode];
        }
        else if (len[nowNode] + temp == ans)
            res += num[nowNode] * num[nextNode];
        if (temp > len[nowNode])
        {
            len[nowNode] = temp;
            num[nowNode] = num[nextNode];
        }else
        if (temp == len[nowNode])
            num[nowNode] += num[nextNode];
    }
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    while (cin >> n)
    {
        ans = res = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            int t1, t2, t3;
            cin >> t1 >> t2 >> t3;
            g[t1].push_back(t2);
            g[t2].push_back(t1);
            w[t1].push_back(t3);
            w[t2].push_back(t3);
        }
        vector<int> V;
        memset(len,0,sizeof(len));
        memset(num,0,sizeof(num));
        dfs(1, 0);
        cout << ans << " " << res << endl;
        for (int i = 0; i <= n; i++)
            g[i].clear(), w[i].clear();
    }
    return 0;
}