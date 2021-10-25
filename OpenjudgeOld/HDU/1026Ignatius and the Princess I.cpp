#include<iostream>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#define Maxn 123
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
    cout << "It takes " << cnttime-1 << " seconds to reach the target position, let me show you the way." << endl;
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
        // cout << nowx << " " << nowy << endl;
        s.pop();
        if(nowx == 1 && nowy == 1 && bd[nowx][nowy] < '1' && bd[nowx][nowy] > '9')
            continue;
        if(nowx != 1 || nowy != 1)
        {
            nowtime++;
            cout << nowtime << "s:(" << prex-1 << "," << prey-1 << ")->(" << nowx-1 << "," << nowy-1 << ")" << endl;
            prex = nowx;
            prey = nowy;
        }          
        if(bd[nowx][nowy] >= '1' && bd[nowx][nowy] <= '9')
        {
            for(int i = 1; i <= bd[nowx][nowy]-'0'; i++)
            {
                nowtime++;
                cout << nowtime << "s:FIGHT AT (" << nowx-1 << "," << nowy-1 << ")" << endl;
            }
        }
    }
    cout << "FINISH" << endl;
    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= m; j++)
    //         cout << status[i][j] << " ";
    //     cout << endl;
    // }
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
            if(bd[nextx][nexty] == 'X')
                continue;
            if(bd[nextx][nexty] >= '1' && bd[nextx][nexty] <= '9')
                nextt += bd[nextx][nexty]-'0';
            status[nextx][nexty] = i;
            vised[nextx][nexty] = true;
            Node nextnode;
            nextnode.x = nextx;
            nextnode.y = nexty;
            nextnode.time = nextt;
            q.push(nextnode);
        }
    }
    cout << "God please help our poor hero." << endl;
    cout << "FINISH" << endl;
}

int main()
{
    while(cin >> n >> m)
        work();
    return 0;
}