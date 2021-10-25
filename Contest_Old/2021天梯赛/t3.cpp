#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

const double g = 10;

double h0,h1,x,y;
double vg,v0;
double t1,t2;
int main()
{
    cin >> h0 >> h1 >> x >> y;
    t1 = sqrt((2*(h0-h1))/g);
    t2 = sqrt(2*h0/g);
    v0 = y/t2;
    if(v0*t1 < x)
        cout << "xie'e";
    else
        cout << fixed << setprecision(2) << v0;
    return 0;
}