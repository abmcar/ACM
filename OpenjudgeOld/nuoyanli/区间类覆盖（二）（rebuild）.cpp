#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int t, n;
double w, h;
double nowx = 0;
int ans;
struct point
{
    double x, r;
    double left,right;
    void getl()
    {
        if(r*r-h*h/4 < 0)
            return;
        left = x-sqrt(r*r-h*h/4);
        right = x+sqrt(r*r-h*h/4);
    }
}p[23333];

bool cmp(point a, point b)
{
    if(a.left == b.left)
        return a.right > b.right;
    return a.left < b.left;
}

void work()
{
    nowx = 0;
    ans = 0;
    cin >> n >> w >> h;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].x >> p[i].r;
        p[i].getl();
    }
    sort(p + 1, p + 1 + n, cmp);
    for(int i = 1; i <= n; i++)
    {
        double nextmax = nowx;
        int ti = 1;
        while(p[ti].left <= nowx)
        {
            nextmax = max(nextmax,p[ti].right);
            ti++;
            if(ti > n)
                break;
        }
        if(nowx == nextmax)
            continue;
        ans++;
        nowx = nextmax;
    }
    if(nowx >= w)
        cout << ans << endl;
    else
        cout << "0" << endl;
    return;
}

int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
        work();
    return 0;
}