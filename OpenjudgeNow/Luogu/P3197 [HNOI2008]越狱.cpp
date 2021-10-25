#include<iostream>
#include<algorithm>
#define mod 100003
using namespace std;

long long m,n;
long long ans;
int main()
{
    cin >> m >> n;
    //ans = m^n - m*(m-1)^(n-1)
    ans = 1;
    long long tempn = n;
    long long base = m;
    while(tempn > 0)
    {
        if(tempn % 2 == 1)
        {
            ans = ((ans%mod)*(base%mod))%mod;
            tempn--;
        }else
        {
            base = ((base%mod)*(base%mod))%mod;
            tempn = tempn/2;
        }
    }
    long long tempans = m;
    base = m-1;
    tempn = n-1;
    while(tempn > 0)
    {
        if(tempn % 2 == 1)
        {
            tempans = ((tempans%mod)*(base%mod))%mod;

            tempn--;
        }else
        {
            base = ((base%mod)*(base%mod))%mod;
            tempn = tempn/2;
        }
    }
    cout << ((ans-tempans)%mod+mod)%mod;
    return 0;
}