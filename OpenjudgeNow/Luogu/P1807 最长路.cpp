#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define Maxn 2333
using namespace std;

int n,m;
vector<int> g[Maxn];
vector<int> w[Maxn];
int f[Maxn];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int tempstr,tempend,tempw;
        cin >> tempstr >> tempend >> tempw;
        g[tempstr].push_back(tempend);
        w[tempstr].push_back(tempw);
    }
    for(int i = 1; i <= n; i++)
        f[i] = -1e9;
    queue<int> qn;
    qn.push(1);
    f[1] = 0;
    while(!qn.empty())
    {
        int nownode = qn.front();
        qn.pop();
        for(int i = 0; i < g[nownode].size(); i++)
        {
            int nextdis = f[nownode] + w[nownode][i];
            if(nextdis > f[g[nownode][i]])
                f[g[nownode][i]] = nextdis,qn.push(g[nownode][i]);
        }
    }
    if(f[n] == -1e9)
        f[n] = -1;
    cout << f[n];
    return 0;
}