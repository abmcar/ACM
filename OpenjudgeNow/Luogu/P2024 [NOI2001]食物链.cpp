#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;

int n,k;
int fakenews;
int father[Maxn];
int eme[Maxn];
int eat[Maxn];

int find(int son)
{
	if(father[son] == son)
		return son;
	father[son] = find(father[son]);
	return father[son];
}

int main()
{
	Buff;
	// cin >> n >> k;
	scanf("%d %d",&n,&k);
	for(int i = 1; i <= n*3; i++)
		father[i] = i;
	for(int i = 1; i <= k; i++)
	{
		int tt,ta,tb;
		scanf("%d %d %d",&tt,&ta,&tb);
		// cin >> tt >> ta >> tb;
		if(ta > n || tb > n)
		{
			fakenews++;
			continue;
		}
		if(tt == 1)
		{	
			if(find(ta+n) == find(tb) || find(ta+2*n) == find(tb))
			{
				fakenews++;
				continue;
			}
			father[find(ta)] = find(tb);
			father[find(ta+n)] = find(tb+n);
			father[find(ta+2*n)] = find(tb+2*n);
		}
		if(tt == 2)
		{
			if(find(ta) == find(tb))
			{
				fakenews++;
				continue;
			}
			if(find(ta+2*n) == find(tb))
			{
				fakenews++;
				continue;
			}
			father[find(ta)] = find(tb+2*n);
			father[find(ta+n)] = find(tb);
			father[find(ta+2*n)] = find(tb+n);
		}
	}
	cout << fakenews << '\n';
	return 0;	
} 
