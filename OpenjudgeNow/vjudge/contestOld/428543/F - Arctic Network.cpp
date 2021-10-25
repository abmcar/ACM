#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
// #define endl "\n"

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, s, n;
int father[Maxn];
int posX[Maxn], posY[Maxn];
bool used[Maxn];
int cntEdges;
double ans;
int deletePos1, deletePos2;

struct Edge
{
    int from, to;
    double val;
    bool const operator<(Edge b) const
    {
        return val > b.val;
    }
} edge[Maxn];

double getDis(int pos1, int pos2)
{
    double x1 = posX[pos1];
    double x2 = posX[pos2];
    double y1 = posY[pos1];
    double y2 = posY[pos2];
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int find(int son)
{
    if (father[son] == son)
        return son;
    father[son] = find(father[son]);
    return father[son];
}

void clear()
{
    ans = 0;
    for (int i = 1; i <= n; i++)
        father[i] = i, used[i] = false;
}

void work()
{
    cin >> s >> n;
    clear();
    vector<Edge> nowEdges;
    priority_queue<Edge> q;
    for(int i = 1; i <= n; i++)
        cin >> posX[i] >> posY[i];
    for(int i = 1; i <= n; i++)
    for(int j = i+1; j <= n; j++)
    {
        Edge temp;
        temp.from = i;
        temp.to = j;
        temp.val = getDis(i,j);
        q.push(temp);
    }
    while (!q.empty())
    {
        Edge nowEdge = q.top();
        q.pop();
        int f1 = find(nowEdge.from);
        int f2 = find(nowEdge.to);
        if (f1 == f2)
            continue;
        father[f1] = f2;
        nowEdges.push_back(nowEdge);
    }
    cout << fixed << setprecision(2) << nowEdges[n-s-1].val << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}