#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int n,m,s,t;
vector<int> g[10010];
vector<int> w[10010];
int dis[10010];
bool used[10010];
int ans = 100010;

inline void link(int a, int b, int tw)
{
	g[a].push_back(b);
	g[b].push_back(a);
	w[a].push_back(tw);
	w[b].push_back(tw);
	return;
}

void get()
{
	cin >> n >> m >> s >> t;
	for(int i = 1; i <= m; i++)
	{
		int tf,tt,tw;
		cin >> tf >> tt >> tw;
		link(tf,tt,tw);
	}
}

void work()
{
	queue<int> temp;
	temp.push(s);
	for(int i = 1; i <= n; i++)
		dis[i] = 1000010;
	dis[s] = 0;
	used[s] = 1;
	while(temp.size() != 0)
	{
		int nown = temp.front();
		temp.pop();
		used[nown] = 0;
		for(int i = 0; i < g[nown].size(); i++)
		{
			int nextn = g[nown][i];
			int nextw = w[nown][i];
			if(dis[nextn] > max(dis[nown],nextw))
			{
				dis[nextn] = max(dis[nown],nextw);
				if(used[nextn] == 0)
				{
					used[nextn] = 1;
					temp.push(nextn);
				}
			}
			//cout << nown << " " << nowmax << " " << nextn << " " << nextw  << " " << max(nextw,nowmax)<< endl;
		}
		//cout << temp.size() << endl;

	}
	cout << dis[t] << endl;
}

int main()
{
	get();
	work();
	return 0;	
} 
