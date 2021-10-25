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

const int Maxn = 666;
const ll Mod = 1e9 + 7;

int nx[5] = {0, 1, 0, -1, 0};
int ny[5] = {0, 0, 1, 0, -1};
int n, m, t;
int ans;
bool used[Maxn][Maxn];
int bd[Maxn][Maxn];
int father[Maxn];
bool lastUsed[Maxn];

struct Node
{
    int x, y;
};


struct Segment
{
    int str, end;
    bool const operator < (Segment b) const
    {
        if(str == b.str)
            return end > b.end;
        return str < b.str;
    }
}segment[Maxn];

void bfs(int posX, int posY)
{
    queue<Node> Q;
    memset(used,0,sizeof(used));
    Q.push({posX, posY});
    int str = 1e9;
    int end = 0;
    while (!Q.empty())
    {
        Node nowNode = Q.front();
        Q.pop();
        if (nowNode.x == n)
        {
            father[nowNode.y] = posY;
            str = min(str,nowNode.y);
            end = max(end,nowNode.y);
            // cout << nowNode.y << "    " << posY << endl;
            // continue;
        }
        for (int i = 1; i <= 4; i++)
        {
            Node nextNode;
            nextNode.x = nowNode.x + nx[i];
            nextNode.y = nowNode.y + ny[i];
            if (nextNode.x > n || nextNode.y > m || nextNode.x < 1 || nextNode.y < 1)
                continue;
            if (used[nextNode.x][nextNode.y])
                continue;
            if (bd[nowNode.x][nowNode.y] <= bd[nextNode.x][nextNode.y])
                continue;
            used[nextNode.x][nextNode.y] = true;
            Q.push(nextNode);
        }
    }
    if(str == 1e9)
        str = -1;
    segment[posY].str = str;
    segment[posY].end = end;
}

int main()
{
    Buff;
    // freopen("P1514_5.in","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> bd[i][j];
    for (int i = 1; i <= m; i++)
    {
        if(bd[1][i] < bd[1][i-1])
        {
            segment[i].str = -1;
            segment[i].end = 0;
            continue;
        }
        bfs(1, i);
    }
    bool ok = true;
    int t1 = 0;
    for (int i = 1; i <= m; i++)
    {
        if (father[i] == 0)
            ok = false, t1++;
    }
    if(!ok)
    {
        cout << "0" << endl;
        cout << t1 << endl;
        return 0;
    }
    sort(segment+1,segment+1+m);
    int now = 1;
    int finans = 0;
    while (now != m)
    {
        // cout << now << endl;
        int temppos = 0;
        int maxn = 0;
        for(int i = 1; i <= m; i++)
        {
            if(lastUsed[i])
                continue;
            if(segment[i].str-1 <= now)
            {
                if(maxn < segment[i].end)
                {
                    maxn = segment[i].end;
                    temppos = i;
                }
            }
        }
        now = max(now,maxn);
        finans++;
        lastUsed[temppos] = true;
    }

    // for(int i = 1; i <= m; i++)
    // {
    //     if(now <= segment[i].str)
    //     {
    //         finans++;
    //         now = segment[i].end;
    //     }
    //     cout << segment[i].str << " " << segment[i].end << " " << finans << endl;
    // }
    cout << 1 << endl;
    cout << finans << endl;
    return 0;
}