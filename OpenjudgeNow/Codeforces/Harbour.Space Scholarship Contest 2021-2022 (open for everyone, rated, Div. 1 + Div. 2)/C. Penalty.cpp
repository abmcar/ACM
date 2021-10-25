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
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t;
string oriS;

int dfs(string nowS)
{
    int nowAns = 10;
    if (nowS.find("?") == string::npos)
    {
        int nowA, nowB;
        nowA = nowB = 0;
        for (int i = 0; i < 10; i++)
        {
            if (nowA > nowB)
            {
                int nowD = nowA - nowB;
                int nowC = 0;
                for (int j = i; j < 10; j++)
                    if (j % 2)
                        nowC++;
                if (nowD > nowC)
                    return i;
            }else
            {
                int nowD = nowB - nowA;
                int nowC = 0;
                for (int j = i; j < 10; j++)
                    if (j % 2 == 0)
                        nowC++;
                if (nowD > nowC)
                    return i;
            }
            if (nowS[i] == '1')
            {
                if (i % 2 == 0)
                    nowA++;
                else
                    nowB++;
            }
        }
    }
    for (int i = 0; i < 10; i++)
        if (nowS[i] == '?')
        {
            string tempS = nowS;
            tempS[i] = '1';
            nowAns = min(nowAns,dfs(tempS));
            tempS[i] = '0';
            nowAns = min(nowAns,dfs(tempS));
            break;
        }
    return nowAns;
}

void work()
{
    cin >> oriS;
    cout << dfs(oriS) << endl;
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}