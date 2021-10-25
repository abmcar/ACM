#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n,c;
long long ans;
int father[3000];
int bx[3000];
int by[3000];
int nowedge;

struct edge
{
	int from,to;
	long long w;
}e[5000000];

bool cmp(edge a,edge b)
{
	return a.w < b.w;
}

int find(int son)
{
	if(father[son] == son)
		return son;
	father[son] = find(father[son]);
	return father[son];
}

void get()
{
	cin >> n >> c;
	for(int i = 1; i <= n; i++)
		cin >> bx[i] >> by[i];
	return;
}

void prework()
{
	for(int i = 1; i <= n; i++)
		father[i] = i;
	for(int i = 1; i <= n; i++)
	for(int j = i+1; j <= n; j++)
	{
		nowedge++;
		e[nowedge].from = i;
		e[nowedge].to = j;
		e[nowedge].w = (bx[i]-bx[j])*(bx[i]-bx[j])+(by[i]-by[j])*(by[i]-by[j]);
	}
	sort(e+1,e+1+nowedge,cmp);
	return;
}

void work()
{
	prework();
	for(int i = 1; i <= nowedge; i++)
	{
		//cout << e[i].from << " " << e[i].to << " " << e[i].w << endl;
		if(find(e[i].from) == find(e[i].to))
			continue;
		if(e[i].w < c)
			continue;
		father[find(e[i].from)] = find(e[i].to);
		ans += e[i].w;
	}
	return;
}

bool check()
{
	int tempfather = find(1);
	for(int i = 1; i <= n; i++)
		if(find(i) != tempfather)
			return false;
	return true;
}

void output()
{
	if(check() == true)
		cout << ans << endl;
	else
		cout << "-1" << endl;
	return;
}

int main()
{
	get();
	work();
	output();
	return 0;	
}
