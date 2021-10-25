#include<iostream>

using namespace std;

int n,m,p;
int father[10010];

int find(int son)
{
	if(father[son] == son)
		return son;
	father[son] = find(father[son]);
	return father[son];
}

int main()
{
	cin >> n >> m >> p;
	for(int i = 1; i <= n; i++)
		father[i] = i;
	for(int i = 1; i <= m; i++)
	{
		int ta,tb;
		cin >> ta >> tb;
		father[find(ta)] = find(tb);
	}
	for(int i = 1; i <= p; i++)
	{
		int ta,tb;
		cin >> ta >> tb;
		if(find(ta) == find(tb))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
} 
