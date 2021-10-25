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
int ans[Maxn];
vector<int> g[Maxn];

void build(int father, int l, int r)
{
    if(l > r)
        return;
    int maxn = 0;
    for(int i = l; i <= r; i++)
        maxn = max(maxn,num[i]);
    for(int i = l; i <= r; i++)
        if(maxn == num[i])
        {
            g[father].push_back(i);
            build(i,l,i-1);
            build(i,i+1,r);
            break;
        }
}

void work()
{
    cin >> n;
    int maxn = 0;
    int strpos;
    memset(ans,0,sizeof(ans));
    for(int i = 1; i <= n; i++)
        cin >> num[i], maxn = max(maxn,num[i]), g[i].clear();
    for(int i = 1; i <= n; i++)
        if(maxn == num[i])
        {
            build(i,1,i-1);
            build(i,i+1,n);
            strpos = i;
            break;
        }
    queue<int> qn;
    qn.push(strpos);
    while (!qn.empty())
    {
        int nownode = qn.front();
        qn.pop();
        // cout << nownode << endl;
        for(int i = 0; i < g[nownode].size(); i++)
        {
            int nextnode = g[nownode][i];
            ans[nextnode] = ans[nownode]+1;
            qn.push(nextnode);
        }
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    Buff;
    cin >> t;
    while(t--)
        work();
    return 0;
}