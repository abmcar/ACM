#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define Maxn (int)2e3+1

using namespace std;

int k,n,m;
int cows[123];
vector<int> g[Maxn];
int ans;
int ok[Maxn];

void bfs(int strnode)
{
    bool used[Maxn];
    for(int i = 1; i <= n; i++)
        used[i] = 0;
    queue<int> qn;
    qn.push(strnode);
    while(!qn.empty())
    {
        int nownode = qn.front();
        qn.pop();
        if(used[nownode])
            continue;
        used[nownode] = 1;
        ok[nownode]++;
        // cout << "++:" << nownode << endl;
        for(int i = 0; i < g[nownode].size(); i++)
        if(used[g[nownode][i]])
            continue;
        else
            qn.push(g[nownode][i]);
    }
}

int main()
{
    cin >> k >> n >> m;
    for(int i = 1; i <= k; i++)
        cin >> cows[i];
    for(int i = 1; i <= m; i++)
    {
        int tempstr,tempend;
        cin >> tempstr >> tempend;
        g[tempstr].push_back(tempend);
    }
    for(int i = 1; i <= k; i++)
        bfs(cows[i]);
    for(int i = 1; i <= n; i++)
        if(ok[i] == k)
            ans++;
    cout << ans;
    return 0;
}
