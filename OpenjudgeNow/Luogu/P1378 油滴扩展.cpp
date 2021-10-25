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
#include <cstdlib>
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define abs std::abs
#define y1 yy1

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
const double Pi = 3.1415926535897;
int n;
int x,y,x1,y1;
int posX[10], posY[10];
double r[10];
bool used[10];
double finR[10];
double ans = 1e9;

double dis(int pos1, int pos2)
{
    return sqrt((posX[pos1]-posX[pos2])*(posX[pos1]-posX[pos2]) + (posY[pos1]-posY[pos2])*(posY[pos1]-posY[pos2]));
}

void dfs(int deep)
{
    if(deep == n+1)
    {
        double tot = abs(x-x1)*abs(y-y1);
        for(int i = 1; i <= n; i++)
            tot = tot - Pi*r[i]*r[i];
        ans = min(ans,tot);
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(used[i])
            continue;
        double tempr = min((double)min(abs(posY[i]-y),abs(posY[i]-y1)),(double)min(abs(posX[i]-x),abs(posX[i]-x1)));
        for(int j = 1; j <= n; j++)
        {
            if(!used[j])
                continue;
            tempr = min(tempr,max(0.0,dis(i,j)-r[j]));
        }
        r[i] = tempr;
        used[i] = true;
        dfs(deep+1);
        used[i] = false;
    }

}

int main()
{
    Buff;
    cin >> n;
    cin >> x >> y >> x1 >> y1;
    for(int i = 1; i <= n; i++)
        cin >> posX[i] >> posY[i];
    dfs(1);
    cout << (int)(ans+0.5);
    return 0;
}