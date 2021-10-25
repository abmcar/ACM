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
#define endl "\n"

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;

int nx[5] = {0,1,0,0,-1};
int ny[5] = {0,0,-1,1,0};
char bd[55][55];
int endX = 30, endY = 50;
bool vised[55][55];

int main()
{
    Buff;
    // for(int i = 1; i <= 30; i++)
    // for(int j = 1; j <= 50; j++)
    //     cin >> bd[i][j];
    // queue<int> qx,qy;
    // queue<string> qa;
    // qx.push(1);
    // qy.push(1);
    // qa.push("");
    // vised[1][1] = true;
    // while (!qx.empty())
    // {
    //     int nowx = qx.front();
    //     int nowy = qy.front();
    //     string nowans = qa.front();
    //     qx.pop();
    //     qy.pop();
    //     qa.pop();
    //     cout << nowx << " " << nowy << endl;
    //     if(nowx == endX && nowy == endY)
    //     {
    //         cout << nowans << endl;
    //         for(int i = 0; i < nowans.size(); i++)
    //         {
    //             if(nowans[i] == '1')
    //                 cout << 'D';
    //             if(nowans[i] == '2')
    //                 cout << 'L';
    //             if(nowans[i] == '3')
    //                 cout << 'R';
    //             if(nowans[i] == '4')
    //                 cout << 'U';
    //         }
    //     }
    //     for(int i = 1; i <= 4; i++)
    //     {
    //         int nextx = nowx + nx[i];
    //         int nexty = nowy + ny[i];
    //         char temp = i+'0';
    //         string nextans = nowans + temp;
    //         if(nextx < 1 || nexty < 1 || nextx > 30 || nexty > 50)
    //             continue;
    //         if(vised[nextx][nexty])
    //             continue;
    //         if(bd[nextx][nexty] == '1')
    //             continue;
    //         vised[nextx][nexty] = true;
    //         qx.push(nextx);
    //         qy.push(nexty);
    //         qa.push(nextans);
    //     }
    // }
    cout << "DDDDRRURRRRRRDRRRRDDDLDDRDDDDDDDDDDDDRDDRRRURRUURRDDDDRDRRRRRRDRRURRDDDRRRRUURUUUUUUULULLUUUURRRRUULLLUUUULLUUULUURRURRURURRRDDRRRRRDDRRDDLLLDDRRDDRDDLDDDLLDDLLLDLDDDLDDRRRRRRRRRDDDDDDRR";
    return 0;
}