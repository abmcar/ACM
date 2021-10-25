#include<iostream>
#include<string>
#include<algorithm>
 
using namespace std;

int t,n;
int maxn;
unsigned long long ans;

void work()
{
	cin >> n;
	maxn = 0;
	ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		ans += temp;
		if(maxn < temp)
			maxn = temp;
	}
	if(ans - maxn >= maxn)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> t;
	for(int i = 1; i <= t; i++)
		work();
	return 0;
 } 
