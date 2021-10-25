#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n;
int maxn;
int t[10010];
int r[10010];
int ans[10010];
vector<int> g[10010];
vector<int> w[10010];
bool used[10010];

void addline(int from, int to)
{
	g[from].push_back(to);
	w[from].push_back(t[from]);
	return;
}

void get()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int pos,len;
		cin >> pos >> len;
		t[pos] = len;
		int temp;
		cin >> temp;
		while(temp != 0)
		{
			addline(temp,pos);
			r[pos]++;
			cin >> temp;
		}
	}
}

void work()
{
	queue<int> q;
	for(int i = 1; i <= n; i++)
		if(r[i] == 0)
			q.push(i);
	for(int i = 1; i <= n; i++)
		ans[i] = t[i];
	while(q.size() != 0)
	{
		int nownode = q.front();
		q.pop();
		for(int i = 0; i < g[nownode].size(); i++)
		{
			int nextnode = g[nownode][i];
			r[nextnode]--;
			if(r[nextnode] == 0)
				q.push(nextnode);
			ans[nextnode] = max(ans[nextnode],ans[nownode]+t[nextnode]);
		}
	}
	for(int i = 1; i <= n; i++)
		maxn = max(maxn,ans[i]);
	cout << maxn << endl;
}

int main()
{
	get();
	work();
	return 0;
}
