#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define Maxn (int)1e4+10
#define Mod 80112002
using namespace std;

vector<int> g[Maxn];
int n,m;
int r[Maxn];
long long ans;
long long nowqueue[Maxn];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int tempstr,tempend;
        cin >> tempend >> tempstr;
        r[tempend]++;
        g[tempstr].push_back(tempend);
    }
    queue<int> qn;
    for(int i = 1; i <= n; i++)
        if(r[i] == 0)
            qn.push(i),nowqueue[i]++;
    while(!qn.empty())
    {
        int nownode = qn.front();
        qn.pop();
        // cout << nownode << endl;
        if(g[nownode].size() == 0)
        {
            ans = ans%Mod + nowqueue[nownode]%Mod;
            nowqueue[nownode] = 0;
            ans %= Mod;
            continue;
        }
        for(int i = 0; i < g[nownode].size(); i++)
        {
            if(nowqueue[g[nownode][i]] != 0)
            {
                nowqueue[g[nownode][i]]+=nowqueue[nownode];
                nowqueue[g[nownode][i]] %= Mod;
                continue;
            }
            qn.push(g[nownode][i]);
            nowqueue[g[nownode][i]] = nowqueue[nownode];
            nowqueue[g[nownode][i]] %= Mod;
        }
        nowqueue[nownode] = 0;
    }
    cout << ans;
    return 0;
}