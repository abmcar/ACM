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

const int Maxn = 200000;
const ll Mod = 1e9 + 7;

int n, m, nowTime;
int sum[Maxn];
int costTime[Maxn];
int timeStr[Maxn], timeEnd[Maxn];
bool apple[Maxn];
// vector<vector<int> > g(Maxn);
// typedef vector<int>ve; vector<ve>g(200000);

struct node
{
    int v,next;
} edge[800000];
int head[200000],cnt;
void addEdge(int u,int v)
{
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void dfs(int nowNode)
{
    // cout << nowNode << endl;
    nowTime++;
    timeStr[nowNode] = nowTime;
    for (int i = head[nowNode]; i != -1; i = edge[i].next)
        dfs(edge[i].v);
    timeEnd[nowNode] = nowTime;
}

inline int lowbit(int x)
{
    return x & -x;
}

inline void add(int x, int k)
{
    while (x <= n)
    {
        sum[x] += k;
        x += lowbit(x);
    }
}

inline int getSum(int x)
{
    int nowSum = 0;
    while (x > 0)
    {
        nowSum += sum[x];
        x -= lowbit(x);
    }
    return nowSum;
}

inline void query()
{
    // cout << "query start" << endl;
    int nodePos;
    cin >> nodePos;
    // cout << getSum(timeEnd[nodePos]);
    // cout << timeEnd[nodePos] << " " << timeStr[nodeP] << endl;
    // cout << getSum(timeEnd[nodePos]) << " " << getSum(timeStr[nodePos - 1]) << endl;
    cout << getSum(timeEnd[nodePos]) - getSum(timeStr[nodePos] - 1) << endl;
}

inline void changeTree()
{
    // cout << "change start" << endl;
    int nodePos;
    cin >> nodePos;
    if (apple[nodePos])
    {
        apple[nodePos] = false;
        add(timeStr[nodePos], -1);
    }
    else
    {
        apple[nodePos] = true;
        add(timeStr[nodePos], 1);
    }
}

inline void changeTree(int x)
{
    // cout << "change start" << endl;
    int nodePos = x;
    if (apple[nodePos])
    {
        apple[nodePos] = false;
        add(timeStr[nodePos], -1);
    }
    else
    {
        // cout << "1" << endl;
        apple[nodePos] = true;
        add(timeStr[nodePos], 1);
    }
}

inline void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        head[i] = -1;
    for (int i = 2; i <= n; i++)
    {
        int nFrom, nTo;
        cin >> nFrom >> nTo;
        addEdge(nFrom,nTo);
        // g[nFrom].push_back(nTo);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        changeTree(i);
        // add(i,1);
        // apple[i] = true;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        char optChar;
        cin >> optChar;
        if (optChar == 'C')
            changeTree();
        else
            query();
    }
}

int main()
{
    Buff;
    init();
    return 0;
}