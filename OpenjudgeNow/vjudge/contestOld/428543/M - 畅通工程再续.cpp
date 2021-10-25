#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <iomanip>
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

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;

int father[Maxn];
int t, c;
int posX[Maxn], posY[Maxn];
double ans;

struct Edge
{
    int from, to;
    double dis;
    bool const operator < (Edge b) const
    {
        return dis > b.dis;
    }
};
priority_queue<Edge> q;

int find(int son)
{
    if(father[son] == son)
        return son;
    father[son] = find(father[son]);
    return father[son];
}

double getDis(int pos1, int pos2)
{
    double x1 = posX[pos1];
    double x2 = posX[pos2];
    double y1 = posY[pos1];
    double y2 = posY[pos2];
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool check()
{
    for(int i = 2; i <= c; i++)
        if(find(1) != find(i))
            return false;
    return true;
}

void work()
{
    ans = 0;
    cin >> c;
    for(int i = 1; i <= c; i++)
    {
        father[i] = i;
        cin >> posX[i] >> posY[i];
    }
    for(int i = 1; i <= c; i++)
    for(int j = i+1; j <= c; j++)
        if(getDis(i,j) >= 10 && getDis(i,j) <= 1000)
        {
            Edge temp;
            temp.from = i;
            temp.to = j;
            temp.dis = getDis(i,j)*100;
            q.push(temp);
        }
    while(!q.empty())
    {
        Edge nowEdge = q.top();
        q.pop();
        if(find(nowEdge.from) == find(nowEdge.to))
            continue;
        ans += nowEdge.dis;
        father[find(nowEdge.from)] = find(nowEdge.to);
    }
    if(!check())
        cout << "oh!" << endl;
    else
        cout << fixed << setprecision(1) << ans << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}