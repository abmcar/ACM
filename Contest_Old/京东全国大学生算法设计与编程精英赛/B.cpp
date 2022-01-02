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
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

vector<int> g[Maxn];
ll fatherNode[Maxn], w[Maxn], p[Maxn], totw[Maxn];
ll nowL[Maxn], nowR[Maxn];
int n;
bool isL[Maxn];

void pushUp(int x)
{
    totw[x] = 0;
    for (int i = 0; i < g[x].size(); i++)
        totw[x] += g[x][i];
    if (fatherNode[x] != 0)
        pushUp(fatherNode[x]);
}


int main()
{
    Buff;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> fatherNode[i] >> w[i] >> p[i];
        g[fatherNode[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() == 0)
            isL[i] = true;
    }
    return 0;
}