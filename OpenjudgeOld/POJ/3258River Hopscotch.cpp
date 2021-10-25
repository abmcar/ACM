#include<iostream>
#include<algorithm>
#define Maxn 50010
using namespace std;

long long totl,n,m;
long long dis[Maxn];

bool check(int num)
{
    int nownum = 0;
    int nowdis = 0;
    for(int i = 1; i <= n; i++)
        if(dis[i]-nowdis < num)
            nownum++;
        else
            nowdis = dis[i];
    return nownum <= m;
}

int main()
{
    cin >> totl >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> dis[i];
    sort(dis+1,dis+1+n);
    long long l = 1;
    long long r = totl;
    long long ans;
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