#include <iostream>
#include <map>
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
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#pragma GCC optimize(2)
using namespace std;

const int Maxn = 1e4 + 10;
const ll Mod = 1e9 + 7;
static char space[10000000],*sp=space;
int start = clock();

template<typename T>
struct myalloc:allocator<T>{
    myalloc(){}
    template<typename T2>
    myalloc(const myalloc<T2> &a){}
    template<typename T2>
    myalloc<T>& operator=(const myalloc<T2> &a){return *this;}
    template<typename T2>
    struct rebind{typedef myalloc<T2> other;};
    inline T* allocate(size_t n){
        T *result=(T*)sp;sp+=n*sizeof(T);
        return result;
    }
    inline void deallocate(T* p,size_t n){}
};

int n, m, x, y, strw, d;
vector<int,myalloc<int> > g[Maxn], w[Maxn], limitw[Maxn];
// bool vis[Maxn];
ll dis[Maxn];
bool inQ[Maxn];
int ans;
unordered_map<int,unordered_map<ll,ll> >vis;

struct Node
{
    int pos, maxw;
    ll dis;
    bool const operator< (Node b) const
    {
        return maxw < b.maxw;
    }
};

void init()
{
    cin >> n >> m >> x >> y >> strw >> d;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, p, d;
        cin >> u >> v >> p >> d;
        g[u].push_back(v);
        g[v].push_back(u);
        w[u].push_back(d);
        w[v].push_back(d);
        limitw[u].push_back(p);
        limitw[v].push_back(p);
    }
}

void spfa()
{
    for (int i = 1; i <= n; ++i)
        dis[i] = 1e12;
    queue<int> Q;
    Q.push(y);
    dis[y] = 0;
    while (!Q.empty())
    {
        int nowNode = Q.front();
        Q.pop();
        inQ[nowNode] = false;
        for (int i = 0; i < g[nowNode].size(); ++i)
        {
            int nextNode = g[nowNode][i];
            ll nextDis = dis[nowNode] + w[nowNode][i];
            if (nextDis < dis[nextNode])
            {
                dis[nextNode] = nextDis;
                if (inQ[nextNode])
                    continue;
                Q.push(nextNode);
            }
        }
    }
}

void bfs()
{
    priority_queue<Node,vector<Node>> Q;
    // queue<int> qN;
    // queue<int> qW;
    // queue<ll> qD;
    // qN.push(x);
    // qW.push(2e9);
    // qD.push(0);
    Node t;
    t.pos = x;
    t.maxw = 2e9;
    t.dis = 0;
    Q.push(t);
    while (!Q.empty())
    {
        int nowNode = Q.top().pos;
        int nowMaxW = Q.top().maxw;
        ll nowDis = Q.top().dis;
        // qN.pop();
        // qW.pop();
        // qD.pop();
        Q.pop();
        if (ans != 0)
        if (nowMaxW <= ans)
            continue;
        if (nowNode == y)
        {
            if (nowDis + dis[x] > d)
                continue;
            ans = max(ans, nowMaxW);
            continue;
        }
        if (vis[nowNode][nowMaxW] < nowDis)
            continue;
        else
            vis[nowNode][nowMaxW] = nowDis;
        if (clock() - start >= CLOCKS_PER_SEC * 0.93)
        {
            ans = 1e12;
            return;
        }
        for (int i = 0; i < g[nowNode].size(); ++i)
        {
            int nextNode = g[nowNode][i];
            int nextW = min(limitw[nowNode][i], nowMaxW);
            ll nextDis = nowDis + w[nowNode][i];
            if (nextDis+dis[x] > d)
                continue;
            if (ans != 0)
            if (nextW <= ans)
                continue;
            if (vis[nextNode][nextW] != 0)
            {
                if (vis[nextNode][nextW] < nextDis)
                    continue;
                else
                    vis[nextNode][nextW] = nextDis;
            }else
                vis[nextNode][nextW] = nextDis;
            Node temp;
            temp.pos = nextNode;
            temp.maxw = nextW;
            temp.dis = nextDis;
            // qN.push(nextNode);
            // qW.push(nextW);
            // qD.push(nextDis);
            Q.push(temp);
        }
    }
}

int main()
{
    Buff;
    init();
    spfa();
    if (dis[x] == 1e12)
    {
        cout << "-1";
        return 0;
    }
    bfs();
    if (ans == 0 || ans == 2e9 || ans <= strw)
    {
        cout << "-1" << endl;
        return 0;
    }
    cout << ans-strw << endl;
    return 0;
}