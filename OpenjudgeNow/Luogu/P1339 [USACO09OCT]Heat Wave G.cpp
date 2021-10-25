#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int n,m,s,t;
vector<int> g[10010];
vector<int> w[10010];
int f[10010];

void addedge(int from,int to,int tw)
{
	g[from].push_back(to);
	g[to].push_back(from);
	w[from].push_back(tw);
	w[to].push_back(tw);
	return;
}

void get()
{
	cin >> n >> m >> s >> t;
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
		f[i] = 1000000;
	queue<int> qq;
	qq.push(s);
	f[s] = 0;
	while(qq.size() != 0)
	{
		int nownode = qq.front();
		qq.pop();
		for(int i = 0; i < g[nownode].size(); i++)
		{
			int nextnode = g[nownode][i];
			int nextw = w[nownode][i];
			if(f[nextnode] > f[nownode]+nextw)
			{
				f[nextnode] = f[nownode]+nextw;
				qq.push(nextnode);
			}
		}
	}
	cout << f[t] << endl;
	return;
}

int main()
{
	get();
	work();
	return 0;
}
