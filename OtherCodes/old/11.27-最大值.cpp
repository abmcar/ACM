#include <bits/stdc++.h>
#define ll int
using namespace std;

const ll Maxn = 1e6 + 10;

ll n, m, t, cnt;
ll num[Maxn];
struct Node
{
    ll l, r;
    ll val = 0;
} node[Maxn];

ll lSon(ll x)
{
    return x * 2;
}

ll rSon(ll x)
{
    return x * 2 + 1;
}

void pushUp(ll x)
{
    node[x].val = max(node[lSon(x)].val, node[rSon(x)].val);
}

void build(ll nowPos, ll nowL, ll nowR)
{
    node[nowPos].l = nowL;
    node[nowPos].r = nowR;
    if (nowL == nowR)
    {
        node[nowPos].val = num[nowL];
        return;
    }
    ll nowMid = (nowL + nowR) / 2;
    build(lSon(nowPos), nowL, nowMid);
    build(rSon(nowPos), nowMid + 1, nowR);
    pushUp(nowPos);
}

ll query(ll nowPos, ll nowL, ll nowR, ll targetL, ll targetR)
{
    // cout << nowPos << " " << nowL << " " << nowR << " " << targetL << " " << targetR << endl;
    if (nowL >= targetL && nowR <= targetR)
        return node[nowPos].val;
    ll nowMid = (nowL + nowR) / 2;
    ll nowAns = 0;
    if (nowMid >= targetL)
        nowAns = max(nowAns, query(lSon(nowPos), nowL, nowMid, targetL, targetR));
    if (nowMid + 1 <= targetR)
        nowAns = max(nowAns, query(rSon(nowPos), nowMid + 1, nowR, targetL, targetR));
    return nowAns;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    build(1, 1, n);
    for (ll i = 1; i <= m; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n",query(1, 1, n, l, r));
    }
    return 0;
}
