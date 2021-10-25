#include<iostream>
#include<algorithm>
#include<cmath>

#define Maxn (int)3e6+10
using namespace std;

int n,m;
long long s;
long long kw[Maxn];
long long kv[Maxn];
long long prekw[Maxn];
long long prekv[Maxn];
int workl[Maxn];
int workr[Maxn];
long long finans = 1e14;
long long minn = 1e13;
long long maxn;

bool check(long long num)
{
    long long nowy = 0;
    for(int i = 1; i <= m; i++)
        nowy += (prekw[workr[i]]-prekw[workl[i]-1])*(prekv[workr[i]]-prekv[workl[i]-1]);
    // cout << "nowy:" << nowy << endl;
    long long nextans = nowy-s;
    if(nextans < 0)
        nextans *= -1;
    finans=min(finans,nextans);
    return nowy > s;
}

int main()
{
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++)
    {
        cin >> kw[i] >> kv[i];
        minn = min(minn,kw[i]);
        maxn = max(maxn,kw[i]);
    }
    for(int i = 1; i <= m; i++)
        cin >> workl[i] >> workr[i];
    long long l = minn-1;
    long long r = maxn+2;
    while(l <= r)
    {
        // cout << l << "  " << r << endl;
        long long mid = (l+r)/2;
        for(int i = 1; i <= n; i++)
            prekv[i] = prekw[i] = 0;
        for(int i = 1; i <= n; i++)
        {
            prekv[i] += prekv[i-1];
            prekw[i] += prekw[i-1];
            if(kw[i] >= mid)
                prekw[i]++,prekv[i]+=kv[i];
        }
        if(check(mid))
        {
            l = mid+1;
        }else
            r = mid-1;
    }
    cout << finans;
    return 0;
}