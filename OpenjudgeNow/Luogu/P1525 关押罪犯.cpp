#include<iostream>
#include<algorithm>

using namespace std;

int father[100100];
int eme[100100];
int n,m;
int ans;
struct ct
{
	int a,b,w;
}c[100010];


void get()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
		cin >> c[i].a >> c[i].b >> c[i].w;
	return;
}

bool cmp(ct a, ct b)
{
	return a.w > b.w;
}

int find(int son)
{
	if(father[son] == son)
		return son;
	father[son] = find(father[son]);
	return father[son];
}

void work()
{
	for(int i = 1; i <= n; i++)
		father[i] = i;
	sort(c+1,c+1+m,cmp);
	for(int i = 1; i <= m; i++)
	{
		if(find(c[i].a) == find(c[i].b))
		{
			ans = c[i].w;
			break;
		}
		if(eme[c[i].a] == 0)
		{
			eme[c[i].a] = c[i].b;
		}else
			father[find(c[i].b)] = find(eme[c[i].a]);
		if(eme[c[i].b] == 0)
		{
			eme[c[i].b] = c[i].a;
		}else
			father[find(c[i].a)] = find(eme[c[i].b]);
	}
	cout << ans << endl;
}

int main()
{
	get();
	work();
	return 0;
}
