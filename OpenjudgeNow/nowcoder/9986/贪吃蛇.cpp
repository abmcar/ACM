#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
int nx[5] = {0,1,0,-1,0};
int ny[5] = {0,0,1,0,-1};
int n,m;
int sX,sY,eX,eY;
char bd[123][123];
bool vised[123][123];

int main()
{
    Buff;
    cin >> n >> m;
    cin >> sX >> sY >> eX >> eY;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        cin >> bd[i][j];
    queue<int> qX,qY,qT;
    qX.push(sX);
    qY.push(sY);
    qT.push(0);
    vised[sX][sY] = true;
    while(!qX.empty())
    {
        int nowx = qX.front();
        int nowy = qY.front();
        int nowt = qT.front();
        qX.pop();
        qY.pop();
        qT.pop();
        // cout << nowx << " " << nowy << "\n";
        if(nowx == eX && nowy == eY)
        {
            cout << nowt*100;
            return 0;
        }
        for(int i = 1; i <= 4; i++)
        {
            int nextx = nowx + nx[i];
            int nexty = nowy + ny[i];
            int nextt = nowt+1;
            if(nextx < 1 || nexty < 1 || nextx > n || nexty > m)
                continue;
            // cout << nextx << " " << nexty << "\n";
            if(bd[nextx][nexty] == '#')
                continue;
            if(vised[nextx][nexty] == true)
                continue;
            vised[nextx][nexty] = true;
            qX.push(nextx);
            qY.push(nexty);
            qT.push(nextt);
        }
    }
    cout << "-1";
    return 0;
}