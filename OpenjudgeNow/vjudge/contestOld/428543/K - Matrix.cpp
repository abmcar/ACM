#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e6;
const ll Mod = 1e9+7;

int father[Maxn];
ll t, n, k, ans;

struct Edge
{
    ll from,to,val;
    bool const operator < (Edge b) const
    {
        return val > b.val;
    }
};
vector<Edge> V;

int find(int son)
{
    if(father[son] == son)
        return son;
    father[son] = find(father[son]);
    return father[son];
}

void work()
{
    ans = 0;
    cin >> n >> k;
    V.clear();
    for(int i = 0; i <= n; i++)
        father[i] = i;
    for(int j = 2; j <= n; j++)
    {
        Edge temp;
        cin >> temp.from >> temp.to >> temp.val;
        V.push_back(temp);
    }
    unordered_map<int,bool> M;
    for(int i = 1; i <= k; i++)
    {
        int temp;
        cin >> temp;
        M[temp] = true;
    }
    sort(V.begin(),V.end());
    for(int i = 0; i < V.size(); i++)
    {
        Edge nowEdge = V[i];
        int f1 = find(nowEdge.from);
        int f2 = find(nowEdge.to);
        bool b1,b2;
        b1 = b2 = false;
        if(M[f1])
            b1 = true;
        if(M[f2])
            b2 = true;
        if(b1 && b2)
        {
            ans += nowEdge.val;
            continue;
        }
        if(b1)
        {
            father[f2] = f1;
            continue;
        }
        father[f1] = f2;
    }
    cout << ans << endl;
}

int main()
{
    Buff;
    cin >> t;
    while(t--)
        work();
    return 0;
}
