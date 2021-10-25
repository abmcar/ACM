#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>

using namespace std;

int n;
long long a[100010];
long long nowmaxn;
long long ans;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		ans = max(ans,nowmaxn - a[i]);
		nowmaxn = max(nowmaxn,a[i]);
	}
	cout << ans;
	return 0;
}
