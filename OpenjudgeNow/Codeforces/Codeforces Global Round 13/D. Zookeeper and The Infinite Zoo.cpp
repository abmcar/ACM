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
int q;
ll u,v;

int main()
{
    Buff;
    cin >> q;
    for(int i = 1; i <= q; i++)
    {
        cin >> u >> v;
        // for(int j = 1; j <= v; j++)
        //     cout << u+j << " " << ((u&j)==j) << endl;
        if(u == v)
        {
            cout << "YES" << endl;
            continue;
        }
        priority_queue<ll> Q;
        map<ll,bool> M;
        Q.push(u);
        bool isend = false;
        while(!Q.empty())
        {
            if(isend)
            {
                Q.pop();
                continue;
            }
            ll now = Q.top();
            Q.pop();
            // cout << now << endl;
            for(ll j = 1; j+now <= v; j++)
            {
                ll temp1 = j;
                ll temp2 = now;
                if(M[now+j])
                    continue;
                if((temp1 & temp2) == j)
                {
                    // cout << now << " " << (temp1 & temp2) << endl;
                    if(j+now == v)
                    {
                        cout << "YES" << endl;
                        isend = true;
                        break;
                    }
                    M[now+j] = true;
                    Q.push(now+j);
                }
            }
        }
        if(!isend)
        cout << "NO" << endl;
    }
    return 0;
}