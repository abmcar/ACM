#include<iostream>
#include<algorithm>

using namespace std;

long long n,k;
long long l[100100];

bool check(long long num)
{
    if(num == 0)
        return true;
    long long now = k;
    for(int i = 1; i <= n; i++)
        now = now - l[i]/num;
    return now <= 0;
}

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> l[i];
    long long l = 0;
    long long r = 100000000;
    long long ans = 0;
    while(l <= r)
    {
        long long mid = (l+r)/2;
        if(check(mid))
        {
            ans = mid;
            l = mid+1;
        }else
            r = mid-1;
    }
    cout << ans;
    return 0;
}