#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>

using namespace std;

char bd[666][666];
int costt[666][666];
int used[666][666];
int nextx[5] = {0, 0, 1, 0, -1};
int nexty[5] = {0, 1, 0, -1, 0};
int n,m;
int strx,stry;
int ans = 1e9;

struct pos
{
    int x,y;
};

map<pos,pos> tp;
map<char,vector<pos> > tpnode;

int quickp(int a,int b)
{
    int ans = 1;
    int base = a;
    while(b > 0)
    {
        if(b & 1)
            ans *= base;
        base*base;
        b >>= 1;
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    {
        cin >> bd[i][j];
        if(bd[i][j] == '@')
            strx = i,stry = j;
        if(bd[i][j] >= 'A' && bd[i][j] <= 'Z')
        {
            pos newnode;
            newnode.x = i;
            newnode.y = j;
            tpnode[bd[i][j]].push_back(newnode);
            // if(tpnode[bd[i][j]].size() == 2)
            // {
            //     pos tpa = tpnode[bd[i][j]][0];
            //     pos tpb = tpnode[bd[i][j]][1];
            //     tp[tpa] = tpb;
            //     // tp[tpnode[bd[i][j]][1]] = tpnode[bd[i][j]][0];
            // }
        }
    }
    queue<int> qx,qy,qt;
    qx.push(strx);
    qy.push(stry);
    qt.push(0);
    used[strx][stry] = 1;
    while(!qx.empty())
    {
        int nowx = qx.front();
        int nowy = qy.front();
        int nowt = qt.front();
        // cout << "nowfront:" << nowx << " " << nowy << " " << nowt << " " << bd[nowx][nowy] << endl;
        qx.pop();
        qy.pop();
        qt.pop();
        if(bd[nowx][nowy] == '=')
        {
            ans = min(ans,nowt);
            continue;
        }
        if(bd[nowx][nowy] >= 'A' && bd[nowx][nowy] <= 'Z')
        {
            if(used[nowx][nowy] == 0)
            {
            qx.push(nowx);
            qy.push(nowy);
            qt.push(nowt+2);
            }
            pos thispos;
            thispos.x = nowx;
            thispos.y = nowy;
            // cout << "tpnode:" << nowx << " " << nowy << " " << nowt+1 << endl;
            if(tpnode[bd[nowx][nowy]][0].x == nowx && tpnode[bd[nowx][nowy]][0].y == nowy)
                thispos = tpnode[bd[nowx][nowy]][1];
            else
                thispos = tpnode[bd[nowx][nowy]][0];
            // thispos = tp[thispos];
            // if(used[thispos.x][thispos.y] != 0 && used[thispos.x][thispos.y] < nowt)
            //     continue;
            // if(thispos.x < 1 || thispos.x < 1 || thispos.x > n || thispos.y > m)
            //     continue;
            // used[thispos.x][thispos.y] = nowt;
            nowx = thispos.x;
            nowy = thispos.y;
            // cout << "tp compelete" << endl;
            // cout << "finish :" << nowx << " " << nowy << " " << nowt+1 << endl;
        }
        for(int i = 1; i <= 4; i++)
        {
            int nextxx = nowx + nextx[i];
            int nextyy = nowy + nexty[i];
            int nextt = nowt + 1;
            if(nextxx < 1 || nextyy < 1 || nextxx > n || nextyy > m)
                continue;
            if(used[nextxx][nextyy] <= nextt && used[nextxx][nextyy] != 0)
                continue;
            used[nextxx][nextyy] = nextt;
            if(bd[nextxx][nextyy] == '#')
                continue;
            // cout << "nowfront:" << nowx << " " << nowy << " " << nowt << " " << bd[nowx][nowy] << endl;
            // cout << "nextpos:" << nextxx << " " << nextyy << " " << nextt << endl;
            qx.push(nextxx);
            qy.push(nextyy);
            qt.push(nextt);
        }
    }
    if(ans == 1e9)
        ans = -1;
    cout << ans;
    return 0;
}