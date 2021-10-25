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

const int Maxn = 1e5+10;
const ll Mod = 1e9+7;
int n,c0,c1,c2;
int num[Maxn];
int t;

void work()
{
    int ans = 0;
    cin >> n;
    c0 = c1 = c2 = 0;
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        if(temp % 3 == 0)
            c0++;
        if(temp % 3 == 1)
            c1++;
        if(temp % 3 == 2)
            c2++;
    }
    while(1)
    {
        if(c0 == n/3 && c1 == n/3 && c2 == n/3)
            break;
        if(c0 > n/3)
            c1 += (c0-n/3),ans += (c0-n/3),c0 = n/3;
        if(c1 > n/3)
            c2 += (c1-n/3),ans += (c1-n/3),c1 = n/3;
        if(c2 > n/3)
            c0 += (c2-n/3),ans += (c2-n/3),c2 = n/3;
    }
    cout << ans << endl;
}

int main()
{
    Buff;
    cin >> t;
    while(t--)
        work();
    return 0;
}