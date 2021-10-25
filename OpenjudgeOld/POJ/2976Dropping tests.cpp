#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<vector>

#define Maxn (int)1e3+10
using namespace std;

int n,k;
struct test
{
    double accept,submit;
}tests[Maxn];
double finalAccept,finalSubmit;

bool check(double num)
{
    vector<double> tempv;
    double newans = 0;
    for(int i = 1; i <= n; i++)
    {
        double temp = tests[i].accept - num*tests[i].submit;
        newans += temp;
        tempv.push_back(temp);
    }
    sort(tempv.begin(),tempv.end());
    for(int i = 0; i < k; i++)
        newans -= tempv[i];
    // cout << newans << endl;
    return newans > -0.00001;
}

void work()
{
    cin >> k;
    if(n == 0 && k == 0)
        return;
    for(int i = 1; i <= n; i++)
        cin >> tests[i].accept;
    for(int i = 1; i <= n; i++)
        cin >> tests[i].submit;
    double l = 0;
    double r = 100;
    double ans;
    while(r-l >= 0.00001)
    {
        double mid=(l+r)/2;
        if(check(mid))
        {
            ans = mid;
            l = mid+0.00001;
        }else
            r = mid-0.00001;
    }
    cout << (int)(100 * ans+0.5) << endl;
}

int main()
{
    while(cin >> n)
        work();
    return 0;
}