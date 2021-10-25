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
struct Pos
{
    int x,y;
};
int n,m;

void get()
{
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        cin >> bd[i][j];
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

void print()
{
    stack<Pos> s;
    Pos pos;
    pos.x = n;
    pos.y = m;
    s.push(pos);
    while(s.top().x != 1 || s.top().y != 1)
    {
        int nowx = s.top().x;
        int nowy = s.top().y;
        // cout << nowx << " " << nowy << endl;
        int nowstatus = status[nowx][nowy];
        Pos next;
        next.x = nowx-nx[nowstatus];
        next.y = nowy-ny[nowstatus];
        s.push(next);
        // cout << nowx << " " << nowy << endl;
    }
    
    int nowtime = 0;
    int prex = 1;
    int prey = 1;
    while(!s.empty())
    {
        int nowx = s.top().x;
        int nowy = s.top().y;
        cout << "(" << nowx-1 << ", " << nowy-1 << ")" << endl;
        s.pop();       
    }
}

void work()
{
    get();
    clear();
    priority_queue<Node, vector<Node>> q;
    Node temp;
    temp.x = 1;
    temp.y = 1;
    temp.time = 1;
    q.push(temp);
    while(!q.empty())
    {
        Node node = q.top();
        q.pop();
        // node.print();
        if(node.x == n && node.y == m)
        {
            cnttime = node.time;
            print();
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
            if(bd[nextx][nexty] == '1')
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
    n = m = 5;
        work();
    return 0;
}