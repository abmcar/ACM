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
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 3e5 + 10;
const ll Mod = 1e9 + 7;

struct node
{
    int v, w, next;
} edge[Maxn * 10];
int head[Maxn], cnt;

struct Node
{
    int pos, val;
    bool const operator<(Node b) const
    {
        return val > b.val;
    }
};

void add(int u, int v, int w)
{
    // cout << "add:" << u << " " << v << " " << w << " " << cnt << endl;
    edge[++cnt].v = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

int t, n, m, c, Cnt;
int dis[Maxn];
bool used[Maxn];

void init()
{
    memset(dis, 0x3f, sizeof(dis));
    memset(used, false, sizeof(used));
    memset(head, -1, sizeof(head));
    cnt = 0;
    scanf("%d %d %d", &n, &m, &c);
    // cin >> n >> m >> c;
    // for (int i = 0; i <= n+10000; i++)
    // {
    //     head[i] = -1;
    //     dis[i] = 1e9;
    //     used[i] = false;
    // }
    for (int i = 1; i <= n; i++)
    {
        // cin >> deep[i];
        int temp;
        scanf("%d", &temp);
        add(temp + n, i, 0);
        if (temp > 1)
            add(i, n + temp - 1, c);
        if (temp < n)
            add(i, n + temp + 1, c);
    }
    for (int i = 1; i <= m; i++)
    {
        int t1, t2, t3;
        // cin >> t1 >> t2 >> t3;
        scanf("%d %d %d", &t1, &t2, &t3);
        add(t1, t2, t3);
        add(t2, t1, t3);
    }
}
priority_queue<Node, vector<Node>> Q;

void dijkstra()
{
    memset(dis,0x7f,sizeof(dis));
    memset(used,false,sizeof(used));
    Q.push({1, 0});
    dis[1] = 0;
    while (!Q.empty())
    {
        int nowNode = Q.top().pos;
        Q.pop();
        // cout << nowNode.pos << " " << nowNode.val << endl;
        if (used[nowNode])
            continue;
        used[nowNode] = true;
        for (int i = head[nowNode]; i != -1; i = edge[i].next)
        {
            int nextNodePos = edge[i].v;
            // if (nextNodePos == nowNode.pos)
            //     continue;
            int nextDis = dis[nowNode] + edge[i].w;
            // cout << "next:" << nowNode.pos << " " << nextNodePos << " " << nextDis << endl;
            if (nextDis < dis[nextNodePos])
            {
                dis[nextNodePos] = nextDis;
                Q.push({nextNodePos, nextDis});
            }
        }
    }
}

void work()
{
    init();
    dijkstra();
    if (dis[n] == dis[0])
        dis[n] = -1;
    cout << "Case #" << ++Cnt << ": " << dis[n] << endl;
}

int main()
{
    // Buff;
    // cin >> t;
    scanf("%d", &t);
    while (t--)
        work();
    return 0;
}