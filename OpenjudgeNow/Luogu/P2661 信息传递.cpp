#include<iostream>
#include<vector>

using namespace std;

int n;
int father[200010];
int tempfather[200010];
int d[200010];
int ans;

int find(int son)
{
	if(father[son] == son)
		return son;
	father[son] = find(father[son]);
	return father[son];
}

bool check()
{
	for(int i = 1; i <= n; i++)
	{
		if(find(i) != find(1))
			return false;
	}
	return true;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n*2; i++)
		father[i] = i;
	for(int i = 1; i <= n; i++)
		cin >> d[i];
	int flag = 1;
	while(check() == false)
	{
		ans++;
		for(int i = 1; i <= n; i++)
			father[find(i+n*flag)] = find(d[i]+n*(!flag));
		if(flag == 1)
			flag = 0;
		else
			flag = 1;
	}
	cout << ans << endl;
	return 0;
}
