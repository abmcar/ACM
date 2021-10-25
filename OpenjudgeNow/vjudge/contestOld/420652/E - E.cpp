#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

int t;
double y;

bool check(double num)
{
    double temp = 8*pow(num,4)+7*pow(num,3)+2*num*num+3*num+6;
    if(temp >= y)
        return true;
    return false;
}

void work()
{
    cin >> y;
    double l = 0;
    double r = 100;
    double ans = -1;
    // if(y == 6)
    // {
    //     cout << "0" << endl;
    //     return;
    // }
    int num = 100;
    if(y < 6 || y > 8*pow(num,4)+7*pow(num,3)+2*num*num+3*num+6)
    {
        cout << "No solution!" << endl;
        return;
    }
    while (r-l >= 0.000000001)
    {
        // cout << l << " " << r << endl;
        double mid = (l+r)/2;
        if(check(mid))
        {
            r = mid-0.000000001;
            ans = mid;
        }else
            l = mid+0.000000001;
    }
    double temp = ans;
    printf("%.4f\n",ans);
}

int main()
{
    cin >> t;
    while (t--)
        work();
    return 0;
}