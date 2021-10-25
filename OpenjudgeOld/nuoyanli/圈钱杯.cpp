#include<iostream>
#include<algorithm>

using namespace std;

int n;
int a[233333];
int now = 1;
int ans;
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1,a+1+n);
	for(int i = 1; i <= n; i++)
	{
		if(now <= a[i])
		{
			ans++;
			now++;
		}
	}
	cout << ans << endl;
	return 0;
}
