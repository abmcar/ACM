#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const int INF = 0x3f3f3f3f;
const int maxl = 2e6 + 10;
long long x, y, t;
long long mod = 1e9 + 7;
ll n, m;
ll ar[maxl], ans[maxl], k, lg[maxl], num[maxl], nn[maxl];
struct node
{
    ll l, r, k, id, cc;
} stu[maxl];
bool cmp(node aa, node bb)
{
    if (aa.l / k == bb.l / k)
    {
        return aa.r < bb.r;
    }
    return aa.l / k < bb.l / k;
}
void add(ll x)
{
    nn[num[x]]--;
    num[x]++;
    nn[num[x]]++;
}
void dec(ll x)
{
    nn[num[x]]--;
    num[x]--;
    nn[num[x]]++;
}
void solve()
{
    ll pl = stu[1].l;
    ll pr = stu[1].r;
    ll i;
    for (i = pl; i <= pr; i++)
    {
        add(ar[i]);
    }
    ll cc;
    ans[stu[1].id] = nn[stu[1].k];
    for (i = 2; i <= m; i++)
    {
        cc++;
        do
        {
            if (pl <= stu[i].l)
            {
                cc++;
                break;
            }
            pl--;
            add(ar[pl]);
        } while (pl > stu[i].l);
        do
        {
            if (pr >= stu[i].r)
            {
                break;
            }
            pr++;
            cc++;
            add(ar[pr]);
        } while (pr < stu[i].r);
        do
        {
            if (pl >= stu[i].l)
            {
                break;
            }
            dec(ar[pl]);
            pl++;
            cc++;
        } while (pl < stu[i].l);
        do
        {
            if (pr <= stu[i].r)
            {
                break;
            }
            dec(ar[pr]);
            pr--;
            cc++;
        } while (pr > stu[i].r);
        ans[stu[i].id] = nn[stu[i].k];
    }
}
int main()
{
    scanf("%lld %lld", &n, &m);
    ll i, j;
    for (i = 1; i <= n; i++)
    {
        scanf("%lld", &ar[i]);
    }
    for (i = 1; i <= m; i++)
    {
        scanf("%lld %lld %lld", &stu[i].l, &stu[i].r, &stu[i].k);
        stu[i].id = i;
    }
    k = sqrt(m);
    for (i = 1; i <= n; i++)
    {
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    }

    ll cc;
    sort(stu + 1, stu + m + 1, cmp);
    solve();
    for (i = 1; i <= m; i++)
    {
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    }
    for (i = 1; i <= m; i++)
    {
        cc = ans[i];
        printf("%lld\n", cc);
    }

    return 0;
}
