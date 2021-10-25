#include<iostream>
#include<queue>
#define Maxn (int)233
using namespace std;

int nx[8] = {-2,-1,1,2,2,1,-1,-2}; 
int ny[8] = {1,2,2,1,-1,-2,-2,-1};
char c1,c2,c3,c4;
int strx,stry;
int endx,endy;
bool vised[Maxn][Maxn];

void clear()
{
    for(int i = 1; i <= Maxn; i++)
    for(int j = 1; j <= Maxn; j++)
        vised[i][j] = 0;
}

void work()
{
    clear();
    strx = c1;
    stry = c2;
    endx = c3;
    endy = c4;
    queue<int> qx,qy,qt;
    qx.push(strx);
    qy.push(stry);
    qt.push(0);
    while(!qx.empty())
    {
        int nowx = qx.front();
        int nowy = qy.front();
        int nowt = qt.front();
        // cout << nowx << " " << nowy << endl;
        qx.pop();
        qy.pop();
        qt.pop();
        if(nowx == endx && nowy == endy)
        {
            //To get from xx to yy takes n knight moves.
            cout << "To get from " << c1 << c2 << " to " << c3 << c4 << " takes " << nowt << " knight moves." << endl;
            return;
        }
        for(int i = 0; i < 8; i++)
        {
            int nextx = nowx + nx[i];
            int nexty = nowy + ny[i];
            int nextt = nowt + 1;
            if(nextx < 'a' || nexty < '1' || nextx > 'h' || nexty > '8')
                continue;
            if(vised[nextx][nexty] == true)
                continue;
            vised[nextx][nexty] = true;
            qx.push(nextx);
            qy.push(nexty);
            qt.push(nextt);
        }
    }
}

int main()
{
    while(cin >> c1 >> c2 >> c3 >> c4)
        work();
    return 0;
}