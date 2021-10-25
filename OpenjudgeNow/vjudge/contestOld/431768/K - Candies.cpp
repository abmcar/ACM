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

const int Maxn = 3e4 + 10;
const ll Mod = 100003;

int n, m;
int dis[Maxn];
bool inQ[Maxn];
short tempS[Maxn];

class fuckPOJ
{
public:
    int cnt;
    fuckPOJ();
    void pop();
    void push(int num);
    int top();
    bool empty();
};

fuckPOJ::fuckPOJ()
{
    cnt = 0;
}

void fuckPOJ::pop()
{
    cnt--;
}

void fuckPOJ::push(int num)
{
    tempS[++cnt] = num;
}

int fuckPOJ::top()
{
    return tempS[cnt];
}

bool fuckPOJ::empty()
{
    // cout << cnt << endl;
    if (cnt == 0)
        return true;
    return false;
}

struct node
{
    int v,w,next;
} edge[150010];
int head[30001],cnt;
void add(int u,int v,int w)
{
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

int main()
{
    // Buff;
    // cin >> n >> m;
    scanf("%d %d", &n, &m);
    memset(dis,0x3f3f3f3f,sizeof(dis));
    for (int i = 1; i <= n; i++)
        head[i] = -1;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2, t3;
        scanf("%d %d %d", &t1, &t2, &t3);
        // cin >> t1 >> t2 >> t3;
        // if (t2 - t1 <= t3)
        add(t1,t2,t3);
    }
    fuckPOJ Q;
    Q.push(1);
    dis[1] = 0;
    while (!Q.empty())
    {
        int nowNode = Q.top();
        Q.pop();
        inQ[nowNode] = false;
        for (int i = head[nowNode]; i!=-1; i=edge[i].next)
        {
            int nextNode = edge[i].v;
            int nextDis = dis[nowNode] + edge[i].w;
            if (dis[nextNode] > nextDis)
            {
                dis[nextNode] = nextDis;
                if (!inQ[nextNode])
                {
                    inQ[nextNode] = true;
                    Q.push(nextNode);
                }
            }
        }
    }
    cout << dis[n];
    return 0;
}