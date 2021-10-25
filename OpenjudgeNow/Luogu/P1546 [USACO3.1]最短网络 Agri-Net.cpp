#include<iostream>
#include<algorithm>

using namespace std;

struct edge
{
	int from,to,w;
}e[10010];
int n;
int father[10010];
int ans;
int nown;

void get()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++)
	{
		int temp;
		if(i == j)
		{
			cin >> temp;
			continue;
		}
		nown++;
		cin >> temp;
		e[nown].from = i;
		e[nown].to = j;
		e[nown].w = temp;
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
	cout << ans << endl;
}

int main()
{
	get();
	work();
	return 0;
}
