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
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 90;
const ll Mod = 1e9+7;

int bd[Maxn][Maxn];
bool used1[Maxn][20], used2[Maxn][20], used3[Maxn][Maxn][20];
vector<int> qX,qY;
bool ok = false;
bool fir;

void dfs(int nowPos)
{
    if(nowPos == qX.size())
    {
        ok = true;
        return;
    }
    int nowX = qX[nowPos];
    int nowY = qY[nowPos];
    map<int,bool> M;
    for (int i = 1; i <= 9; i++)
        if(used1[nowX][i] || used2[nowY][i] || used3[(nowX+2)/3][(nowY+2)/3][i])
            M[i] = true;
    for (int i = 1; i <= 9; i++)
        if(!M[i])
        {
            bd[nowX][nowY] = i;
            used1[nowX][i] = true;
            used2[nowY][i] = true;
            used3[(nowX+2)/3][(nowY+2)/3][i] = true;
            dfs(nowPos+1);
            if(ok)
                return;
            used1[nowX][i] = false;
            used2[nowY][i] = false;
            used3[(nowX+2)/3][(nowY+2)/3][i] = false;
        }
}

void work()
{
    char tempChar;
    for (int i = 1; i <= 9; i++)
    for (int j = 1; j <= 9; j++)
    {
        if (i == 1 && j == 1)
            continue;
        cin >> tempChar;
        if (tempChar == '?')
        {
            qX.push_back(i);
            qY.push_back(j);
        }else
        {
            int tempnum = tempChar - '0';
            used1[i][tempnum] = true;
            used2[j][tempnum] = true;
            used3[(i+2)/3][(j+2)/3][tempnum] = true;
            bd[i][j] = tempnum;
        }
    }
    dfs(0);
    if(!fir)
    {
        fir = true;
    }else
        cout << endl;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j < 9; j++)
            cout << bd[i][j] << " ";
        cout << bd[i][9];
        cout << endl;
    }
}

int main()
{
    Buff;
    char temp;
    while (cin >> temp)
    {
        memset(used1,false,sizeof(used1));
        memset(used2,false,sizeof(used2));
        memset(used3,false,sizeof(used3));
        memset(bd,0,sizeof(bd));
        qX.clear();
        qY.clear();
        ok = false;
        if (temp == '?')
        {
            qX.push_back(1);
            qY.push_back(1);
        }else
        {
            int tempnum = temp - '0';
            used1[1][tempnum] = true;
            used2[1][tempnum] = true;
            used3[1][1][tempnum] = true;
            bd[1][1] = tempnum;
        }
        work();
    }
    return 0;
}