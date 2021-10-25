#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n,a,b;
vector<int> g[10010];
vector<int> w[10010];
int maxn;
int f[10010];


void addedge(int from,int to)
{
	g[from].push_back(to);
} 

void get()
{
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++)
	{
		int tempnum;
		cin >> tempnum;
		for(int j = 0; j < tempnum; j++)
		{
			int tt;
			cin >> tt;
			addedge(i,tt);
		}
	}
	return;
}

void prework()
{
	for(int i = 1; i <= n; i++)
	for(int j = 0; j < g[i].size(); j++)
	if(j == 0)
		w[i].push_back(0);
	else
		w[i].push_back(1);
	return;
}

void work()
{
	for(int i = 1; i <= n; i++)
		f[i] = 12346798;
	queue<int> tq;
	tq.push(a);
	f[a] = 0;
	while(tq.size() != 0) 
	{
		int nownode = tq.front();
		tq.pop();
		for(int i = 0; i < g[nownode].size(); i++)
		{
			int nextnode = g[nownode][i];
			int nextw = w[nownode][i];
			if(f[nextnode] > f[nownode]+nextw)
			{
				f[nextnode] = f[nownode]+nextw;
				//cout << nownode << " " << nextnode << " " << f[nextnode] << endl;
				tq.push(nextnode);
			}
		}
	}
	if(f[b] != 12346798)
		cout << f[b] << endl;
	else
		cout << "-1" << endl;
}

int main()
{
	get();
	prework();
	work();
	return 0;
}
