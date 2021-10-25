#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std; 

struct edge
{
	int from,to;
}e[100010];
int n,m;
int father[10010];
int ans;
bool endflag;

int find(int son)
{
	if(father[son] == son)
		return son;
	father[son] = find(father[son]);
	return father[son];
}

void get()
{
	if(n == 0)
	{
		endflag = 1;
		return;
	}
	cin >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> e[i].from >> e[i].to;
	}
}

void work()
{
	while(cin >> n)
	{
		get();
		if(endflag == 1)
			return;
		int nowans = 0;
		for(int i = 1; i <= n; i++)
			father[i] = i;
		for(int i = 1; i <= m; i++)
		{
			if(find(e[i].from) != find(e[i].to))
			{
				nowans++;
				father[find(e[i].from)] = father[e[i].to];
			}
		}
		cout << n-1-nowans << endl;
	}
	return;
}

int main()
{
	work();
}
