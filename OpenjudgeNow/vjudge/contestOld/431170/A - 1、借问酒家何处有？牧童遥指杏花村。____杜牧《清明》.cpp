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

const int Maxn = 1e3+10;
const ll Mod = 1e9+7;

ll ans = 1;
int father[Maxn];
int n, m;
map<int,int> M;

int find(int son)
{
    if (father[son] == son)
        return son;
    father[son] = find(father[son]);
    return father[son];
}

int main()
{
    Buff;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        father[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int ta,tb;
        cin >> ta >> tb;
        int f1 = find(ta);
        int f2 = find(tb);
        if(f1 == f2)
            continue;
        father[f1] = f2;
    }
    for (int i = 1; i <= n; i++)
        M[find(i)]++;
    for (auto i = M.begin(); i != M.end(); i++)
        for (int j = 1; j < i->second; j++)
            ans *= 2;
    cout << ans;
    return 0;
}