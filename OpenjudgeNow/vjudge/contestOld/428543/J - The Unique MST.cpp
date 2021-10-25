#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e5;
const ll Mod = 1e9+7;

struct Edge
{
    int from, to, val;
    bool used;
    bool const operator < (Edge b) const
    {
        return val > b.val;
    }

    void get()
    {
        cin >> from >> to >> val;
        used = false;
    }

}edge[Maxn];

int t, n, m;
int father[Maxn];
int ans;
int mstSize;
bool isUnique;

int find(int son)
{
    if (father[son] == son)
        return son;
    father[son] = find(father[son]);
    return father[son];
}

void clear()
{
    for (int i = 0; i <= n; i++)
        father[i] = i;
}

void work()
{
    cin >> n >> m;
    if(n == 1)
    {
        cout << 0 << endl;
        return;
    }
    clear();
    ans = 0;
    isUnique = true;
    mstSize = 0;
    priority_queue<Edge> q;
    vector<Edge> V;
    for (int i = 1; i <= m; i++)
    {
        Edge temp;
        temp.get();
        q.push(temp);
    }
    while (!q.empty())
    {
        Edge nowEdge = q.top();
        q.pop();
        V.push_back(nowEdge);
        int f1 = find(nowEdge.from);
        int f2 = find(nowEdge.to);
        if (f1 == f2)
            continue;
        V[V.size()-1].used = true;
        father[f1] = f2;
        ans += nowEdge.val;
        mstSize++;
    }
    for(int i = 0; i < m; i++)
    {
        if(!V[i].used)
            continue;
        for(int j = 0; j < m; j++)
        {
            if(i == j)
                continue;
            q.push(V[j]);
        }
        clear();
        int nowSize = 0;
        int nowAns = 0;
        while (!q.empty())
        {
            Edge nowEdge = q.top();
            q.pop();
            int f1 = find(nowEdge.from);
            int f2 = find(nowEdge.to);
            if (f1 == f2)
                continue;
            father[f1] = f2;
            nowAns += nowEdge.val;
            nowSize++;
        }
        // cout << i << " " << nowSize << " " << nowAns << "  test" << endl;
        // if (nowSize != mstSize)
        // {
        //     isUnique = true;
        //     break;
        // }
        if(nowSize == mstSize && nowAns == ans)
        {
            isUnique = false;
            break;
        }
    }
    if(isUnique)
        cout << ans << endl;
    else
        cout << "Not Unique!" << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}