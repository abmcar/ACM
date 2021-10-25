#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;

struct edge
{
	int from,to;
	double w;
}e[13010000];
int n,m;
int father[5010];
double ans;
double maxn;
int nown;
long long bx[5010];
long long by[5010];

void get()
{
	std::ios::sync_with_stdio(false);
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
	for(int j = i+1; j <= n; j++)
	{
		nown++;
		e[nown].from = i;
		e[nown].to = j;
		if(::abs(bx[i]-bx[j])+::abs(by[i]-by[j]) > 1500000)
		{
			nown--;
			continue;
		}
		e[nown].w = sqrt((bx[i]-bx[j])*(bx[i]-bx[j])+(by[i]-by[j])*(by[i]-by[j]));
	}
	sort(e+1,e+1+nown,cmp);
	for(int i = 1; i <= nown; i++)
	{
		//cout << e[i].from << " " << e[i].to << " " << e[i].w << endl;
		if(find(e[i].from) == find(e[i].to))
			continue;
		father[find(e[i].from)] = find(e[i].to);
		ans += e[i].w;
		//cout << e[i].from << " " << e[i].to << " " << e[i].w << endl;
	}
	cout << fixed << setprecision(2) << ans << endl;
}

int main()
{
	get();
	work();
	return 0;
}
