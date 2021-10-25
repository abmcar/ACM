#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>


using namespace std;

int n,m,q;
struct Node
{
    int x,y;
    int num;
    int deltax = 0;
    int deltay = 0;
};
int bd[123][123];
vector<Node> node;
stack<int> dt,dx;

int main()
{
    cin >> n >> m;
    cin >> q;
    for(int i = 1; i <= q; i++)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int temp;
            cin >> temp;
            dt.push(1);
            dx.push(temp);
            for(int j = 0; j < node.size(); j++)
            if(node[j].x == temp)
            {
                node[j].y--;
                if(node[j].y == 0)
                    node[j].y = m;
                node[j].deltax++;
            }
        }
        if(type == 2)
        {
            int temp;
            cin >> temp;
            dt.push(2);
            dx.push(temp);
            for(int j = 0; j < node.size(); j++)
            if(node[j].y == temp)
            {
                node[j].x--;
                if(node[j].x == 0)
                    node[j].x = n;
                node[j].deltay++;
            }
        }
        if(type == 3)
        {
            int tx,ty,tn;
            cin >> tx >> ty >> tn;
            Node temp;
            temp.x = tx;
            temp.y = ty;
            temp.num = tn;
            node.push_back(temp);
        }
    }
    while(!dx.empty())
    {
        int nowtype = dt.top();
        int nowd = dx.top();
        dt.pop();
        dx.pop();
        if(nowtype == 1)
        for(int i = 0; i < node.size(); i++)
        {
            if(node[i].x == nowd)
            {
                node[i].y++;
                if(node[i].y == m+1)
                    node[i].y = 1;
            }
        }
        if(nowtype == 2)
        for(int i = 0; i < node.size(); i++)
        {
            if(node[i].y == nowd)
            {
                node[i].x++;
                if(node[i].x == n+1)
                    node[i].x = 1;
            }
        }
    }
    for(int i = 0; i < node.size(); i++)
        bd[node[i].x][node[i].y] = node[i].num;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cout << bd[i][j] << " ";
        cout << endl;
    }
    return 0;
}