#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;

int t;
ll n;

void work()
{
    scanf("%lld",&n);
    if(n < 20)
    {
        printf("-1\n");
        return;
    }
    int ans = 2;
    bool fir = false;
    bool sed = false;
    if(n % 10 == 0)
        fir = true, ans--;
    n = n / 10;
    if((n % 10) % 2 == 0)
        sed = true, ans--;
    n = n / 10;
    while(n != 0)
    {
        int tempnum = n % 10;
        n = n / 10;
        if(!fir && tempnum == 0)
        {
            fir = true;
            continue;
        }
        if(!sed && (tempnum % 2 == 0))
        {
            sed = true;
            continue;
        }
        if(fir && sed)
            break;
    }
    if(fir && sed)
        printf("%d\n",ans);
    else
        printf("-1\n");
}

int main()
{
    // Buff;
    scanf("%d",&t);
    while(t--)
        work();
    return 0;
}