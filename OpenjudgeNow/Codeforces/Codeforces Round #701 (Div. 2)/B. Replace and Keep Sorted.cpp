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
ll n,q,k;
ll num[Maxn];
ll tempnum[Maxn];
ll preans[Maxn];
int main()
{
    Buff;
    cin >> n >> q >> k;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    tempnum[1] = num[1]-1;
    for(int i = 2; i < n; i++)
        tempnum[i] = num[i+1]-num[i-1]-2;
    tempnum[n] = k-num[n];
    // for(int i = 1; i <= n; i++)
    //     cout << tempnum[i] << " ";
    // cout << endl;
    for(int i = 1; i <= n; i++)
        preans[i] = preans[i-1] + tempnum[i];
    while(q--)
    {
        ll l,r;
        cin >> l >> r;
        if(l == r)
        {
            cout << k-1 << endl;
            continue;
        }
        ll tempans = num[l+1]-2+k-num[r-1]-1;
        if(r > l+1)
            tempans += preans[r-1]-preans[l];
        cout << tempans << endl;
    }
    return 0;
}