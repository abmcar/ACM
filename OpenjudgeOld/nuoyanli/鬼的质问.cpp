#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>

using namespace std;

struct ghost
{
	int pos,level;
	bool havefather;
	bool dead;
	bool luck;
}g[10010];
int n,m,q;
int father[10010];
int bh[10010];

bool cmp(ghost a,ghost b)
{
	if(a.level != b.level)
		return a.level > b.level;
	return a.pos < b.pos;
}

int find(int son)
{
	if(father[son] == son)
		return son;
	return find(father[son]);
}

bool isdead(int now)
{
	int temp = now;
	while(father[temp] != temp)
	{
		temp = father[temp];
		if(g[bh[temp]].dead == 1)
			return 1;
	}
	return 0;
}

bool isluck(int nowpos)
{
	int temp = nowpos;
	while(father[temp] != temp)
	{
		temp = father[temp];
		if(g[bh[temp]].luck == 1)
			return 1;
	}
	return 0;
}


void check(int nowpos)
{
	if(isdead(nowpos) == 1 || g[bh[nowpos]].dead == 1)
	{
		cout << "aaaaa" << endl;
		return;
	}
	if(g[bh[nowpos]].luck == 1 || isluck(nowpos) == 1)
	{
		cout << "hhhhh" << endl;
		return;
	}
	cout << "~~~~~" << endl;
	return;
}

void work()
{
	cin >> m >> q;
	int temp[233];
	for(int i = 1; i <= n; i++)
		cin >> g[i].pos >> g[i].level;
	for(int i = 1; i <= n; i++)
	{
		temp[i] = 0;
		father[i] = i;
		g[i].havefather = 0;
		g[i].dead = 0;
		g[i].luck = 0;
	}
	for(int i = 1; i <= n; i++)
	{
		int tempbh = g[i].pos;
		bh[tempbh] = i;
	}
	for(int i = 1; i <= m; i++)
	{
		int a,b;
		cin >> a >> b;
		father[b] = a;
		temp[bh[a]] += g[bh[b]].level;
		g[bh[b]].havefather = 1;
	}
	for(int i = 1; i <= n; i++)
		g[i].level += temp[i];	
	sort(g+1,g+1+n,cmp);
	for(int i = 1; i <= n; i++)
	{
		int tempbh = g[i].pos;
		bh[tempbh] = i;
	}
	for(int i = 1; i <= 12; i++)
	{
		if(i > n)
			break;
		if(g[i].havefather == 1)
		{
			g[i].dead = 1;
			continue;
		}
		if(i == 7)
			g[i].luck = 1;
		if(i >= 8)
			g[i].dead = 1;
	}
	for(int i = 1; i <= q; i++)
	{
		int tempnum;
		cin >> tempnum;
		check(tempnum);
	}

	for(int i = 1; i <= n; i++)
	{
		cout << g[i].pos << " ";
		cout << g[i].level << " " << g[i].dead << " ";
		cout << g[i].luck << " " << g[i].havefather << " ";
		cout << endl;
	}
	return;
}

int main()
{
	while(cin >> n)
		work();
	return 0;
}
