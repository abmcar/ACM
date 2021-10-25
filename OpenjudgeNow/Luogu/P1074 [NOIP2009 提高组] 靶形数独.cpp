#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int used1[10][10];
int used2[10][10];
int used3[4][4][10];
int bd[10][10];
bool isend;
vector<int> qx, qy;
int ans;
const int score[10][10] =
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 6, 6, 6, 6, 6, 6, 6, 6, 6},
     {0, 6, 7, 7, 7, 7, 7, 7, 7, 6},
     {0, 6, 7, 8, 8, 8, 8, 8, 7, 6},
     {0, 6, 7, 8, 9, 9, 9, 8, 7, 6},
     {0, 6, 7, 8, 9, 10, 9, 8, 7, 6},
     {0, 6, 7, 8, 9, 9, 9, 8, 7, 6},
     {0, 6, 7, 8, 8, 8, 8, 8, 7, 6},
     {0, 6, 7, 7, 7, 7, 7, 7, 7, 6},
     {0, 6, 6, 6, 6, 6, 6, 6, 6, 6}};

map<int, int> Mx;
map<int, int> My;
struct Node
{
    int x, y;
    bool const operator<(Node b) const
    {
        if(Mx[x] == Mx[b.x])
            return My[y] < My[b.y];
        return Mx[x] < Mx[b.x];
    }
};

inline void clear()
{
    memset(used1, false, sizeof(used1));
    memset(used2, false, sizeof(used2));
    memset(used3, false, sizeof(used3));
    isend = false;
    qx.clear();
    qy.clear();
}

inline void get()
{
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
        {
            if (i == 1 && j == 1)
                continue;
            char temp;
            cin >> temp;
            if (temp != '0')
            {
                bd[i][j] = temp - '0';
                used1[i][bd[i][j]] = true;
                used2[j][bd[i][j]] = true;
                used3[(2 + i) / 3][(2 + j) / 3][bd[i][j]] = true;
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
    if (pos == qx.size())
    {
        int nowscore = 0;
        for (int i = 1; i <= 9; i++)
            for (int j = 1; j <= 9; j++)
                nowscore += bd[i][j] * score[i][j];
        ans = max(ans, nowscore);
        return;
    }
    // if(isend)
    //     return;
    int nowx = qx[pos];
    int nowy = qy[pos];
    int nowused[10];
    memset(nowused, false, sizeof(nowused));
    for (int i = 1; i <= 9; i++)
    {
        if (used1[nowx][i] || used2[nowy][i] || used3[(2 + nowx) / 3][(2 + nowy) / 3][i])
            nowused[i] = true;
        if (!nowused[i])
        {
            bd[nowx][nowy] = i;
            used1[nowx][i] = true;
            used2[nowy][i] = true;
            used3[(2 + nowx) / 3][(2 + nowy) / 3][i] = true;
            dfs(pos + 1);
            used1[nowx][i] = false;
            used2[nowy][i] = false;
            used3[(2 + nowx) / 3][(2 + nowy) / 3][i] = false;
        }
    }
}

bool fir;

void work()
{
    // cout << "pass #1" << endl;
    get();
    // cout << "pass #2" << endl;
    // cout << "pass #3" << endl;
    vector<Node> V;
    for(int i = 0; i < qx.size(); i++)
    {
        V.push_back({qx[i],qy[i]});
        Mx[qx[i]]++;
        My[qy[i]]++;
    }
    qx.clear();
    qy.clear();
    sort(V.begin(),V.end());
    for(int i = 0; i < V.size(); i++)
    {
        qx.push_back(V[i].x);
        qy.push_back(V[i].y);
    }
    dfs(0);
    if (ans == 0)
    {
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;
}

int main()
{
    // std::ios::sync_with_stdio(false);
    char tc;
    cin >> tc;
    // clear();
    if (tc == '0')
    {
        qx.push_back(1);
        qy.push_back(1);
    }
    else
    {
        bd[1][1] = tc - '0';
        used1[1][bd[1][1]] = true;
        used2[1][bd[1][1]] = true;
        used3[1][1][bd[1][1]] = true;
    }
    work();
    return 0;
}