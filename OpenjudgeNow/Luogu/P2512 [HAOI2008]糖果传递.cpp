#include <iostream>
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

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
ll n,ans,avg;
ll num[Maxn],preans[Maxn];

int main()
{
    Buff;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> num[i], avg += num[i];
    avg = avg / n;
    for(int i = 1; i <= n; i++)
        preans[i] = preans[i-1] - num[i-1] + avg;
    sort(preans+1,preans+1+n);
    ll midnum = preans[(n+1)/2];
    for(int i =  1; i <= n; i++)
        ans += abs(midnum-preans[i]);
    cout << ans;
    return 0;
}