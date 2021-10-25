#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <iomanip>
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

const int Maxn = 1e4+10;
const ll Mod = 1e9+7;

int father[Maxn];
int dp[1010][32];
int t, n;
double ans;
int posX[Maxn], posY[Maxn];
double p[Maxn];
double finans;
int deepLevel[Maxn];

struct Edge
{
    int from, to;
    double dis;
    bool const operator < (Edge b) const
    {
        return dis > b.dis;
    }
};
priority_queue<Edge> q;

double getDis(int pos1, int pos2)
{
    double x1 = posX[pos1];
    double x2 = posX[pos2];
    double y1 = posY[pos1];
    double y2 = posY[pos2];
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int find(int son)
{
    if(father[son] == son)
        return son;
    father[son] = find(father[son]);
    return father[son];
}

void preST()
{
    dp[1][0] = 1;
    for(int j = 1; pow(2,j) <= n; j++)
    for(int i = 1; i <= n; i++)
        dp[i][j] = dp[dp[i][j-1]][j-1];
}


int LCA(int a,int b)
{
	if(deepLevel[a]<deepLevel[b])
		swap(a,b);
	for(int i=19;i>=0;i--)
	{
		if(deepLevel[a]- pow(2,i)>=deepLevel[b])
			a=dp[a][i];
	}
	if(a==b)
		return a;
	for(int i=19;i>=0;i--)
	{
		if(dp[a][i]!=dp[b][i])
		{
			a=dp[a][i];
			b=dp[b][i];
		}
	}
	return dp[a][0];
}

void work()
{
    vector<Edge> tempE;
    ans = finans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        father[i] = i;
        cin >> posX[i] >> posY[i] >> p[i];
    }
    for(int i = 1; i <= n; i++)
    for(int j = i+1; j <= n; j++)
    {
        Edge temp;
        temp.from = i;
        temp.to = j;
        temp.dis = getDis(i,j);
        q.push(temp);
    }
    while(!q.empty())
    {
        Edge nowEdge = q.top();
        q.pop();
        if(find(nowEdge.from) == find(nowEdge.to))
            continue;
        tempE.push_back(nowEdge);
        // cout << "kruskal:" << nowEdge.from << " " << nowEdge.to << " " << nowEdge.dis << endl;
        ans += nowEdge.dis;
        father[find(nowEdge.from)] = find(nowEdge.to);
    }
    vector<int> g[Maxn];
    vector<double> w[Maxn];
    double deep[Maxn];
    bool used[Maxn];
    for(int i = 1; i <= n; i++)
        used[i] = false;
    for(int i = 0; i < tempE.size(); i++)
    {
        g[tempE[i].from].push_back(tempE[i].to);
        w[tempE[i].from].push_back(tempE[i].dis);
        g[tempE[i].to].push_back(tempE[i].from);
        w[tempE[i].to].push_back(tempE[i].dis);
    }
    queue<int> qn;
    qn.push(1);
    deep[1] = 0;
    deepLevel[1] = 1;
    used[1] = true;
    while (!qn.empty())
    {
        int nownode = qn.front();
        qn.pop();
        for(int i = 0; i < g[nownode].size(); i++)
        if(used[g[nownode][i]])
            continue;
        else
        {
            deep[g[nownode][i]] = deep[nownode] + w[nownode][i];
            qn.push(g[nownode][i]);
            deepLevel[g[nownode][i]] = deepLevel[nownode]+1;
            dp[g[nownode][i]][0] = nownode;
            used[g[nownode][i]] = true;
        }
    }
    preST();
    // cout << "Ans:" << ans << endl;
    for(int i = 1; i <= n; i++)
    for(int j = i+1; j <= n; j++)
    {
        double maxDis = 0;
        int lca = LCA(i,j);
        int n1 = i;
        int n2 = j;
        while(n1 != lca)
            maxDis = max(maxDis,deep[n1]-deep[dp[n1][0]]), n1 = dp[n1][0];
        while(n2 != lca)
            maxDis = max(maxDis,deep[n2]-deep[dp[n2][0]]), n2 = dp[n2][0];
        double tempAns = ans - maxDis;
        // cout << i << " " << j << " " << deep[i] << " " << deep[j] << " " << tempAns << endl;
        finans = max(finans, (double)(p[i]+p[j])/tempAns);
    }
    cout << fixed << setprecision(2) << finans << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}