#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
int p[10010];
int ans[10010];
int finans[10010];
int maxn;

void get()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> p[i];
	return;
}

void work()
{
	for(int i = 1; i <= n; i++)
		ans[i] = ans[i-1] + p[i];
	for(int i = m+1; i <= n; i++)
	{
		finans[i] = ans[i]-ans[i-m];
		maxn = max(maxn,finans[i]);
	}
	cout << maxn << endl;
}

int main()
{
	get();
	work();
}
