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
int t,n,num[Maxn];

void work()
{
    int ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    for(int i = 1; i < n; i++)
    {
        int numa = min(num[i],num[i+1]);
        int numb = max(num[i],num[i+1]);
        while(numa*2 < numb)
        {
            ans++;
            numa*=2;
        }
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