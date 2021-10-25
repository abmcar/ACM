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

const int Maxn = 1e3+10;
const ll Mod = 1e9+7;
int t,n;
int num[Maxn];

void work()
{
    int minn = 1e9;
    int ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> num[i];
        minn = min(num[i],minn);
    }
    for(int i = 1; i <= n; i++)
        if(num[i] > minn)
            ans++;
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