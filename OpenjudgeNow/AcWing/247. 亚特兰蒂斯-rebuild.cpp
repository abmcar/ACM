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
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

struct Segment
{
    double posX, posY1, posY2;
    int k;
    const bool operator<(Segment seg) const
    {
        return posX < seg.posX;
    }
} segment[Maxn];

struct Node
{
    int l, r, cnt;
    double len;
} node[Maxn];

vector<double> Ys;

int lc(int x) { return x * 2; }
int rc(int x) { return x * 2 + 1; }

int find(double nowY)
{
    return lower_bound(Ys.begin(), Ys.end(), nowY) - Ys.begin();
}

void pushUp(int x)
{
    if (node[x].cnt)
        node[x].len = Ys[node[x].r + 1] - Ys[node[x].l];
    else if (node[x].l != node[x].r)
        node[x].len = node[lc(x)].len + node[rc(x)].len;
    else
        node[x].len = 0;
}

void build(int x, int l, int r)
{
    node[x].l = l;
    node[x].r = r;
    node[x].cnt = 0;
    node[x].len = 0;
    if (l == r)
        return;
    int mid = (l + r) / 2;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
}

void modify(int x, int l, int r, int k)
{
    // cout << "modify " << x << " " << l << " " << r << " " << k << endl;
    if (node[x].l >= l && node[x].r <= r)
    {
        node[x].cnt += k;
        pushUp(x);
        return;
    }
    int mid = (node[x].l + node[x].r) / 2;
    if (mid >= l)
        modify(lc(x), l, r, k);
    if (mid + 1 <= r)
        modify(rc(x), l, r, k);
    pushUp(x);
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int cnt = 1;
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        Ys.clear();
        for (int i = 0, j = 0; i < n; i++)
        {
            double t1, t2, t3, t4;
            cin >> t1 >> t2 >> t3 >> t4;
            segment[j++] = {t1, t2, t4, 1};
            segment[j++] = {t3, t2, t4, -1};
            Ys.push_back(t2);
            Ys.push_back(t4);
        }
        sort(Ys.begin(), Ys.end());
        Ys.erase(unique(Ys.begin(), Ys.end()), Ys.end());
        build(1, 0, Ys.size() - 2);
        sort(segment, segment + n * 2);
        double nowRes = 0;
        for (int i = 0; i < n * 2; i++)
        {
            if (i != 0)
                nowRes += node[1].len * (segment[i].posX - segment[i - 1].posX);
            // cout << i << " " << node[1].len << " " << nowRes << endl;
            modify(1, find(segment[i].posY1), find(segment[i].posY2) - 1, segment[i].k);
        }
        cout << "Test case #" << cnt++ << endl;
        cout << "Total explored area: " << fixed << setprecision(2) << nowRes << endl;
        cout << endl;
    }
    return 0;
}