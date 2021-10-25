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
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

int t, n;
char bd[Maxn][Maxn];
bool firPos1;
int posX1, posX2, posX3, posX4;
int posY1, posY2, posY3, posY4;
int dis;

void work()
{
    firPos1 = false;
    cin >> n;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
        cin >> bd[i][j];
        if (bd[i][j] == '*')
        {
            if (firPos1 == false)
            {
                posX1 = i;
                posY1 = j;
                firPos1 = true;
            }else
            {
                posX2 = i;
                posY2 = j;
            }
        }
    }
    if (posX2 == posX1)
    {
        dis = 1;
        if (posX1 - dis >= 1)
        {
            posX3 = posX1 - dis;
            posX4 = posX1 - dis;
            posY3 = posY1;
            posY4 = posY2;
        }else
        {
            posX3 = posX1 + dis;
            posX4 = posX1 + dis;
            posY3 = posY1;
            posY4 = posY2;
        }
    }else
    if (posY2 == posY1)
    {
        dis = 1;
        if (posY1 - dis >= 1)
        {
            posY3 = posY1 - dis;
            posY4 = posY1 - dis;
            posX3 = posX1;
            posX4 = posX2;
        }else
        {
            posY3 = posY1 + dis;
            posY4 = posY1 + dis;
            posX3 = posX1;
            posX4 = posX2;
        }
    }else
    {
        int minx = min(posX1,posX2);
        int maxx = max(posX1,posX2);
        int miny = min(posY1,posY2);
        int maxy = max(posY1,posY2);
        posX1 = minx;
        posY1 = miny;
        posX2 = minx;
        posY2 = maxy;
        posX3 = maxx;
        posY3 = miny;
        posX4 = maxx;
        posY4 = maxy;
    }
    bd[posX1][posY1] = '*';
    bd[posX2][posY2] = '*';
    bd[posX3][posY3] = '*';
    bd[posX4][posY4] = '*';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << bd[i][j];
        cout << endl;
    }
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}