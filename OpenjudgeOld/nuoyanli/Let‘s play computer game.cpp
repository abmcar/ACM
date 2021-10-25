#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n,s,d;
int dis[2333][2333];
int w[2333];
int f[2333];
bool used[2333];
int mindis = (int)1e9;
int ans;

void spfa()
{
    for(int i = 1; i <= n; i++)
        f[i] = (int)1e9;
    queue<int> tq;
    queue<int> tw;
    tq.push(s);
    tw.push(w[s]);
    f[s] = 0;
    while(tq.empty() != 1)
    {
        int nownode = tq.front();
        int noww = tw.front();
        tq.pop();
        tw.pop();
        //cout << nownode << " " << noww << endl;
        if(nownode == d)
        {
            if(f[d] < mindis)
                ans = noww;
            if(f[d] == mindis)
                ans = max(ans,noww);
            continue;
        }
        for(int i = 1; i <= n; i++)
        {
            if(i == nownode)
                continue;
            int nextnode = i;
            int nextdis = dis[nownode][i];
            int nextw = w[i];
            if(f[i] >= f[nownode]+nextdis)
            {
                f[i] = min(f[i],f[nownode]+nextdis);
                tq.push(nextnode);
                tw.push(nextw+noww);
            }
        }
    }
    return;
}
/*
void dfs(int nowdis,int nownode,int noww)
{
    if(nowdis > f[d])
        return;
    if(nownode == d)
    {
        if(nowdis == f[d])
        ans = max(noww,ans);
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(i == nownode)
            continue;
        int nextnode = i;
        int nextdis = dis[nownode][i];
        int nextw = w[i];
        if(used[nextnode])
            continue;
        used[nextnode] = 1;
        dfs(nowdis+nextdis,nextnode,noww+nextw);
        used[nextnode] = 0;
    }
    
    return;
}
*/
int main()
{
    cin >> n >> s >> d;
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
        cin >> dis[i][j];
    spfa();
    used[s] = 1;
    //dfs(0,s,w[s]);
    cout << f[d] << " " << ans;
    return 0;
}