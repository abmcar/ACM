#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

int t;
int m,n,pos;
int lans,rans;

void work()
{
	lans = 0;
	rans = 0;
	cin >> n >> m >> pos;
	for(int i = 1; i <= n; i++)
	{
		int ta,tb;
		cin >> ta >> tb;
		if(ta > pos)
			rans += tb;
		else
			lans += tb;
	}
	cout << min(lans,rans) << endl;
	return;
}

int main()
{
	cin >> t;
	for(int i = 1; i <= t; i++)
	work();
	return 0;
}
