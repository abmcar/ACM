#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int ok[1010][20];
int unac[1010][20];
int t,n,m,k;
struct people
{
	int ac;
	int tottime;
	int bh;
}p[1010];

bool cmp(people a,people b)
{
	if(a.ac != b.ac)
		return a.ac > b.ac;
	if(a.tottime != b.tottime)
		return a.tottime < b.tottime;
	return a.bh < b.bh;
}

void work()
{
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= m; j++)
	{
		ok[i][j] = 0;
		unac[i][j] = 0;
	}
	for(int i = 1; i <= n; i++)
	{
		p[i].ac = 0;
		p[i].tottime = 0;	
		p[i].bh = i;
	}	
	for(int i = 1; i <= k; i++)
	{
		int ta,tb,tc;
		string ts;
		cin >> ta >> tb >> tc >> ts;
		if(ts == "AC")
		{
			if(ok[tb][tc] == 1)
				continue;
			ok[tb][tc] = 1;
			p[tb].ac++;
			p[tb].tottime += ta;
			p[tb].tottime += unac[tb][tc]*20;
		}else
		{
			if(ok[tb][tc] == 1)
				continue;
			unac[tb][tc]++;
		}
	}
	sort(p+1,p+1+n,cmp);
	if(p[1].bh == 1)
		cout << "WAAAAA" << endl;
	else
		cout << p[1].bh << endl;
	return;
}

int main()
{
	cin >> t;
	for(int i = 1; i <= t; i++)
		work();
	return 0;	
}
