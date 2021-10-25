#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define Maxnode (int)1e5+10
using namespace std;

int n,m;
int r[Maxnode];
bool used[Maxnode];
vector<int> g[Maxnode];
int strnode = 1;

void dfs(int node)
{
    cout << node << " ";
    used[node] = 1;
    for(int i = 0; i < g[node].size(); i++)
    {
        if(used[g[node][i]])
            continue;
        used[g[node][i]] = 1;
        dfs(g[node][i]);
    }
}

void bfs(int node)
{
    queue<int> qn;
    qn.push(node);
    used[node] = 1;
    while(!qn.empty())
    {
        int nownode = qn.front();
        qn.pop();
        cout << nownode << " ";
        for(int i = 0; i < g[nownode].size(); i++)
        {
            if(used[g[nownode][i]])
                continue;
            used[g[nownode][i]] = 1;
            qn.push(g[nownode][i]);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int tempstr,tempend;
        cin >> tempstr >> tempend;
        r[tempend]++;
        g[tempstr].push_back(tempend);
    }
    for(int i = 1; i <= n; i++)
    {
        if(strnode == 0 && r[i] == 0)
            strnode = i;
        sort(g[i].begin(),g[i].end());
    }
    dfs(strnode);
    cout << endl;
    for(int i = 1; i <= n; i++)
        used[i] = 0;
    bfs(strnode);
    return 0;    
}