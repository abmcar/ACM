//x = y + p*n;
//"任一充分大的偶数都可以表示成二个素数的和
//或是一个素数和一个半素数的和"。
//在数学中，两个素数的乘积所得的自然数我们称之为半素数
//数字分为素数和非素数，除了1之外的所有非素数其实都是素数的倍数
#include<iostream>
#include<cmath>

using namespace std;

long long x,y;
int t;

void work()
{
	cin >> x >> y;
	long long z = x-y;
	if(z == 1)
	{
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	return;
}

int main()
{
	cin >> t;
	for(int i = 1; i <= t; i++)
		work();
	return 0;
}
