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

ll ans1[Maxn], ans2[Maxn];
int n;
ll num[Maxn];
int ans;

int main()
{
    Buff;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    for(int i = n; i >= 1; i--)
    {
        ans1[i] = ans1[i+1];
        ans2[i] = ans2[i+1];
        if(i % 2 == 1)
            ans1[i] += num[i];
        else
            ans2[i] += num[i];
    }
    ans1[0] = ans1[1];
    ans2[0] = ans2[1];
    for(int i = 1; i <= n; i++)
    {
        int tempans1 = ans1[1] - ans1[i] + ans2[i+1];
        int tempans2 = ans2[1] - ans2[i] + ans1[i+1];
        if(tempans1 == tempans2)
            ans++;
        // cout << i << " " << tempans1 << " " << tempans2 << endl;
    }
    cout << ans;
    return 0;
}