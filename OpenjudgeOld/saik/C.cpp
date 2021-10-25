#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

const int Maxn = 1e7 + 7;

int n, m, k;
long long ans;
int father[Maxn];

struct Node
{
    long long from, to, val;

    bool const operator<(Node b) const
    {
        return val < b.val;
    }
} node[Maxn];

int find(int son)
{
    if (father[son] == son)
        return son;
    father[son] = find(father[son]);
    return father[son];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        father[i] = i;
    for (int i = 1; i <= m; i++)
        cin >> node[i].from >> node[i].to >> node[i].val;
    cin >> k;
    father[find(node[k].from)] = find(node[k].to);
    ans += node[k].val;
    sort(node + 1, node + 1 + m);
    for (int i = 1; i <= m; i++)
    {
        if (find(node[i].from) == find(node[i].to))
            continue;
        father[find(node[i].from)] = find(node[i].to);
        ans += node[i].val;
    }
    cout << ans;
    return 0;
}