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

int n;
ll num[Maxn];
ll tempans[Maxn];

int main()
{
    Buff;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    queue<int> qa;
    queue<ll> qn;
    queue<int> qd;
    qa.push(1);
    qd.push(1);
    qn.push(num[1]);
    int ans = 1e8;
    ll nowmaxn = -1e10;
    int maxdeep = 0;
    while (!qa.empty())
    {
        int nowa = qa.front();
        int nowd = qd.front();
        ll nownum = qn.front();
        qa.pop();
        qd.pop();
        qn.pop();
        tempans[nowd] += num[nowa];
        maxdeep = max(maxdeep,nowd);
        if(nowa*2 <= n)
        {
            qa.push(nowa*2);
            qd.push(nowd+1);
            qn.push(nownum + num[nowa*2]);
        }
        if(nowa*2+1 <= n)
        {
            qa.push(nowa*2+1);
            qd.push(nowd+1);
            qn.push(nownum + num[nowa*2+1]);
        }
    }
    for(int i = 1; i <= maxdeep; i++)
        if(tempans[i] > nowmaxn)
        {
            nowmaxn = tempans[i];
            ans = i;            
        }
    cout << ans;
    return 0;
}