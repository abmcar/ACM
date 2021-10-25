#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define Maxn 123
using namespace std;

int n;
int num[Maxn];
bool used[Maxn];
int ans = 1e8;
vector<int> g[Maxn];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> num[i];
        int tempa,tempb;
        cin >> tempa >> tempb;
        if(tempa != 0)
        {
            g[i].push_back(tempa);
            g[tempa].push_back(i);
        }
        if(tempb != 0)
        {
            g[i].push_back(tempb);
            g[tempb].push_back(i);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            used[j] = 0;
        int totdis = 0;
        queue<int> qn,qd;
        qn.push(i);
        qd.push(0);
        used[i] = 1;
        while(!qn.empty())
        {
            int nownode = qn.front();
            int nowdis = qd.front();
            qn.pop();
            qd.pop();
            for(int j = 0; j < g[nownode].size(); j++)
            {
                int nextnode = g[nownode][j];
                int nextdis = nowdis+1;
                if(used[nextnode])
                    continue;
                used[nextnode] = 1;
                totdis += num[nextnode]*nextdis;
                qn.push(nextnode);
                qd.push(nextdis);
            }
        }
        ans = min(ans,totdis);
    }
    cout << ans;
    return 0;
}