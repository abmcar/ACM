#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>

using namespace std;

int p,s;
int bx[100100];
int by[100100];
int father[10010];
int nown;
int usedn;
double ans;
bool rebuild[10010];

struct edge
{
	int from,to;
	double w;
	bool used;
}e[1001000];

void get()
{
	cin >> p >> s;
	for(int i = 1; i <= s; i++)
		cin >> bx[i] >> by[i];
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
	for(int i = 1; i <= s; i++)
		father[i] = i;
	for(int i = 1; i <= s; i++)
	for(int j = i+1; j <= s; j++)
	{
		nown++;
		e[nown].from = i;
		e[nown].to = j;
		e[nown].w = (bx[i]-bx[j])*(bx[i]-bx[j]) + (by[i]-by[j])*(by[i]-by[j]);
		//cout << e[nown].from << " " << e[nown].to << " " << e[nown].w << endl;
	}
	sort(e+1,e+1+nown,cmp);
	for(int i = 1; i <= nown; i++)
	{
		//cout << e[i].w << endl;
		if(find(e[i].from) == find(e[i].to))
			continue;
		father[find(e[i].from)] = find(e[i].to);
		e[i].used = 1;
	}
	int usedn;
	for(int i = nown; i >= 1; i--)
	{
		if(e[i].used != 1)
			continue;
		e[i].used = 1;
		usedn++;
		if(usedn == p)
		{
			ans = sqrt(e[i].w);
			break;
		}
	}
	cout << fixed << setprecision(2) << ans << endl;	
}

int main()
{
	get();
	work();
	return 0;
}
