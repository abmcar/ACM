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

const int Maxn = 1e4+10;
const ll Mod = 1e9+7;
int t,n;
int s[Maxn];

void work()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> s[i];
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i + s[i] > n)
        {
            if(i == n && s[i] == 1)
                continue;
            ans += (i+s[i]-n);
            for(int j = i+1; j <= n; j++)
                s[i] = max(s[i]-1,1);
        }else
        {
            for(int j = 1; j <= s[i]; j++)
                s[i+j] = max(s[i+j]-1,1);
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
/*
1 4 2 2 2 2 2
1 3 2 2 2 1 2
1 2 2 2 1 1 1
1 1 2 1 1 1 1


*/