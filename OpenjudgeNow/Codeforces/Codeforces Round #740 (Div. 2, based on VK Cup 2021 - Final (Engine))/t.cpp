#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=6e6+6;

ll dp[maxn];

int main()
{
    ll n,m;
    cin>>n>>m;
    dp[1]=1;
    dp[2]=m-1;

    for(int i=1;i<=n;i++)
    {
        dp[i]+=dp[i-1];
        dp[i]%=m;
        dp[i+1]+=dp[i];
        dp[i+1]%=m;
        for(ll j=2;j*i<=n;j++)
        {
            dp[j*i]=dp[j*i]+dp[i];
            dp[j*i]%=m;
            if(j*i+j<=n)
            {
                dp[j*i+j]-=dp[i];
                dp[j*i+j]%=m;
                dp[j*i+j]+=m;
                dp[j*i+j]%=m;
            }

        }


    }
    cout<<dp[n];
    return 0;
}