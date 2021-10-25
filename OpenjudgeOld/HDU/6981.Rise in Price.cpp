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
#include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;

const int Maxn = 123;
const ll Mod = 1e9 + 7;

int t, n;
ll a[Maxn][Maxn], b[Maxn][Maxn];
struct Node
{
    int k;
    ll val;
    bool const operator< (Node b) const
    {
        return k < b.k;
    }
};

bool cmp(Node a, Node b)
{
    return a.k > b.k;
}

void work()
{
    // unordered_map<int,ll> M[Maxn][Maxn];
    vector<Node> V[Maxn][Maxn];
    // V[1][1].push_back({a[1][1],b[1][1]});
    cin >> n;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        cin >> a[i][j];
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        cin >> b[i][j];
    Node tempNode;
    tempNode.k = a[1][1];
    tempNode.val = b[1][1];
    V[1][1].push_back(tempNode);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
        vector<Node> temp(V[i-1][j].size()+V[i][j-1].size());
        merge(V[i-1][j].begin(),V[i-1][j].end(),V[i][j-1].begin(),V[i][j-1].end(),temp.begin(),cmp);
        sort(temp.begin(),temp.end());
        int nowMaxn = -1;
        for (int pos = 0; pos < temp.size(); pos++)
        {
            if (temp[pos].val < nowMaxn)
                continue;
            nowMaxn = temp[pos].val;
            temp[pos].k += a[i][j];
            temp[pos].val += b[i][j];
            V[i][j].push_back(temp[pos]);
        }
    }
    ll ans = 0;
    for (Node nowNode : V[n][n])
        ans = max(ans, nowNode.k * nowNode.val);
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