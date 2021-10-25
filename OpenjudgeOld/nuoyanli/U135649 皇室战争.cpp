#include<iostream>
#include<vector>

using namespace std;

int n,m;
vector<char> g[100000];
int xx,xy;
int ans;

void get()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		g[i].push_back('!');
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= m; j++)
	{
		char tempchar;
		cin >> tempchar;
		if(tempchar == 'S')
		{
			xx = i;
			xy = j;
		}
		g[i].push_back(tempchar);	
	}
		for(int i = 1; i <= n; i++)
		g[i].push_back('!');
	return;
}

void work()
{
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= m; j++)
	{
		char nowchar = g[i][j];
		if(nowchar == 'K')
		{
			ans++;
			g[i][j] = '.';
			//cout << i << " " << j << endl;
			if(i == xx)
			{
				if(j < xy)
				for(int ti = 1; ti < xy; ti++)
					g[i][ti] = '.';
				if(j > xy)
				for(int ti = xy+1; ti <= m; ti++)
					g[i][ti] = '.';
				continue;
			}
			if(j == xy)
			{
				if(i < xx)
				for(int ti = 1; ti < xx; ti++)
					g[ti][j] = '.';
				if(i > xx)
				for(int ti = xx+1; ti <= n; ti++)
					g[ti][j] = '.';
				continue;
			}
			long double k = (long double)(j-xy)/(long double)(i-xx);
			long double b = (long double)xy - k*xx;
			//xy = k*xx + b
			//cout << "k " << k << " b " << b << endl;
			if(i < xx)
			for(int ti = 1; ti < xx; ti++)
			{
				long double ty = k*(long double)ti+b;
				//cout << ti << " " << (int)ty << endl;
				if(ty >= 1 && ty <= m)
				if(ty - (int)(ty/1) == 0)
					g[ti][(int)ty] = '.';
			}
			if(i > xx)
			for(int ti = xx+1; ti <= n; ti++)
			{
				long double ty = k*(long double)ti+b;
				//cout << ti << " " << (int)ty << endl;
				if(ty >= 1 && ty <= m)
				if(ty - (int)(ty/1) == 0)
					g[ti][(int)ty] = '.';
			}
		}
	}
}

int main()
{
	get();
	work();
	cout << ans << endl;
	return 0;
}
