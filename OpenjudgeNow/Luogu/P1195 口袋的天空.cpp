#include<iostream>
#include<algorithm>

using namespace std;

struct edge
{
	int from,to,w;
	bool used;
};

int n,m,k;
edge e[10010];
int father[10010];
int nown;
long long ans;
bool refather[10010];
bool noans;

void get()
{
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		int tf,tt,tw;
		cin >> tf >> tt >> tw;
		e[i].from = tf;
		e[i].to = tt;
		e[i].w = tw;
	}
}

int find(int temp)
{
	if(father[temp] == temp)
		return temp;
	father[temp] = find(father[temp]);
	return father[temp];
}

void check()
{
	for(int i = 1; i <= n; i++)
	{
		if(refather[find(i)] == 0)
		{
			nown++;
			refather[find(i)] = 1;
		}
	}
}

bool cmp(edge a, edge b)
{
	return a.w < b.w;
}

void work()
{
	sort(e+1,e+1+m,cmp);
	for(int i = 1; i <= n; i++)
		father[i] = i;
	for(int i = 1; i <= m; i++)
	{
		if(find(e[i].from) != find(e[i].to))
		{
			father[find(e[i].from)] = find(e[i].to);
			e[i].used = 1;
			ans = ans + e[i].w;
		}
	}
	check();
	if(nown > k)
	{
		noans = 1;
		return;
	}
	int tempflag = m;
	for(int i = nown; i < k; i++)
	{
        if(e[tempflag].used == 0)
        {
            tempflag--;
            i--;
            continue;
        }
		ans = ans - e[tempflag].w;
		tempflag--;
	}
	return;
}

void tempout()
{
	cout << endl;
	for(int i = 1; i <= n; i++)
		cout << find(i) << " ";
	cout << endl;
	for(int i = 1; i <= m; i++)
		cout << e[i].from << " " << e[i].to << " " << e[i].w << endl;
	cout << endl;
}

void out()
{
	//tempout();
	if(noans == 1)
	{
		cout << "No Answer" << endl;
		return;
	}
	cout << ans << endl;
	return;
}

int main()
{
	get();
	work();
	out();
	return 0;
}
