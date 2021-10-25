#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define Maxn (int)1e6+10

using namespace std;

int num[Maxn];
int n,m;

bool check(double nownum)
{
    int cut = 0;
    for(int i = 1; i <= n; i++)
        cut += (int)(num[i]/nownum);
    return cut >= m;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    double r = 1000000000;
    double l = 0;
    double ans = 0;
    while(r-l >= 0.0001)
    {
        // cout << l << " " << r << endl;
        double mid = (l+r)/2;
        if(check(mid))
        {
            l = mid+0.0001;
            ans = mid;
        }
        else
            r = mid-0.0001;
    }
    // cout << ans << endl;
    cout << fixed << setprecision(2) << ans;
}