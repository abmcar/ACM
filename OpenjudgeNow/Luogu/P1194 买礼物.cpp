
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int price,n;
int father[10010];
bool used[10010];
int nowedge = 1;

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
	cin >> price >> n;
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++)
	{
		int tw;
		cin >> tw;
		if(i == j)
			continue;
		if(tw == 0 || tw > price)
			tw = 3;
		edge t;
		t.a = i;
		t.b = j;
		t.c = tw;
		edges[nowedge] = t;
		nowedge++;
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
	sort(edges+1,edges+1+nowedge,cmp);
	for(int i = 1; i <= n; i++)
		father[i] = i;
	for(int i = 1; i <= nowedge; i++)
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
		cout << now+price << endl;
	else 
		cout << "orz" << endl;
}



int main()
{
	get();
	work();
	return 0;
}
