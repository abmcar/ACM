#include<iostream>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#define Maxn 223
using namespace std;

int status[Maxn][Maxn];
char bd[Maxn][Maxn];
bool vised[Maxn][Maxn];
int nx[4] = {0,1,0,-1};
int ny[4] = {1,0,-1,0};
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
int ttime;

void get()
{
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    {
        cin >> bd[i][j];
        if(bd[i][j] == 'Y')
            strx = i,stry = j;
        if(bd[i][j] == '@')
            endx = i,endy = j;
    }
}

void clear()
{
    cnttime = -1;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    {
        status[i][j] = -1;
        vised[i][j] = 0;
    }
}

void work()
{
    get();
    clear();
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
        if(node.x == endx && node.y == endy)
        {
            cnttime = node.time;
            ttime = cnttime;
            return;
        }
        for(int i = 0; i < 4; i++)
        {
            int nextx = node.x + nx[i];
            int nexty = node.y + ny[i];
            int nextt = node.time + 1;
            if(nextx > n || nexty > m || nextx < 1 || nexty < 1)
                continue;
            if(vised[nextx][nexty] == true)
                continue;
            if(bd[nextx][nexty] == '#')
                continue;
            status[nextx][nexty] = i;
            vised[nextx][nexty] = true;
            Node nextnode;
            nextnode.x = nextx;
            nextnode.y = nexty;
            nextnode.time = nextt;
            q.push(nextnode);
        }
    }
}

void work1()
{
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    {
        if(bd[i][j] == 'M')
            strx = i,stry = j;
        if(bd[i][j] == '@')
            endx = i,endy = j;
    }
    clear();
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
        if(node.x == endx && node.y == endy)
        {
            cnttime = node.time;
            cout << (cnttime+ttime)*11 << endl;
            return;
        }
        for(int i = 0; i < 4; i++)
        {
            int nextx = node.x + nx[i];
            int nexty = node.y + ny[i];
            int nextt = node.time + 1;
            if(nextx > n || nexty > m || nextx < 1 || nexty < 1)
                continue;
            if(vised[nextx][nexty] == true)
                continue;
            if(bd[nextx][nexty] == '#')
                continue;
            status[nextx][nexty] = i;
            vised[nextx][nexty] = true;
            Node nextnode;
            nextnode.x = nextx;
            nextnode.y = nexty;
            nextnode.time = nextt;
            q.push(nextnode);
        }
    }
}

int main()
{
    while(cin >> n >> m)
    {
        work();
        work1();
    }
    return 0;
}
