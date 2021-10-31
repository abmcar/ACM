#include <bits/stdc++.h>
using namespace std;
int n, m, t;
const int N = 100005;
#define lowbit(x) (x & (-x))
int w[N], ar[N], br[N], ans[N], c[N], le, len, cn[N], block[N], sq;
struct node
{
    int id, l, r;
} q[N];
int cmp(node q, node w)
{
    if (block[q.l] == block[w.l])
        return q.r < w.r;
    return block[q.l] < block[w.l];
}
int getsum(int i)
{
    int res = 0;
    while (i > 0)
    {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

void updata(int i, int k)
{
    while (i <= n)
    {
        c[i] += k;
        i += lowbit(i);
    }
}

inline void add(int x)
{
    cn[x]++;
    updata(x, 1);
}

inline void del(int x)
{
    cn[x]--;
    updata(x, -1);
}
bool check(int mid, int cc)
{
    if (cc - getsum(mid - 1) >= mid)
        return true;
    return false;
}
int main()
{
    while (~scanf("%d %d", &n, &m))
    {
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; i++)
            scanf("%d", &w[i]);
        int t = sqrt(n);
        for (int i = 0; i < n; i++)
            block[i] = i / t;
        for (int i = 0; i < m; i++)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            q[i] = {i, l, r};
        }
        sort(q, q + m, cmp);
        int i, j, k, res;
        for (k = 0, i = 0, j = 1, res = 0; k < m; k++)
        {
            int id = q[k].id, l = q[k].l, r = q[k].r;
            while (i < r)
                add(w[++i]);
            while (i > r)
                del(w[i--]);
            while (j < l)
                del(w[j++]);
            while (j > l)
                add(w[--j]);
            int cc = r - l + 1;
            int ll = 0, rr = n;
            while (ll <= rr)
            {
                int mid = (ll + rr) >> 1;
                if (check(mid, cc))
                {
                    ll = mid + 1;
                }
                else
                {
                    rr = mid - 1;
                }
            }
            ans[id] = rr;
        }
        for (int k = 0; k < m; k++)
            printf("%d\n", ans[k]);
    }
    return 0;
}