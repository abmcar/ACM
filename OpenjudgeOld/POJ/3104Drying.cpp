#include<iostream>
#include<algorithm>
#include<cstdio>

#define Maxn 100010
using namespace std;

long long n,k;
long long totwater[Maxn];
long long maxn;

inline bool check(long long num)
{
    long long nowtime = 0;
    for(int i = 1; i <= n; i++)
    {
        long long nowless = totwater[i] - num;
        if(nowless <= 0)
            continue;
        nowtime += nowless/(k-1);
        if(nowless % (k-1) != 0)
            nowtime++;
        if(nowtime > num)
            return false;
    }
    return nowtime <= num;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> totwater[i];
        if(totwater[i] > maxn)
            maxn = totwater[i];
    }
    cin >> k;
    if(k == 1)
    {
        cout << maxn;
        return 0;
    }
    long long l = 1;
    long long r = maxn;;
    long long ans = -1;
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
    cout << ans;
    return 0;
}