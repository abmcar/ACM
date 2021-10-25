#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
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

const int Maxn = 25000000;
const ll Mod = 1e9+7;

int t, s, n;
int father[2077];
char originString[2077][8];
int ans;

struct Edge
{
    int from, to;
    int val;
    bool const operator<(Edge b) const
    {
        return val < b.val;
    }
} edge[Maxn];

int getDis(int pos1, int pos2)
{
    int tempans = 0;
    for (int i = 0; i < 7; i++)
    if (originString[pos1][i] != originString[pos2][i])
        tempans++;
    return tempans;
}

int find(int son)
{
    if (father[son] == son)
        return son;
    father[son] = find(father[son]);
    return father[son];
}
Edge V[Maxn];

int main()
{
    Buff;
    while (cin >> n)
    {
        if(n == 0)
            return 0;
        ans = 0;
        int cntEdge = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> originString[i];
            father[i] = i;

        }
        for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
        {
            V[++cntEdge].from = i;
            V[cntEdge].to = j;
            V[cntEdge].val = getDis(i,j);
        }
        sort(V+1,V+1+cntEdge);
        for(int i = 1; i <= cntEdge; i++)
        {
            Edge nowEdge = V[i];
            int f1 = find(nowEdge.from);
            int f2 = find(nowEdge.to);
            if (f1 == f2)
                continue;
            father[f1] = f2;
            ans += nowEdge.val;
        }
        cout << "The highest possible quality is 1/" << ans << ".\n";
    }
    return 0;
}