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

const int Maxn = 2e5+10;
const ll Mod = 1e9+7;

int t, n;
int q[Maxn];

void work()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> q[i];
    bool M[Maxn];
    int minn = 1;
    int maxn = n;
    for(int i = 1; i <= n; i++)
        M[i] = false;
    for(int i = 1; i <= n; i++)
    {
        if(M[q[i]] == false)
        {
            cout << q[i] << " ";
            M[q[i]] = true;
            continue;
        }
        for(minn; minn <= q[i]; minn++)
        if(M[minn] == false)
        {
            cout << minn << " ";
            M[minn] = true;
            break;
        }
    }
    cout << endl;
    for(int i = 1; i <= n; i++)
        M[i] = false;
    // M.clear();
    for(int i = 1; i <= n; i++)
    {
        if(q[i] == q[i-1]+1)
        {
            cout << q[i] << " ";
            M[q[i]] = true;
            continue;
        }
        if(q[i] != q[i-1])
            minn = q[i];
        for(;minn >= 1; minn--)
        if(M[minn] == false)
        {
            M[minn] = true;
            cout << minn << " ";
            break;
        }
    }
    cout << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}