#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std; 

struct edge
{
	int from,to,w;
}e[100010];
int n,m;
int father[10010];
int ans;

void get()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
		cin >> e[i].from >> e[i].to >> e[i].w;
	return;
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
	return a.w < b.w;
}

void work()
{
	for(int i = 1; i <= n; i++)
		father[i] = i;
	sort(e+1,e+1+m,cmp);
	for(int i = 1; i <= m; i++)
	{
		if(find(e[i].from) != find(e[i].to))
		{
			ans = max(ans,e[i].w);
			father[find(e[i].from)] = father[e[i].to];
		}
	}
	return;
}

void out()
{
	cout << n-1 << " " << ans;
	return;
}

int main()
{
	get();
	work();
	out();
}
