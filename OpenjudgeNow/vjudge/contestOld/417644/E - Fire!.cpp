#include<iostream>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#define Maxn 2233
using namespace std;

int status[Maxn][Maxn];
char bd[Maxn][Maxn];
bool vised[Maxn][Maxn];
bool vvised[Maxn][Maxn];
int nx[4] = {0,1,0,-1};
int ny[4] = {1,0,-1,0};
int ttime[Maxn][Maxn];
int cnttime;
struct Node
{
    int x,y,time;
    bool operator<(const Node b)const
    {
        return time > b.time;
    }
    void print()
    {
        cout << x << " " << y << " " << time << endl;
    }
};
int strx,stry,endx,endy;
int n,m;

void get()
{
    for(int i = 0; i <= n+1; i++)
    for(int j = 0; j <= m+1; j++)
        bd[i][j] = '?',ttime[i][j] = 1e7;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    {
        cin >> bd[i][j];
        if(bd[i][j] == 'J')
            strx = i,stry = j;
        if(bd[i][j] == 'F')
            endx = i,endy = j;
    }
}

void clear()
{
    cnttime = 1e8;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    {
        status[i][j] = -1;
        vised[i][j] = 0;
        vvised[i][j] = 0;
    }
}

void prework()
{
    queue<Node> q;
    Node temp;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    if(bd[i][j] == 'F')
    {
        temp.x = i;
        temp.y = j;
        temp.time = 0;
        q.push(temp);
        vvised[i][j] = 1;
    }
    while(!q.empty())
    {
        Node node = q.front();
        q.pop();
        // node.print();
        ttime[node.x][node.y] = node.time;
        for(int i = 0; i < 4; i++)
        {
            int nextx = node.x + nx[i];
            int nexty = node.y + ny[i];
            int nextt = node.time + 1;
            if(nextx > n || nexty > m || nextx < 1 || nexty < 1)
                continue;
            if(ttime[nextx][nexty] != 1e7)
                continue;
            if(vvised[nextx][nexty] == true)
                continue;
            if(bd[nextx][nexty] == '#')
                continue;
            vvised[nextx][nexty] = true;
            Node nextnode;
            nextnode.x = nextx;
            nextnode.y = nexty;
            nextnode.time = nextt;
            q.push(nextnode);
        }
    }
    // for(int i = 0; i <= n+1; i++)
    // {
    //     for(int j = 0; j <= m+1; j++)
    //         cout << ttime[i][j] << " ";
    //     cout << endl;
    // }
}

void work()
{
    get();
    clear();
    prework();
    priority_queue<Node, vector<Node>> q;
    Node temp;
    temp.x = strx;
    temp.y = stry;
    temp.time = 0;
    q.push(temp);
    while(!q.empty())
    {
        Node node = q.top();
        q.pop();
        // node.print();
        // if(bd[node.x][node.y] == '?')
        // {
        //     cnttime = min(cnttime,node.time);
        //     continue;
        // }
        if(ttime[node.x][node.y] <= node.time)
            continue;
        if(node.x == 1 || node.y == 1 || node.x == n || node.y == m)
        {
            cout << node.time+1 << endl;
            return;
        }
        for(int i = 0; i < 4; i++)
        {
            int nextx = node.x + nx[i];
            int nexty = node.y + ny[i];
            int nextt = node.time + 1;
            if(nextx > n+1 || nexty > m+1 || nextx < 0 || nexty < 0)
                continue;
            if(vised[nextx][nexty] == true)
                continue;
            if(bd[nextx][nexty] == '#')
                continue;
            if(bd[nextx][nexty] == '?')
            {
                cout << nextt << endl;
                return;
            }
            if(nextt > ttime[nextx][nexty])
                continue;
            vised[nextx][nexty] = true;
            Node nextnode;
            nextnode.x = nextx;
            nextnode.y = nexty;
            nextnode.time = nextt;
            q.push(nextnode);
        }
    }
    if(cnttime == 1e8)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << cnttime << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    freopen("a.out","w",stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cin >> n >> m;
        work();
    }
    // while(cin >> n >> m)
    return 0;
}
