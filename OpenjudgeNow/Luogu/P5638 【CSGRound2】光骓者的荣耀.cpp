#include<iostream>
#include<algorithm>

using namespace std;

int n,k;
long long s[1000010];
long long lans[1000010];
long long ans;
long long maxn;
long long finans;

void get()
{
	cin >> n >> k;
	n--;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	return;
}

void work()
{
	if(k != 0)
	for(int i = 1; i <= k; i++)
	{
		ans = ans + s[i];
		lans[i] = lans[i-1] + s[i];
		if(maxn <= lans[i])
			maxn = lans[i];
	}
	for(int i = k+1; i <= n; i++)
	{
		ans = ans + s[i];
		lans[i] = lans[i-1] + s[i] - s[i-k];
		if(maxn <= lans[i])
			maxn = lans[i];
	}
	finans = ans - maxn;
	return;
}

void put()
{
	cout << finans << endl;
	return;
}

int main()
{
	get();
	work();
	put();
	return 0;	
} 
