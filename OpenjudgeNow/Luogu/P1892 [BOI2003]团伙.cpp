#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n,m;
int father[10010];
int ememy[10010];
int ans;

int find(int son)
{
	if(father[son] == son)
		return son;
	father[son] = find(father[son]);
	return father[son];
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		father[i] = i;
	for(int i = 1; i <= m; i++)
	{
		char ta;
		int tb,tc;
		cin >> ta >> tb >> tc;
		if(ta == 'F')
		{
			father[find(tb)] = find(tc);
			continue;
		}
		else
		{
			if(ememy[tb] == 0)
				ememy[tb] = find(tc);
			else
				father[find(ememy[tb])] = find(tc);
			if(ememy[tc] == 0)
				ememy[tc] = find(tb);
			else
				father[find(ememy[tc])] = find(tb);
		}
	}
	for(int i = 1; i <= n; i++)
		if(find(i) == i)
			ans++;
	cout << ans << endl;
	return 0;	
} 
