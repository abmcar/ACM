#include <stdio.h>

double x, y, a, b;
double l,r,ans;
double targetV;

signed main()
{
    scanf("%lf %lf %lf %lf",&x,&y,&a,&b);
    targetV = a*b/4;
    l = 0;
    r = 1;
    while (r - l >= 1e-10)
    {
        double mid = (l + r) / 2;
        // cout << l << " " << r << " " << mid << endl;
        if (mid*mid*a*b/2 >= targetV)
        {
            ans = mid;
            r = mid;
        }else
            l = mid;
    }
    printf("%.5lf",x+a*(1-ans));
    return 0;
}
// 347 -685 868 194