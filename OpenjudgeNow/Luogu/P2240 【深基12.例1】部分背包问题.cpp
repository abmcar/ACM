#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>

using namespace std;

int n,t;
double ans;
int nowt;
int nowbz = 1;

struct bz
{
	double m;
	double v;
	double d;
};
bz b[1010];

bool cmp(bz a, bz b)
{
	return a.d > b.d;
}

void get()
{
	cin >> n >> t;
	for(int i = 1; i <= n; i++)
		cin >> b[i].m >> b[i].v;
	return;
}

void work()
{
	for(int i = 1; i <= n; i++)
		b[i].d = b[i].v / b[i].m;
	sort(b+1,b+n+1,cmp);
	while(nowt < t)
	{
		ans = ans + b[nowbz].d;
		b[nowbz].m--;
		nowt++;
		if(b[nowbz].m == 0)
			nowbz++;
	}
	return;
}

void put()
{
	//for(int i = 1; i <= n; i++)
	//	cout << b[i].m << " " << b[i].v << " " << b[i].d << endl;
	cout << fixed << setprecision(2) << ans << endl;
	return;
}

int main()
{
	get();
	work();
	put();
	return 0;	
} 
