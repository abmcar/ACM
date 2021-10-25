#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

int n;
int a[333];
int midpos;
int ans1,ans2;

int getmid()
{
	if(n % 2 == 1)
		return (n/2)+1;
	return n/2;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1,a+1+n);
	midpos = getmid();
	for(int i = 1; i <= n; i++)
	{
		ans1 += abs(a[i]-a[midpos]);
		ans2 += abs(a[i]-a[midpos+1]);
	}
	if(ans1 > ans2)
		cout << a[midpos+1] << " " << ans2;
	else
		cout << a[midpos] << " " << ans1;
	return 0;
}
