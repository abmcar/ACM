#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

double tot,once,month;
double l = 0.0001;
double r = 5;

bool check(double li)
{
    double temptot = tot;
    for(int i = 1; i <= month; i++)
    {
        temptot = temptot * (1+li);
        temptot = temptot - once;
        // cout << temptot << endl;
    }
    // cout << temptot << endl;
    return (temptot <= 0);
}

int main()
{
    cin >> tot >> once >> month;
    while(r-l >= 0.0001)
    {
        // cout << l << " " << r << endl;
        double mid = (l+r)/2;
        if(check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << fixed << setprecision(1) << l*100;
};