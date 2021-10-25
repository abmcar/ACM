#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>

using namespace std;

int sum[10];

int main()
{	
	for(int i = 1; i <= 5; i++)
		cin >> sum[i];
	sum[1] = sum[1]/3;
	sum[2] = sum[2]+sum[1];
	sum[5] = sum[5]+sum[1];
	for(int i = 2; i <= 4; i++)
	{
		sum[i] = sum[i]/3;
		sum[i-1] += sum[i];
		sum[i+1] += sum[i];
	}
	sum[5] = sum[5]/3;
	sum[4] += sum[5];
	sum[1] += sum[5];
	for(int i = 1; i <= 5; i++)
		cout << sum[i] << " ";
	return 0;
}
