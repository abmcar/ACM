#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct edge
{
	int from,to;
	double w;
}e[1001000];
int n,m;
int father[10010];
double ans;
double maxn;
int nown;
int cmove[10010];
int bx[10010];
int by[10010];

void get()
{
	cin >> m;
	for(int i = 1; i <= m; i++)
		cin >> cmove[i];
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> bx[i] >> by[i];
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
	for(int i = 1; i <= n; i++)
	for(int j = i; j <= n; j++)
	{
		nown++;
		e[nown].from = i;
		e[nown].to = j;
		e[nown].w = (bx[i]-bx[j])*(bx[i]-bx[j])+(by[i]-by[j])*(by[i]-by[j]);
	}
	sort(e+1,e+1+nown,cmp);
	for(int i = 1; i <= nown; i++)
	{
		//cout << e[i].from << " " << e[i].to << " " << e[i].w << endl;
		if(find(e[i].from) == find(e[i].to))
			continue;
		father[find(e[i].from)] = find(e[i].to);
		maxn = max(maxn,e[i].w);
		//cout << e[i].from << " " << e[i].to << " " << e[i].w << endl;
	}
	for(int i = 1; i <= m; i++)
		if(cmove[i]*cmove[i] >= maxn)
			ans++;
	cout << ans << endl;
}

int main()
{
	get();
	work();
	return 0;
}
