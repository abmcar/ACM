#include<iostream>
#include<algorithm>
#define Maxn 51111

using namespace std;

struct cow
{
    long long w;
    long long v;
}cows[Maxn];
int n;
long long aftans[Maxn];

bool cmp(cow a,cow b)
{
    return a.w+a.v > b.w+b.v;
}

bool check(long long num)
{
    for(int i = 1; i <= n; i++)
        if(aftans[i]-cows[i].w-cows[i].v > num)
            return false;
    return true;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> cows[i].w >> cows[i].v;
    sort(cows+1,cows+1+n,cmp);
    for(int i = n; i >= 1; i--)
        aftans[i] = aftans[i+1]+cows[i].w;
    if(n == 1)
    {
        cout << -cows[1].v;
        return 0;
    }
    long long l = -1e17;
    long long r = 1e17;
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
    cout << ans;
    return 0;
}