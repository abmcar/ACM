#include<iostream>
#include<algorithm>

using namespace std;

int n,m,p,q;
int afather[10010];
int bfather[10010];
int aans = 1;
int bans = 1;

int find(int son)
{	
	if(son > 0)
	{
		if(afather[son] == son)
			return son;
		afather[son] = find(afather[son]);
		return afather[son];
	}
	else
	{
		son = son*-1;
		if(bfather[son] == son)
			return son;
		bfather[son] = find(bfather[son]*-1);
		return bfather[son];
	}
}

int main()
{
	cin >> n >> m >> p >> q;
	for(int i = 1; i <= n; i++)
		afather[i] = i;
	for(int i = 1; i <= m; i++)
		bfather[i] = i;
	for(int i = 1; i <= p; i++)
	{
		int ta,tb;
		cin >> ta >> tb;
		if(find(ta) == find(tb))
			continue;
		afather[find(ta)] = find(tb);
	}
	for(int i = 1; i <= q; i++)
	{
		int ta,tb;
		cin >> ta >> tb;
		if(find(ta) == find(tb))
			continue;
		bfather[find(ta)] = find(tb);
	}
	for(int i = 2; i <= n; i++)
	{
		if(find(i) == find(1))
			aans++;
	}
	for(int i = 2; i <= m; i++)
	{
		if(find(i*-1) == find(-1))
			bans++;
	}
	//cout << aans << " " << bans << endl;
	cout << min(aans,bans) << endl;
}
