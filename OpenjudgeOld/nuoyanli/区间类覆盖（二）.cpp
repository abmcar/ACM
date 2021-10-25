#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int t, n;
double w, h;
double nowx = 0;
int ans;
bool ok[233333];
struct point
{
    double x, r;
};
point p[23333];

bool cmp(point a, point b)
{
    if (a.x == b.x)
        return a.r > b.r;
    return a.x < b.x;
}

double instance(int pos, double nextx)
{
    return sqrt(h * h / 4 + (p[pos].x - nextx) * (p[pos].x - nextx));
}

void work()
{
    nowx = 0;
    ans = 0;
    cin >> n >> w >> h;
    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].r;
    sort(p + 1, p + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
        if (instance(i, nowx) <= p[i].r)
        {
            if(i>=2 && p[i].x == p[i-1].x)
                continue;
            ans++;
            for (int j = nowx; j <= w; j++)
                if (instance(i, j) <= p[i].r)
                    nowx = j, ok[j] = 1;
        }
    bool tempok = 1;
    for (int i = 0; i <= w; i++)
        if (!ok[i])
        {
            tempok = 0;
            break;
        }
    if (tempok)
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