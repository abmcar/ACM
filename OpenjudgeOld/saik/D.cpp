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

const int Maxn = 1e6 + 10;

int n, m, tempa[Maxn], ans[Maxn], k, num[Maxn], num1[Maxn];
int templ, tempr;

struct Node
{
    int l, r, k, pos;
    bool const operator<(Node b) const
    {
        ll t1 = l / k;
        ll t2 = b.l / k;
        if (t1 == t2)
            return r < b.r;
        return t1 < t2;
    }

    void get()
    {
        cin >> l >> r >> k;
    }
} node[Maxn];

inline void add(int x)
{
    num1[num[x]]--;
    num[x]++;
    num1[num[x]]++;
}

inline void sor(int x)
{
    num1[num[x]]--;
    num[x]--;
    num1[num[x]]++;
}

void prework()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> tempa[i];
    for (int i = 1; i <= m; i++)
        node[i].get(), node[i].pos = i;
    k = sqrt(m);
    sort(node + 1, node + m + 1);
    templ = node[1].l, tempr = node[1].r;
    for (int i = templ; i <= tempr; i++)
        add(tempa[i]);
    ans[node[1].pos] = num1[node[1].k];
}

void work()
{
    for (int i = 2; i <= m; i++)
    {
        int nowPos = node[i].pos;
        while (templ > node[i].l)
        {
            templ--;
            add(tempa[templ]);
        }
        while (tempr < node[i].r)
        {
            tempr++;
            add(tempa[tempr]);
        }
        while (templ < node[i].l)
        {
            sor(tempa[templ]);
            templ++;
        }
        while (tempr > node[i].r)
        {
            sor(tempa[tempr]);
            tempr--;
        }
        ans[nowPos] = num1[node[i].k];
    }
}

void output()
{
    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;
}

int main()
{
    prework();
    work();
    output();
    return 0;
}