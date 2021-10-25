#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long n,m;
int t;

long long getsum(long long i,long long j)
{
    return i*i+j*j+i*100000-j*100000+i*j;
}

bool check(long long num)
{
    long long cut = 0;
    for(long long i = 1; i <= n; i++)
    {
        long long l = 0;
        long long r = n;
        long long ans = 0;
        while(l <= r)
        {
            long long mid = (l+r)/2;
            if(getsum(mid,i) <= num)
            {
                ans = mid;
                l = mid+1;
            }else
                r = mid-1;
        }
        cut += ans;
    }
    // cout << num << " " << cut << endl;
    return cut >= m;
}

void work()
{
    cin >> n >> m;
    long long l = -1e13;
    long long r = 1e13;
    long long ans;
    while(l <= r)
    {
        long long mid = (l+r)/2;
        if(check(mid))
        {
            ans = mid;
            r = mid-1;
        }else
            l = mid+1;
    }
    cout << ans << endl;
}

int main()
{
    cin >> t;
    for(int i = 1; i <= t; i++)
        work();
    return 0;
}