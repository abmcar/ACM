#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

int t;
int n,f;
double num[12345];

bool check(double nownum)
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
        sum += (num[i]/nownum);
    return sum > f;
}

void work()
{
    double maxn = 0;
    cin >> n >> f;
    for(int i = 1; i <= n; i++)
    {
        cin >> num[i];
        num[i] = num[i] * num[i];
        maxn = max(maxn,num[i]);
    }
    double l = 0;
    double r = maxn;
    double ans;
    while (r-l >= 0.00000001)
    {
        // cout << l << " " << r << endl;
        double mid = (l+r)/2;
        if(check(mid))
        {
            l = mid+0.000000001;
            ans = l;
        }else
            r = mid-0.000000001;
    }
    // cout << ans << endl;
    printf("%.4f\n",ans*4*atan(1.0));
}

int main()
{
    cin >> t;
    while (t--)
        work();
    return 0;
}