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
int t,n,m;
int rk[Maxn];
int father[Maxn];

int find(int son)
{
    if(father[son] == son)
        return son;
    int temp = find(father[son]);
    rk[son] = (rk[son] + rk[father[son]]) % 2;
    father[son] = temp;
    return temp;
}

int main()
{
    Buff;
    cin >> t;
    for(int k = 1; k <= t; k++)
    {
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
        {
            father[i] = i;
            rk[i] = 0;
        }
        bool ok = false;
        int t1,t2;
        for(int i = 1; i <= m; i++)
        {
            cin >> t1 >> t2;
            if(ok)
                continue;
            int f1 = find(t1);
            int f2 = find(t2);
            if(f1 == f2)
            {
                if((rk[t1] - rk[t2]) % 2 == 0)
                {
                    ok = true;
                    continue;
                }
            }else
            {
                father[f1] = f2;
                rk[f1] = (rk[t1] + rk[t2] + 1) % 2;
            }
        }
        cout << "Scenario #" << k << ":" << endl;
        if(ok)
            cout << "Suspicious bugs found!" << endl;
        else
            cout << "No suspicious bugs found!" << endl;
        cout << endl;
    }
    return 0;
}