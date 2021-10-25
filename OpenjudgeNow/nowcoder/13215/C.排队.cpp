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

const int Maxn = 300010;
const ll Mod = 1e9 + 7;

int n;
// ll t[Maxn], h[Maxn], d[Maxn];
ll preM[Maxn], aftM[Maxn];

struct Student
{
    ll t, h, d;
    bool const operator<(const Student b) const
    {
        return t < b.t;
    }
    void get()
    {
        cin >> t >> h >> d;
    }
} stu[Maxn];

int main()
{
    Buff;
    cin >> n;
    for (int i = 1; i <= n; i++)
        stu[i].get();
    sort(stu + 1, stu + 1 + n);
    for (int i = 1; i <= n; i++)
        preM[i] = max(preM[i-1], stu[i].h);
    for (int i = n; i >= 1; i--)
        aftM[i] = max(aftM[i+1], stu[i].h);
    for (int i = 1; i <= n; i++)
    {
        int l = max((ll)1, stu[i].t - stu[i].d);
        int r = min((ll)n, stu[i].t + stu[i].d);
        int ans = 0;
        ll nowL = 0;
        ll nowR = 0;
        for (int j = i-1; j >= l; j--)
        {
            if (nowL >= preM[j])
                break;
            if (stu[i].t-stu[i].d <= stu[j].t)
            {
                if (stu[j].h > nowL)
                {
                    ans++;
                    nowL = max(nowL, stu[j].h);
                    // l = j;
                    // break;
                }
            }else
                break;
        }
        for (int j = i+1; j <= r; j++)
        {
            if (nowR >= aftM[j])
                break;
            if (stu[i].t + stu[i].d >= stu[j].t)
            {
                if (stu[j].h > nowR)
                {
                    ans++;
                    nowR = max(nowR, stu[j].h);
                    // r = j;
                    // break;
                }
            }else
                break;
        }
        cout << ans << " ";
    }
    return 0;
}