#include<iostream>

using namespace std;

double n;
double h,r;
double pi = 3.1415926;

int main()
{
	cin >> n >> h >> r;
	double one = pi*r*r*h;
	double ans = n / one;
	//cout << one << endl << ans << endl;
	if(ans / 1 == 0)
		cout << ans;
	else
		cout << (int)ans + 1;
	return 0;
}
