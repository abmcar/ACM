#include<iostream>
#include<iomanip>

using namespace std;

double r1,r2;
double ans;
int main()
{
	cin >> r1 >> r2;
	ans = 1/((1/r1)+(1/r2));
	cout << fixed << setprecision(2) << ans;
	return 0;
}
