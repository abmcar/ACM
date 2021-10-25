#include<iostream>
#include<algorithm>

using namespace std;

int n;
double p;
double str[100010];
double cos[100010];

bool check(double num)
{
    double nowp = p*num;
    for(int i = 1; i <= n; i++)
    {
        double nextp = str[i];
        nextp = nextp - num*cos[i];
        if(nextp < 0)
            nowp = nowp + nextp;
    }
    return nowp >= 0;
}

int main()
{
    cin >> n >> p;
    for(int i = 1; i <= n; i++)
        cin >> cos[i] >> str[i];
    double l = 0;
    double r = 1e10;
    double ans = -1;
    while (r-l >= 0.000001)
    {
        // cout << l << " " << r << endl;
        double mid = (l+r)/2;
        if(check(mid))
        {
            ans = mid;
            l = mid+0.000001;
        }else
            r = mid-0.000001;
    }
    if(r-ans <= 0.000001)
        ans = -1;
    cout << ans;
    return 0;
}