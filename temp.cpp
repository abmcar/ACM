#include<bits/stdc++.h>
#define ll long long
#define in128 __int128
using namespace std;
const int N=2e5+100;
ll a[N],b[N];
ll c[N];
int n;
in128 check(ll sum)
{
    c[0]=0;
    for(int i=1;i<n;i++)
    {
        c[i]=c[i-1]+sum-b[i+1];
    }
    sort(c,c+n);
    in128 x=c[n/2];
    in128 res=0;
    for(int i=0;i<n;i++)
    {
        in128 y=x-c[i];
        if(y>0)res+=y;
        else res+=-y;
    }
    return res;
}
void print(in128 x)
{
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i]-a[i-1];
    }
    ll l=-1e13,r=1e13;
    while(l<r)
    {
        ll midl=l+(r-l)/3;
        ll midr=r-(r-l)/3;
        if(check(midl)<=check(midr))
            r=midr-1;
        else l=midl+1;
    }
    print(check(l));
    return 0;
}
/*
 * 123
 * 132
 * 312
 * 213
 * 231
 * 1234
 *
 * 2134
 * 2314
 * 2341
 *
 * 1243
 * 1324
 * 3124
 *
 * 1243
 * 4123
 * 1423
 * 1243
 * */