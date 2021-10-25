#include <iostream>
#include <map>
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

using namespace std;

const int Maxn = 1e6+10;
const ll Mod = 1e9+7;
int n,q;
int father[Maxn];
map<string,int> M;

struct Edge
{
    int from,to;
    ll val;
    bool const operator< (const Edge b) const
    {
        return val < b.val;
    }
}edge[Maxn];

int find(int son)
{
    if(father[son] == son)
        return son;
    father[son] = find(father[son]);
    return father[son];
}


bool check()
{
    for (int i = 2; i <= n; i++)
        if (find(i) != find(i - 1))
            return 0;
    return 1;
}

void work()
{
    M.clear();
    string temp;
    int nowcitys = 0;
    ll ans = 0;
    cin >> temp;
    M[temp] = ++nowcitys;
    for(int i = 1; i <= n; i++)
        father[i] = i;
    for(int i = 1; i <= q; i++)
    {
        // father[i] = i;
        string ta,tb;
        cin >> ta >> tb;
        if(M[ta] == 0)
            M[ta] = ++nowcitys;
        if(M[tb] == 0)
            M[tb] = ++nowcitys;
        edge[i].from = M[ta];
        edge[i].to = M[tb];
        cin >> edge[i].val;
    }
    // if(n == 1)
    // {
    //     cout << "0\n";
    //     return;
    // }
    sort(edge+1,edge+1+q);
    for(int i = 1; i <= q; i++)
    {
        if(find(edge[i].from) != find(edge[i].to))
        {
            ans += edge[i].val;
            father[find(edge[i].from)] = find(father[edge[i].to]);
        }
    }
    if(check())
        cout << ans << endl;
    else
        cout << "No!"<< endl;
}

int main()
{
    Buff;
    while(cin >> n >> q)
        work();
    return 0;
}