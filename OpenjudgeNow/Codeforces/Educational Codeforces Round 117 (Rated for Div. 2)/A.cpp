#include "bits/stdc++.h"

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t;

/* 
d(a,c)=X+Y
d(b,c)=(X-x)+(Y-y)

d(a,b)=x+y

 = x + y
2x+2*y= 4*X+4*Y

 */

int getDis(int x1, int x2, int y1, int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}

void work()
{
    ll x, y;
    cin >> x >> y;
    int disAB = getDis(x,0,y,0);
    for (int i = 0; i <= 111; i++)
    for (int j = 0; j <= 111; j++)
    {
        if (getDis(i,0,j,0)*2 == disAB)
        if (getDis(i,x,j,y)*2 == disAB)
        {
            cout << i << " " << j << endl;
            return;
        }
    }
    cout << "-1 -1" << endl;
}

signed main()
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