#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

#define Maxn (int)1e3+100

using namespace std;

int n,m;
int r[Maxn];
int deep[Maxn];
vector<int> g[Maxn];
bool isedge[Maxn][Maxn];
bool used[Maxn];
int maxdeep;

queue<int> qn;

void bfs()
{
    // cout << strnode << endl;
    while (!qn.empty())
    {
        int nownode = qn.front();
        qn.pop();
        if(used[nownode])
            continue;
        used[nownode] = 1;
        // cout << "nownode:" << nownode << endl;
        for(int i = 0; i < g[nownode].size(); i++)
        {
            int nextnode = g[nownode][i];
            r[nextnode]--;
            deep[nextnode] = max(deep[nextnode],deep[nownode]+1);
            maxdeep = max(maxdeep,deep[nextnode]);
            if(r[nextnode] == 0)
            {
                qn.push(nextnode);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int totn,tempn;
        cin >> totn;
        int tempc[Maxn];
        bool issite[Maxn];
        for(int i = 1; i <= Maxn; i++)
            issite[i] = 0;
        for(int j = 1; j <= totn; j++)
            cin >> tempc[j],issite[tempc[j]]=1;
        // if(tempc[totn]-tempc[1] == totn-1)
        //     continue;
        for(int j = 1; j <= totn; j++)
        {
            int fromnode = tempc[j];
            for(int k = tempc[1]+1; k < tempc[totn]; k++)
                if(issite[k] || isedge[fromnode][k])
                    continue;
                else
                    g[fromnode].push_back(k),r[k]++,isedge[fromnode][k] = 1;
        }
    }
    for(int i = 1; i <= n; i++)
        if(r[i] == 0)
            deep[i]++;
    for(int i = 1; i <= n; i++)
        if(r[i] == 0 && used[i] == 0)
            qn.push(i);
    bfs();
    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 0; j < g[i].size(); j++)
    //         cout << g[i][j] << " ";
    //     cout << endl;
    // }
    cout << maxdeep;
    return 0;
}