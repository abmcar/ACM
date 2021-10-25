#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define Maxn (int)1e5+10
using namespace std;

int n,m;
int maxdis[Maxn];
bool used[Maxn];
vector<int> g[Maxn];

void bfs(int strnode)
{
    used[strnode] = 1;
    queue<int> qn;
    qn.push(strnode);
    while (!qn.empty())
    {
        int nownode = qn.front();
        qn.pop();
        for(int i = 0; i < g[nownode].size(); i++)
        {
            int nextnode = g[nownode][i];
            if(used[nextnode])
                continue;
            used[nextnode] = 1;
            maxdis[nextnode] = strnode;
            qn.push(nextnode);
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
        g[tempend].push_back(tempstr);
    }
    for(int i = 1; i <= n; i++)
        maxdis[i] = i;
    for(int i = n; i >= 1; i--)
        if(used[i])
            continue;
        else
            bfs(i);
    for(int i = 1; i <= n; i++)
        cout << maxdis[i] << " ";
    return 0;
}