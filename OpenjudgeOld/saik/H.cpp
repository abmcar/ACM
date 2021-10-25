#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 10;
int n, m, fa[maxn];
long long ans;
struct da
{
    int x, y, id;
    long long v;
} q[maxn];
bool cmp(da aa, da bb) { return aa.v < bb.v; }
int getf(int x)
{
    if (fa[x] == x)
        return x;
    fa[x] = getf(fa[x]);
    return fa[x];
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
        scanf("%d%d%lld", &q[i].x, &q[i].y, &q[i].v), q[i].id = i;
    int k;
    scanf("%d", &k);
    fa[getf(q[k].x)] = getf(q[k].y);
    ans += q[k].v;
    sort(q + 1, q + m + 1, cmp);
    for (int i = 1; i <= m; i++)
        if (q[i].id != k)
        {
            if (getf(q[i].x) == getf(q[i].y))
                continue;
            fa[getf(q[i].x)] = getf(q[i].y);
            ans += q[i].v;
        }
    printf("%lld\n", ans);
    return 0;
}