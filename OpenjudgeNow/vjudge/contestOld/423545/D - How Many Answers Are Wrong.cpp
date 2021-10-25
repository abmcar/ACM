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
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 200010;
const ll Mod = 1e9 + 7;

int n, m;
int dis[Maxn];
int father[Maxn];
int ans;

int find(int son)
{
    if(father[son] == son)
        return son;
    int i = father[son];
    father[son] = find(father[son]);
    dis[son] += dis[i];
    return father[son];
}

int main()
{
    Buff;
    while (cin >> n >> m)
    {
        ans = 0;
        for (int i = 0; i <= n; i++)
        {
            father[i] = i;
            dis[i] = 0;
        }
        while(m--)
        {
            int begin,end,value;
            cin >> begin >> end >> value;
            begin--;
            int faBegin = find(begin);
            int faEnd = find(end);
            if (faBegin == faEnd)
            {
                if(dis[begin] - dis[end] != value)
                    ans++;
            }else
            {
                father[faBegin] = faEnd;
                dis[faBegin] = dis[end] - dis[begin] + value;
            }
        }
        cout << ans << endl;
    }
    return 0;
}