#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>

#define Maxn (int)1e3+233
using namespace std;

int n,m,k;
vector<int> g[Maxn];
vector<int> w[Maxn];
int deep[Maxn];
int f[Maxn];

void bfs1()
{
    queue<int> qn;
    qn.push(1);
    bool used[Maxn];
    for(int i = 1; i <= n; i++)
        used[i] = 0;
    used[1] = 1;
    while(!qn.empty())
    {
        int nownode = qn.front();
        qn.pop();
        for(int i = 0; i < g[nownode].size(); i++)
        {
            int nextnode = g[nownode][i];
            if(deep[nextnode] == 0)
                deep[nextnode] = deep[nownode]+1;
            if(used[nextnode])
                continue;
            used[nextnode] = 1;
            qn.push(nextnode);
        }
    }
}

bool check(int length)
{
    queue<int> qn;
    qn.push(1);
    int f[Maxn];
    for(int i = 1; i <= n; i++)
        f[i] = 1e8;
    f[1] = 0;
    //     for(int i = 1; i <= n; i++)
    //     cout << f[i] << " ";
    // cout << endl;
    while(!qn.empty())
    {
        int nownode = qn.front();
        qn.pop();
        for(int i = 0; i < g[nownode].size(); i++)
        {
            int nextnode = g[nownode][i];
            int nextdis = w[nownode][i];
            if(nextdis >= length)
                nextdis = 1;
            else
                nextdis = 0;
                // cout << "test:" << " " << nownode << " " << nextnode << " " << f[nextnode] << " " << f[nownode]+nextdis << endl;
            if(f[nextnode] > f[nownode]+nextdis)
            {
                f[nextnode] = f[nownode]+nextdis;
                qn.push(nextnode);
            }
        }
    }
    // for(int i = 1; i <= n; i++)
    //     cout << f[i] << " ";
    // cout << endl;
    return f[n] > k;
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int fromnode,endnode,length;
        cin >> fromnode >> endnode >> length;
        g[fromnode].push_back(endnode);
        g[endnode].push_back(fromnode);
        w[fromnode].push_back(length);
        w[endnode].push_back(length);
    }
    bfs1();
    if(deep[n] == 0)
    {
        cout << "-1";
        return 0;
    }
    if(deep[n] <= k)
    {
        cout << "0";
        return 0;
    }
    int l = 0;
    int r = 1e6;
    int ans;
    while(l <= r)
    {
        // cout << l << " " << r << endl;
        int mid = (l+r)/2;
        if(check(mid))
        {
            ans = mid;
            l = mid+1;
        }else
            r = mid-1;
    }
    cout << ans;
    return 0;
}