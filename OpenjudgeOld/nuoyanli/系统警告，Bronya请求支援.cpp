#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n,m,x,k;
vector<int> g[233333];
int dis1[233333];
int dis2[233333];
int safeplaces[233333];

void get()
{
    cin >> n >> m >> x;
    for(int i = 1; i <= m; i++)
    {
        int ta,tb;
        cin >> ta >> tb;
        g[ta].push_back(tb);
        g[tb].push_back(ta);
    }
    cin >> k;
    for(int i = 1; i <= k; i++)
        cin >> safeplaces[i];
}

void spfa(int str,int dis[])
{
    for(int i = 1; i <= n; i++)
        dis[i] = 1e8;
    queue<int> tq;
    tq.push(str);
    dis[str] = 0;
    while(tq.empty() != 1)
    {
        int now = tq.front();
        tq.pop();
        for(int i = 0; i < g[now].size(); i++)
        {
            int next = g[now][i];
            if(dis[next] > dis[now]+1)
            {
                tq.push(next);
                dis[next] = dis[now]+1;
            }
        }
    }
}

void work()
{
    spfa(1,dis1);
    spfa(n,dis2);
    int ans = 1e8;
    if(dis1[n] == 1e8)
    {
        cout << "-1";
        return;
    }
    if(dis1[n] <= x)
    {
        cout << dis1[n];
        return;
    }
    for(int i = 1; i <= k; i++)
        if(dis1[safeplaces[i]] <= x)
            ans = min(ans,dis2[safeplaces[i]] + x);
    if(ans == 1e8)
        ans = -1;
    cout << ans;
    return;
}

int main()
{
	get();
    work();
    return 0;
} 