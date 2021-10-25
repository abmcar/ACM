#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,m;
int father[10010];
bool used[10010];

struct edge
{
	int a,b,c;
};

edge edges[200100];

bool cmp(edge a,edge b)
{
	return a.c < b.c;
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
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int ta,tb,tc;
		cin >> ta >> tb >> tc;
		edge t;
		t.a = ta;
		t.b = tb;
		t.c = tc;
		edges[i] = t;
	}
}

bool check()
{
	bool ok = 1;
	int te = find(1);
	for(int i = 1; i <= n; i++)
		if(find(i) != te) ok = 0;
	return ok;
}

void work()
{
	int now = 0;
	sort(edges+1,edges+1+m,cmp);
	for(int i = 1; i <= n; i++)
		father[i] = i;
	for(int i = 1; i <= m; i++)
	{
		if(find(edges[i].a) != find(edges[i].b))
		{
		//	cout << find(edges[i].a) << "   " << find(edges[i].b) << endl;
		//	cout << edges[i].a << "   " << edges[i].b << endl<< endl;
			now = now + edges[i].c;
			father[find(edges[i].a)] = father[edges[i].b];
		}
	}
	if(check() == 1)
		cout << now << endl;
	else 
		cout << "orz" << endl;
}



int main()
{
	get();
	work();
	return 0;
}
