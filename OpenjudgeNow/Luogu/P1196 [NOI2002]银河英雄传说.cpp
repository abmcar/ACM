#include<iostream>
#include<cmath> 

using namespace std;

int len[300010];
int father[300010];
int dis[300010];
int t;

int find(int son)
{
	if(father[son] == son)
		return son;
	int tt = father[son];
	int tf = find(father[son]);
	father[son] = tf;
	dis[son] = dis[son] + dis[tt];
	return father[son];
}

void uni(int a,int b)
{
	int fa = find(a);
	int fb = find(b);
	father[fa] = fb;
	dis[fa] = len[fb];
	len[fb] = len[fb] + len[fa];
    return;
}

void prework()
{
	for(int i = 1; i <= 300000; i++)
	{
		father[i] = i;
		len[i] = 1;
	}
	return;
}

void check(int a,int b)
{
	int fa = find(a);
	int fb = find(b);
	if(fa != fb)
	{
		cout << "-1" << endl;
		return;
	}
	cout << std::abs(dis[a]-dis[b])-1 << endl;
    return;
}

int main()
{
	prework();
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		char tempchar;
		cin >> tempchar;
		int ta,tb;
		cin >> ta >> tb;
		if(tempchar == 'M')
			uni(ta,tb);
		else
			check(ta,tb);
	}
	return 0;
} 
