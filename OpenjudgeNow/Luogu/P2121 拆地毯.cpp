#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,m,k;
int father[100010];
bool used[100010];
long long ans;
int nowlink;

struct edge
{
	int u,v,w;
};

edge edges[100100];

bool cmp(edge a,edge b)
{
	return a.w > b.w;
}

int find(int a)
{
	if(father[a] == a)
		return a;
	else
	{
		father[a] = find(father[a]);
		return father[a];
	}
}


void get()
{
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		int tu,tv,tw;
		cin >> tu >> tv >> tw;
		edge t;
		t.u = tu;
		t.v = tv;
		t.w = tw;
		edges[i] = t;
	}
}

void work()
{
	sort(edges+1,edges+1+m,cmp);
	for(int i = 1; i <= n; i++)
		father[i] = i;
	for(int i = 1; i <= m; i++)
	{
		if(find(edges[i].u) != find(edges[i].v))
		{
		//	cout << find(edges[i].u) << "   " << find(edges[i].v) << endl;
		//	cout << edges[i].u << "   " << edges[i].v << endl<< endl;
			if(nowlink == k)
				continue;
			nowlink++;
			ans += edges[i].w;
			father[find(edges[i].u)] = father[edges[i].v];
		}
	}
	
	cout << ans << endl;
}

void put()
{
	for(int i = 1; i <= m; i++)
		cout << edges[i].w << endl;
}

int main()
{
	get();
	work();
	//put();
	return 0;
}
