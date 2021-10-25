#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define Maxn 1234

using namespace std;

vector<int> g[Maxn];
int wid[Maxn];
int maxdeep;
int maxwid;
int strnode,endnode;
int n,dis;
bool used[Maxn];

void getdis()
{
    queue<int> qn,qd;
    qn.push(1);
    qd.push(1);
    wid[1] = 1;
    used[1] = 1;
    while(!qn.empty())
    {
        int nownode = qn.front();
        int nowdeep = qd.front();
        qn.pop();
        qd.pop();
        for(int i = 0; i < g[nownode].size(); i++)
        {
            int nextnode = g[nownode][i];
            int nextdeep = nowdeep+1;
            if(used[nextnode])
                continue;
            used[nextnode] = 1;
            wid[nextdeep]++;
            maxwid = max(maxwid,wid[nextdeep]);
            maxdeep = max(maxdeep,nextdeep);
            qn.push(nextnode);
            qd.push(nextdeep);
        }
    }
    // cout << maxwid << endl << maxdeep << endl;
}

void getdis(int strnode,int endnode)
{
    for(int i = 1; i <= n; i++)
        used[i] = 0;
    queue<int> qn,qd;
    qn.push(strnode);
    qd.push(0);
    used[strnode] = 1;
    while(!qn.empty())
    {
        int nownode = qn.front();
        int nowdis = qd.front();
        qn.pop();
        qd.pop();
        if(nownode == endnode)
        {
            dis = nowdis;
            return;
        }
        for(int i = 0; i < g[nownode].size(); i++)
        {
            int nextnode = g[nownode][i];
            int nextdis = nowdis + 1;
            if(used[nextnode])
                continue;
            if(nextnode < nownode)
                nextdis++;
            used[nextnode] = 1;
            qn.push(nextnode);
            qd.push(nextdis);
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int tempa,tempb;
        cin >> tempa >> tempb;
        g[tempa].push_back(tempb);
        g[tempb].push_back(tempa);
    }
    cin >> strnode >> endnode;
    getdis();
    getdis(strnode,endnode);
    cout << maxdeep << endl << maxwid << endl << dis;
    return 0;
}