#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int n,m,s;
vector<int> g[101000];
vector<int> w[101000];
bool used[101000];
int f[101000];

struct node
{
	int tnode;
	int tw;
	bool operator < (const node &a) const
	{
		return a.tw < tw;
	}
};

void addedge(int from,int to,int tw)
{
	g[from].push_back(to);
	//g[to].push_back(from);
	w[from].push_back(tw);
	//w[to].push_back(tw);
	return;
}

void get()
{
	cin >> n >> m >> s;
	for(int i = 1; i <= m; i++)
	{
		int tfrom,tto,tw;
		cin >> tfrom >> tto >> tw;
		addedge(tfrom,tto,tw);
	}
	return;
}

void work()
{
	for(int i = 1; i <= n; i++)
		f[i] = 10000000000;
	f[s] = 0;
	priority_queue<node> q;
	node temp;
	temp.tnode = s;
	temp.tw = 0;
	q.push(temp);
	while(q.size() != 0)
	{
		node tempnode = q.top();
		q.pop();
		int nownode = tempnode.tnode;
		if(used[nownode] == 1)
			continue;
		used[nownode]  = 1;
		for(int i = 0; i < g[nownode].size(); i++)
		{
			int nextnode = g[nownode][i];
			int nextw = w[nownode][i];
			if(f[nextnode] > f[nownode]+nextw)
				f[nextnode] = f[nownode]+nextw;
			else
				continue;
			if(used[nextnode] == 0)
			{
				node t;
				t.tnode = nextnode;
				t.tw = f[nextnode];
				q.push(t);
			}
		}
	}
	for(int i = 1; i <= n; i++)
		cout << f[i] << " ";
	return;
}

int main()
{
	get();
	work();
	return 0;
}
