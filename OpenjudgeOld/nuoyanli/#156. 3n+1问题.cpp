#include<iostream>

using namespace std;

int n;
int ans;
int num[200000];

void work(int now)
{
	int ans = 0;
	int str = now;
	while(now != 1)
	{
		if(num[now] != 0)
		{
			ans += num[now];
			num[str] = ans;
			break;
		}
		if(now % 2 == 0)
		{
			now = now*3;
			ans++;
		}else
		{
			now = now/2;
			ans++;
		}
	}
	cout << ans%3 << endl;
}

int main()
{
	while(cin >> n)
		work(n);
	return 0;
}
