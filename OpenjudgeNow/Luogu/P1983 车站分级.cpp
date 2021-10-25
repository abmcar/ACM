#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n,m;
int lr[10010][10010];
int r[10010];
bool used[10010];
bool jg[10010][10010];
vector<int> g[100010];
int ans = 1;

void get()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
		for(int j = 0; j <= lr[i][0]; j++)
			cin >> lr[i][j];
	return;
}

void work()
{
	for(int i = 1; i <= m; i++)
	for(int j = 1; j <= lr[i][0]; j++)
		used[lr[i][j]] = 1;
	for(int i = 1; i <= m; i++)
	for(int j = lr[i][1]; j <= lr[i][lr[i][0]]; j++)
	{
		if(used[j] == 0)
			continue;
		for(int k = 1; k <= lr[i][0]; k++)
		{
			if(jg[j][lr[i][k]] == 0)
			{
				jg[j][lr[i][k]] = 1;
				r[lr[i][k]]++;
				g[j].push_back(lr[i][k]);
			}
		}
	}
	queue<int> tq;
	queue<int> tw;
	for(int i = 1; i <= n; i++)
		if(r[i] == 0)
		{
			tq.push(i);
			tw.push(1);
		}
	for(int i = 1; i <= n; i++)
		cout << r[i] << endl;
	while(tq.size() != 0)
	{
		int nownode = tq.front();
		int nowlevel = tw.front();
		tq.pop();
		tw.pop();
		cout << nownode << " " << nowlevel << endl;
		for(int i = 0; i < g[nownode].size(); i++)
		{
			int nextnode = g[nownode][i];
			r[nextnode]--;
			if(r[nextnode] == 0)
			{
				tq.push(nextnode);
				tw.push(nowlevel+1);
				ans = max(ans,nowlevel+1);
			}
		}
	}
	cout << ans << endl;	
}

int main()
{
	get();
	work();
	return 0;
}
