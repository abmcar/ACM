#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;

struct edge
{
	int from,to;
	double w;
	bool unbuild;
}e[900100];
int father[10010];
int n,m;
int nown;
int bx[10010];
int by[10010];
double ans;

void get()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> bx[i] >> by[i];
	for(int i = 1; i <= m; i++)
	{
		cin >> e[i].from >> e[i].to;
		int tax = bx[e[i].from];
		int tay = by[e[i].from];
		int tbx = bx[e[i].to];
		int tby = by[e[i].to];
		e[i].w = sqrt((double)(tax-tbx)*(tax-tbx)+(double)(tay-tby)*(tay-tby));
	}
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
	nown = m;
	for(int i = 1; i <= n; i++)
	for(int j = i; j <= n; j++)
	{
		int tax = bx[i];
		int tay = by[i];
		int tbx = bx[j];
		int tby = by[j];
		nown++;
		e[nown].from = i;
		e[nown].to = j;
		e[nown].w = sqrt((double)(tax-tbx)*(tax-tbx)+(double)(tay-tby)*(tay-tby));
		e[nown].unbuild = 1;
	}
	sort(e+1,e+1+m,cmp);
	for(int i = 1; i <= m; i++)
	{
		if(find(e[i].from) == find(e[i].to))
			continue;
		father[find(e[i].from)] = find(e[i].to);
	}
	sort(e+2+m,e+2+m+nown,cmp);
	for(int i = m+1; i <= m+nown; i++)
	{
		if(find(e[i].from) == find(e[i].to))
			continue;
		father[find(e[i].from)] = find(e[i].to);
		ans += e[i].w;
	}
	cout << fixed << setprecision(2) << ans << endl;
}

int main()
{
	get();
	work();
	return 0;
}
