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

int n;
int bd[Maxn][Maxn];

int main()
{
    Buff;
    cin >> n;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        cin >> bd[i][j];
    int nowx = 1;
    int nowy = 1;
    bool isUp = true;
    for (int i = 1; i <= n*n; i++)
    {
        cout << bd[nowx][nowy] << " ";
        if(isUp)
        {
            if (nowx == 1 || nowy == n)
            {
                if(nowx == 1 && nowy == n && n%2 == 1)
                    nowx++;
                else
                if(nowx == 1 && nowy == n && n%2 == 0)
                    nowy++;
                else
                if(nowx == 1)
                    nowy++;
                else
                    nowx++;
                isUp = false;
            }else
            {
                nowx--;
                nowy++;
            }
        }else
        {
            if (nowx == n || nowy == 1)
            {
                if(nowx == n)
                    nowy++;
                else
                    nowx++;
                isUp = true;
            }else
            {
                nowx++;
                nowy--;
            }
        }
    }
    return 0;
}