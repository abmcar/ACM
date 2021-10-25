#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

const int Maxn = 21;
int n,m;
char bd[Maxn][Maxn];
int strx,stry,endx,endy;
int strstatus[Maxn][Maxn];
bool vised[Maxn][Maxn];
int nx[4] = {0,1,0,-1};
int ny[4] = {1,0,-1,0};
int nadd[Maxn][Maxn];

inline void get()
{

    cin >> m;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    {
        cin >> bd[i][j];
        if(bd[i][j] == 'S')
        {
            strx = i;
            stry = j;
        }
        if(bd[i][j] == 'T')
        {
            endx = i;
            endy = j;
        }
        if(bd[i][j] == '|')
            strstatus[i][j] = 1;
        if(bd[i][j] == '-')
            strstatus[i][j] = 2;
    }
}


inline void work()
{
    get();
    for(int i = 1; i <= Maxn; i++)
    for(int j = 1; j <= Maxn; j++)
        vised[i][j] = 0,nadd[i][j] = 0;
    queue<int> qx,qy,qt;
    qx.push(strx);
    qy.push(stry);
    qt.push(0);
    // used[strx][stry] = 0;
    vised[strx][stry] = true;
    while(!qx.empty())
    {
        int nowx = qx.front();
        int nowy = qy.front();
        int nowt = qt.front();
        qx.pop();
        qy.pop();
        qt.pop();
        cout << nowx << " " << nowy << " " << nowt << endl;
        for(int i = 0; i < 4; i++)
        {
            int nextx = nowx+nx[i];
            int nexty = nowy+ny[i];
            int nextt = nowt+1;
            if(vised[nextx][nexty] == true)
                continue;
            if(bd[nextx][nexty] == '*')
                continue;
            if(nextx < 1 || nexty < 1 || nextx > n || nexty > m)
                continue;
            if(bd[nextx][nexty] == 'T')
            {
                cout << nextt << endl;
                return;
            }
            if(bd[nextx][nexty] == '.')
            {
                if(nadd[nextx][nexty] > 2)
                    continue;
                qx.push(nextx);
                qy.push(nexty);
                qt.push(nextt);
                nadd[nextx][nexty]++;
                continue;
            }
            if(bd[nextx][nexty] == '|' || bd[nextx][nexty] == '-')
            {
                if(nowt % 2 == 1)
                {
                    if(bd[nextx][nexty] == '|')
                        strstatus[nextx][nexty] = 2; 
                    else
                        strstatus[nextx][nexty] = 1;
                }else
                {
                    if(bd[nextx][nexty] == '-')
                        strstatus[nextx][nexty] = 2; 
                    else
                        strstatus[nextx][nexty] = 1;
                }
                
                if(nx[i] == 0)
                {
                    if(strstatus[nextx][nexty] == 1)
                    {
                        if(nadd[nowx][nowy] > 2)
                            continue;
                        qx.push(nowx);
                        qy.push(nowy);
                        qt.push(nextt);
                        nadd[nowx][nowy]++;
                        continue;
                    }
                    nexty += ny[i];
                    if(vised[nextx][nexty] == true)
                        continue;
                    if(bd[nextx][nexty] == '*')
                        continue;
                    if(nextx < 1 || nexty < 1 || nextx > n || nexty > m)
                        continue;
                    if(bd[nextx][nexty] == 'T')
                    {
                        cout << nextt << endl;
                        return;
                    }
                    if(nadd[nextx][nexty] > 2)
                        continue;
                    vised[nextx][nexty] = true;
                    qx.push(nextx);
                    qy.push(nexty);
                    qt.push(nextt);
                    nadd[nextx][nexty]++;
                }else
                {
                    if(strstatus[nextx][nexty] == 2)
                    {
                        if(nadd[nowx][nowy] > 2)
                            continue;
                        qx.push(nowx);
                        qy.push(nowy);
                        qt.push(nextt);
                        nadd[nowx][nowy]++;
                        continue;
                    }
                    nextx += nx[i];
                    if(vised[nextx][nexty] == true)
                        continue;
                    if(bd[nextx][nexty] == '*')
                        continue;
                    if(nextx < 1 || nexty < 1 || nextx > n || nexty > m)
                        continue;
                    if(bd[nextx][nexty] == 'T')
                    {
                        cout << nextt << endl;
                        return;
                    }
                    if(nadd[nextx][nexty] > 2)
                        continue;
                    vised[nextx][nexty] = true;
                    qx.push(nextx);
                    qy.push(nexty);
                    qt.push(nextt);
                    nadd[nextx][nexty]++;
                }
            }
        }
    }
}

int main()
{
    while(cin >> n)
        work();
    return 0;
}