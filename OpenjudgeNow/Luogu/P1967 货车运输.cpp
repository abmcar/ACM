#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>
#include<queue>

using namespace std;

struct edge
{
	int from,to;
	int w;
	bool used;
}e[100005];

int n,m,q;
int lf[100010];
int lt[100010];
int father[100010];
bool used[100010];
int fa[100010][32];
int deep[100010];
bool dfsUsed[100010];
int dfsw[100010][32];
//int runed[10010][10010];

vector<int> g[100100];
vector<int> gw[100100];
void get()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
		cin >> e[i].from >> e[i].to >> e[i].w;
	cin >> q;
	for(int i = 1; i <= q; i++)
		cin >> lf[i] >> lt[i];
}

int find(int son)
{
	if(father[son] == son)
		return son;
	father[son] = find(father[son]);
	return father[son];
}

bool cmp(edge a, edge b)
{
	return a.w > b.w;
}

void dfs(int nowNode, int fatherNode)
{
	deep[nowNode] = deep[fatherNode] + 1;
	fa[nowNode][0] = fatherNode;
	dfsUsed[nowNode] = true;
	for (int i = 1; (1 << i) <= deep[nowNode]; i++)
		fa[nowNode][i] = fa[fa[nowNode][i-1]][i-1];
	for (int i = 0; i < g[nowNode].size(); i++)
		if(!dfsUsed[g[nowNode][i]])
			dfs(g[nowNode][i], nowNode);	
}

int lca(int pos1, int pos2)
{
	if (deep[pos1] < deep[pos2])
		swap(pos1, pos2);
	while (deep[pos1] != deep[pos2])
		pos1 = fa[pos1][(int)(log2(deep[pos1]-deep[pos2]))];
	while (pos1 != pos2)
	{
		int nexti = 0;
		while (fa[pos1][nexti] != fa[pos2][nexti])
			nexti++;
		if (nexti != 0)
			nexti--;
		pos1 = fa[pos1][nexti];
		pos2 = fa[pos2][nexti];
	}
	return pos1;
}

void check(int larrypos)
{
	if(find(lf[larrypos]) != find(lt[larrypos]))
	{
		cout << "-1" << endl;
		return;
	}
	int lcaNode = lca(lf[larrypos], lt[larrypos]);
	// cout << lf[larrypos] << " " << lcaNode << " " << lt[larrypos] << endl;
	int nowMin = 1e9;
	queue<int> Q;
	Q.push(lf[larrypos]);
	while (!Q.empty())
	{
		int nowNode = Q.front();
		Q.pop();
		// cout << nowNode << endl;
		if (nowNode == lcaNode)
			continue;
		for (int i = 0; i < g[nowNode].size(); i++)
		{
			int nextNode = g[nowNode][i];
			// cout << deep[nowNode] << " " << deep[nextNode] << endl;
			if (deep[nextNode] > deep[nowNode])
				continue;
			nowMin = min(nowMin, gw[nowNode][i]);
			Q.push(nextNode);
		}
	}
	Q.push(lt[larrypos]);
	while (!Q.empty())
	{
		int nowNode = Q.front();
		Q.pop();
		if (nowNode == lcaNode)
			continue;
		for (int i = 0; i < g[nowNode].size(); i++)
		{
			int nextNode = g[nowNode][i];
			// cout << deep[nowNode] << " " << deep[nextNode] << endl;
			if (deep[nextNode] > deep[nowNode])
				continue;
			nowMin = min(nowMin, gw[nowNode][i]);
			Q.push(nextNode);
		}
	}
	cout << nowMin << endl;
	return;
}

void clear()
{
	for(int i = 1; i <= n; i++)
		used[i] = 0;
	return;
}

void work()
{
	for(int i = 1; i <= n; i++)
		father[i] = i;
	sort(e+1,e+1+m,cmp);
	for(int i = 1; i <= m; i++)
	{
		if(find(e[i].from) == find(e[i].to))
			continue;
		father[find(e[i].from)] = find(e[i].to);
		e[i].used = 1;
		g[e[i].from].push_back(e[i].to);
		g[e[i].to].push_back(e[i].from);
		gw[e[i].from].push_back(e[i].w);
		gw[e[i].to].push_back(e[i].w);
		//cout << g[e[i].from].size() << endl;
	}
	dfs(1, 0);
	for(int i = 1; i <= q; i++)
	{
		clear();
		check(i);
	}
}

int main()
{
	get();
	work();
	//cout << g[5].size() << endl;
	return 0;
}