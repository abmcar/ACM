#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#include <iomanip>
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
int n,k;
int num[Maxn];

bool check(double nowMid)
{
    double morePower = 0;
    double needPower = 0;
    for(int i = 1; i <= n; i++)
        if(num[i] > nowMid)
            morePower += (num[i]-nowMid);
        else
            needPower += (nowMid-num[i]);
    if(morePower-morePower*k/100 >= needPower)
        return true;
    return false;
}

int main()
{
    Buff;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    double l = 0;
    double r = 1000;
    double ans;
    while(r - l >= 1e-8)
    {
        double mid = (l+r)/2;
        if(check(mid))
        {
            l = mid+1e-8;
            ans = l;
        }else
            r = mid-1e-8;
    }
    cout << fixed << setprecision(8) << ans << endl;
    return 0;
}