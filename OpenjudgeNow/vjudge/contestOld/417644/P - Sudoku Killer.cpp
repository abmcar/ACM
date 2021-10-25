#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<cstdio>
#include<cstring>

using namespace std;

int used1[10][10];
int used2[10][10];
int used3[4][4][10];
int bd[10][10];
bool isend;
vector<int> qx,qy;

inline void clear()
{
    memset(used1,false,sizeof(used1));
    memset(used2,false,sizeof(used2));
    memset(used3,false,sizeof(used3));
    isend = false;
    qx.clear();
    qy.clear();
}

inline void get()
{
    for(int i = 1; i <= 9; i++)
    for(int j = 1; j <= 9; j++)
    {
        if(i == 1 && j == 1)
            continue;
        char temp;
        cin >> temp;
        if(temp != '?')
        {
            bd[i][j] = temp-'0';
            used1[i][bd[i][j]] = true;
            used2[j][bd[i][j]] = true;
            used3[(2+i)/3][(2+j)/3][bd[i][j]] = true;
        }
        else
        {
            qx.push_back(i);
            qy.push_back(j);
        }
    }
}

void dfs(int pos)
{
    if(pos == qx.size())
    {
        isend = 1;
        return;
    }
    if(isend)
        return;
    int nowx = qx[pos];
    int nowy = qy[pos];
    int nowused[10];
    memset(nowused,false,sizeof(nowused));
    for(int i = 1; i <= 9; i++)
    {
        if(used1[nowx][i] || used2[nowy][i] || used3[(2+nowx)/3][(2+nowy)/3][i])
            nowused[i] = true;
        if(isend)
            return;
        if(!nowused[i])
        {
            if(isend)
                return;
            bd[nowx][nowy] = i;
            used1[nowx][i] = true;
            used2[nowy][i] = true;
            used3[(2+nowx)/3][(2+nowy)/3][i] = true;
            dfs(pos+1);
            used1[nowx][i] = false;
            used2[nowy][i] = false;
            used3[(2+nowx)/3][(2+nowy)/3][i] = false;
        }
    }
}

bool fir;

void work()
{
    get();
    if(fir == 0)
        fir = 1;
    else
        printf("\n");
    dfs(0);
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= 8; j++)
            printf("%d ",bd[i][j]);
        printf("%d",bd[i][9]);
        printf("\n");
    }
}

int main()
{
    // std::ios::sync_with_stdio(false);
    char tc;
    while(cin >> tc)
    {
        clear();
        if(tc == '?')
        {
            qx.push_back(1);
            qy.push_back(1);
        }else
        {
            bd[1][1] = tc-'0';
            used1[1][bd[1][1]] = true;
            used2[1][bd[1][1]] = true;
            used3[1][1][bd[1][1]] = true;
        }
        work();
    }
    return 0;    
}
