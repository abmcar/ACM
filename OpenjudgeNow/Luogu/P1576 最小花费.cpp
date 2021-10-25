#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>

using namespace std;

int n,m;
vector<int> g[10010];
vector<double> w[10010];
int a,b;
double f[10010];
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
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int ta,tb,tc;
		cin >> ta >> tb >> tc;
		addedge(ta,tb,tc);
	}
	cin >> a >> b;
	return;
}

void work()
{
	for(int i = 1; i <= n; i++)
		f[i] = 987654;
	queue<int> qn;
	queue<double> qw;
	qn.push(a);
	qw.push(100);
	while(qn.size() != 0)
	{
		int nownode = qn.front();
		double noww = qw.front();
		qn.pop();
		qw.pop();
		for(int i = 0; i < g[nownode].size(); i++)
		{
			int nextnode = g[nownode][i];
			double nextw = w[nownode][i];
			nextw = noww/(1-0.01*nextw);
			if(f[nextnode] > nextw)
			{
				f[nextnode] = nextw;
				qn.push(nextnode);
				qw.push(nextw);
			}
		}
	}
	cout << fixed << setprecision(8) << f[b] << endl;
}
//x = 100 / 0.97
int main()
{
	get();
	work();
	return 0;
} 
