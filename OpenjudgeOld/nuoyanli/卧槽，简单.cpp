#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double a,b,c;
int n;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a >> b >> c;
		if(b*b-4*a*c < 0)
			cout << "This equation is unsolvable!" << endl;
		else
		{
			double ta = (-b-sqrt(b*b-4*a*c))/2*a;
			double tb = (-b+sqrt(b*b-4*a*c))/2*a;
			cout << fixed << setprecision(2) << "x1=" << min(ta,tb)  << " x2=" << max(ta,tb) << endl;
		}
	}
	return 0;
}
