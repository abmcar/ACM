#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;
inline int read()
{
    int s = 0, w = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            w = -w;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        s = s * 10 + c - '0';
        c = getchar();
    }
    return s * w;
}
int n, m;
int e, beg[maxn], nex[maxn], to[maxn], temp[maxn], num[maxn];
int ans[maxn << 2], tag[maxn << 2];
int son[maxn], id[maxn], father[maxn], cnt, deep[maxn], sons[maxn], top[maxn];
int res = 0;
//id[]表示时间戳（即在链当中的编号）
//deep[]表示该节点的深度
//sons[]表示该节点子树的大小【方便修改子树数值时调用线段树】
//top[]表示重量开端
#define mid ((l + r) >> 1)
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define len (r - l + 1)
inline void add(int x, int y) //链式前向星
{
    to[++e] = y;
    nex[e] = beg[x];
    beg[x] = e;
}
//-----------------------以下为线段树-----------------------------------
inline void build(int rt, int l, int r)
{
    if (l == r)
    {
        ans[rt] = num[l];
        return;
    }
    build(lson);
    build(rson);
    ans[rt] = (ans[rt << 1] + ans[rt << 1 | 1]);
}
inline void pushdown(int rt, int lenn)
{
    tag[rt << 1] += tag[rt];
    tag[rt << 1 | 1] += tag[rt];
    ans[rt << 1] += tag[rt] * (lenn - (lenn >> 1));
    ans[rt << 1 | 1] += tag[rt] * (lenn >> 1);
    tag[rt] = 0;
}
inline void query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R)
    {
        res += ans[rt];
        return;
    }
    else
    {
        if (tag[rt])
            pushdown(rt, len);
        if (L <= mid)
            query(lson, L, R);
        if (R > mid)
            query(rson, L, R);
    }
}

inline void updata(int rt, int l, int r, int L, int R, int k)
{
    if (L <= l && r <= R)
    {
        tag[rt] += k;
        ans[rt] += k * len;
    }
    else
    {
        if (tag[rt])
            pushdown(rt, len);
        if (L <= mid)
            updata(lson, L, R, k);
        if (R > mid)
            updata(rson, L, R, k);
        ans[rt] = (ans[rt << 1] + ans[rt << 1 | 1]);
    }
}
//-----------------------以上为线段树-----------------------------------
inline void dfs1(int x, int f, int deep1)
{
    deep[x] = deep1;
    father[x] = f;
    sons[x] = 1;
    int maxson = -1;
    for (register int i = beg[x]; i; i = nex[i])
    {
        int y = to[i];
        if (y == f)
            continue;
        dfs1(y, x, deep1 + 1);
        sons[x] += sons[y];
        if (sons[y] > maxson)
            son[x] = y, maxson = sons[y];
    }
}
inline void dfs2(int x, int topf)
{
    id[x] = ++cnt;
    num[cnt] = temp[x];
    top[x] = topf;
    if (!son[x])
        return;
    dfs2(son[x], topf);
    for (register int i = beg[x]; i; i = nex[i])
    {
        int y = to[i];
        if (y == father[x] || y == son[x])
            continue;
        dfs2(y, y);
    }
}
inline int qRange(int x, int y)
{
    int ans = 0;
    while (top[x] != top[y])
    {
        if (deep[top[x]] < deep[top[y]])
            swap(x, y);
        res = 0;
        query(1, 1, n, id[top[x]], id[x]);
        ans += res;
        x = father[top[x]];
    }
    if (deep[x] > deep[y])
        swap(x, y);
    res = 0;
    query(1, 1, n, id[x], id[y]);
    ans += res;
    return ans;
}
signed main()
{
    n = read();
    m = read();
    for (int i = 1; i <= n; i++)
        temp[i] = read();
    for (int i = 1; i < n; i++)
    {
        int a, b;
        a = read();
        b = read();
        add(a, b);
        add(b, a);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    build(1, 1, n);
    while (m--)
    {
        int k, x, y;
        k = read();
        if (k == 1)
        {
            x = read();
            y = read();
            // update(1, 1, n, id[x], y);
            updata(1, 1, n, id[x], id[x], y);
        }
        if (k == 2)
        {
            x = read();
            y = read();
            updata(1, 1, n, id[x], id[x] + sons[x] - 1, y);
        }
        if (k == 3)
        {
            x = read();
            printf("%lld\n", qRange(1, x));
        }
    }
    return 0;
}