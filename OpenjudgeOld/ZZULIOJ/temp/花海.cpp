#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int ok[13333];
int n;
int ans;
int num[23333];
int nownum;

bool isprime(int num)
{
	for(int i = 2; i*i <= num; i++)
		if(num % i == 0)
			return false;
	return true;
}

int main()
{
	cin >> n;
	if(n == 0)
	{
		cout << "0";
		return 0;
	}
	if(n == 0)
	{
		cout << "0";
		return 0;
	}
	for(int i = 1; i <= 10000; i++)
		if(isprime(i) == true)
			ok[i] = 1;
	ok[1] = 0;
	for(int i = 1; i <= 10000; i++)
		if(ok[i] == 1)
		{
			//cout << i << endl;
			nownum++;
			num[nownum] = i;
		}
	for(int i = 1; i <= nownum; i++)
	for(int j = 1; j <= nownum; j++)
	{
		int a = num[i];
		int b = num[j];
		if(a*b > n)
			continue;
		else
			ans++;
	}
	cout << ans;
	return 0;
}
