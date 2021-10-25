#include<iostream>
#include<algorithm>
using namespace std;

int father[10010];
int n,m,totw;
int nownum;
int w[10010];
int v[10010];
int finv[10010];
int finw[10010];
int f[10010];

int find(int son)
{
	if(father[son] == son)
		return son;
	father[son] = find(father[son]);
	return father[son];
}

void get()
{
	cin >> n >> m >> totw;
	for(int i = 1; i <= n; i++)
		cin >> v[i] >> w[i];
	for(int i = 1; i <= n; i++)
		father[i] = i;
	for(int i = 1;i <= m; i++)
	{
		int ta,tb;
		cin >> ta >> tb;
		father[find(ta)] = find(tb);
	}
	return;
}

void prework()
{
	for(int i = 1; i <= n; i++)
	{
		finv[find(i)] += v[i];
		finw[find(i)] += w[i];
	}
	return;
}

void work()
{
	prework();
	for(int i = 1; i <= n; i++)
	for(int j = totw; j >= finv[i]; j--)
	if(find(i) == i)
    f[j] = max(f[j],f[j - finv[i]] + finw[i]);
    cout << f[totw] << endl;
    return;
}

int main()
{
	get();
	work();
	return 0;
} 
