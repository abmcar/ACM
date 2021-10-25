#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>

#define Maxn (int)1e5+10
using namespace std;

int n;
long long num[Maxn];
long long totp;

bool check(long long tn)
{
    int tot = 0;
    for(int i = 1; i <= n; i++)
    {
        int nowpos = (upper_bound(num+1+i,num+1+n,num[i]+tn)-num)-1;
        // cout << tn << " " << nowpos << endl;
        tot += nowpos-i;
    }
    // cout << tot << " " << totp << endl;
    return tot >= totp;
}

void work()
{
    for(int i = 1; i <= n; i++)
        scanf("%d",&num[i]);
    totp = (((n*(n-1))/2)+1)/2;
    sort(num+1,num+1+n);
    long long l = 0;
    long long r = num[n]-num[1];
    long long ans;
    while (l <= r)
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
    // std::ios::sync_with_stdio(false);
    while(scanf("%d",&n) != EOF)
        work();
    return 0;
}