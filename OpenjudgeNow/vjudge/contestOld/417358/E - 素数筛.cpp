#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstdio>
#define Maxn (int)1e7+10
using namespace std;

int t,n;
int totn = 1;
int primes[Maxn];
bool used[Maxn];
bool isprimes[Maxn];

int main()
{
    // std::ios::sync_with_stdio(false);
    for(int i = 2; i <= Maxn; i++)
    if(used[i])
        continue;
    else
    {
        primes[totn++] = i;
        isprimes[i] = 1;
        for(int j = 1; i*j <= Maxn; j++)
            used[i*j] = 1;
    }
    scanf("%d",&t);
    for(int i = 1; i <= t; i++)
    {
        scanf("%d",&n);
        int ans = 0;
        int nowpos = 0;
        int temp = 1;
        while(primes[temp] < n)
            temp++;
        while(primes[nowpos]*2 <= n)
        {
            // cout << primes[nowpos] << endl;
            // cout << (*lower_bound(primes.begin(),primes.end(),n-primes[nowpos])) << endl;
            // cout << (*upper_bound(primes.begin(),primes.end(),n-primes[nowpos])) << endl;
            // cout << endl;
            if(isprimes[n-primes[nowpos]])
                ans++;
            nowpos++;
        }
        printf("Case %d: %d\n",i,ans);
        // cout << "Case " << i << ": "3 << ans << endl;
    }
    return 0;
}