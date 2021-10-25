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

const int Maxn = 233;
const ll Mod = 1e9+7;

int nx[5] = {0,1,0,-1,0};
int ny[5] = {0,0,1,0,-1};
char bd[Maxn][Maxn];
bool used[Maxn][Maxn];
int n, m;

bool check(int strX, int strY)
{
    queue<int> qX,qY;
    vector<int> endX,endY;
    char tempChar = bd[strX][strY];
    bool tempUsed[Maxn][Maxn];
    bool fir = false;
    used[strX][strY] = true;
    for (int i = 1; i <= 4; i++)
    {
        int nextX = strX + nx[i];
        int nextY = strY + ny[i];
        if(nextX > n || nextY > m || nextX < 1 || nextY < 1)
            continue;
        if(bd[nextX][nextY] != tempChar)
            continue;
        endX.push_back(nextX);
        endY.push_back(nextY);
    }
    if(endX.size() < 2)
        return false;
    for (int k = 0; k < endX.size(); k++)
    {
        while (!qX.empty())
            qX.pop();
        memset(tempUsed,false,sizeof(tempUsed));
        qX.push(endX[k]);
        qY.push(endY[k]);
        tempUsed[strX][strY] = true;
        tempUsed[endX[k]][endY[k]] = true;
        while (!qX.empty())
        {
            int nowX = qX.front();
            int nowY = qY.front();
            qX.pop();
            qY.pop();
            for (int i = 0; i < endX.size(); i++)
            if(k == i)
                continue;
            else
            if(endX[i] == nowX && endY[i] == nowY)
                return true;
            // cout << k << " " <<  nowX << " " << nowY << " " << tempChar << endl;
            for (int i = 1; i <= 4; i++)
            {
                int nextX = nowX + nx[i];
                int nextY = nowY + ny[i];
                if(nextX > n || nextY > m || nextX < 1 || nextY < 1)
                    continue;
                if(bd[nextX][nextY] != tempChar)
                    continue;
                if(tempUsed[nextX][nextY])
                    continue;
                tempUsed[nextX][nextY] = true;
                used[nextX][nextY] = true;
                qX.push(nextX);
                qY.push(nextY);
            }
        }
    }
    return false;
}

int main()
{
    Buff;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        cin >> bd[i][j];
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        if(!used[i][j])
            if(check(i,j))
            {
                cout << "Yes" << endl;
                return 0;
            }
    cout << "No" << endl;
    return 0;
}