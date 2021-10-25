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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

vector<int> num1, num2;
int n;
int k = 2e9;
int num[Maxn];
int ans1[Maxn], ans2[Maxn];
struct Node
{
    int val, pos;
    bool const operator<(Node b) const
    {
        return val < b.val;
    }
}node[Maxn];

int lc(int x)
{
    return x * 2;
}

int rc(int x)
{
    return x * 2 + 1;
}

void pushUp(int pos)
{
    ans1[pos] = max(ans1[lc(pos)], ans1[rc(pos)]);
    ans2[pos] = min(ans2[lc(pos)], ans2[rc(pos)]);
}

void build(int l, int r, int pos)
{
    // cout << l << " " << r << "build " << pos << " " << ans1[pos] << endl;
    if (l == r)
    {
        ans1[pos] = num[l];
        ans2[pos] = num[l];
        // cout << ans1[]
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, lc(pos));
    build(mid + 1, r, rc(pos));
    pushUp(pos);
    // cout << l << " " << r << "build" << pos << " " << ans1[pos] << endl;
}

int query1(int nextl, int nextr, int l, int r, int pos)
{
    // cout << l << " " << r << " q1:" << ans1[pos] << endl;
    if (l == r)
        return ans1[pos];
    if (l >= nextl && r <= nextr)
        return ans1[pos];
    int nowMax = 0;
    int mid = (l + r) / 2;
    if (mid >= nextl)
        nowMax = max(nowMax, query1(nextl, nextr, l, mid, lc(pos)));
    if (mid < nextr)
        nowMax = max(nowMax, query1(nextl, nextr, mid + 1, r, rc(pos)));
    return nowMax;
}

int query2(int nextl, int nextr, int l, int r, int pos)
{
    // cout << nextl << " " << nextr << " ";
    // cout << l << " q2 " << r << " " << ans2[pos] << endl;
    if (l == r)
        return ans2[pos];
    if (l >= nextl && r <= nextr)
        return ans2[pos];
    int nowMin = 2e9;
    int mid = (l + r) / 2;
    if (mid >= nextl)
        nowMin = min(nowMin, query2(nextl, nextr, l, mid, lc(pos)));
    if (mid < nextr)
        nowMin = min(nowMin, query2(nextl, nextr, mid + 1, r, rc(pos)));
    // cout << l << " q2 " << r << " " << pos << endl;
    return nowMin;
}

int main()
{
    // Buff;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        node[i].val = num[i];
        node[i].pos = i;
    }
    // cout << "pass1" << endl;
    sort(node+1,node+1+n);
    for (int i = 1; i <= n; i++)
        num[i] = node[i].pos;
    // for (int i = 1; i <= n; i++)
    //     cout << num[i] << " ";
    // cout << endl;
    // cout << "pass2" << endl;
    build(1,n,1);
    // cout << "pass3" << endl;
    for (int i = 1; i < n; i++)
    {
        // cout << i << endl;
        int pos1 = query1(i+1,n,1,n,1);
        int pos2 = query2(i+1,n,1,n,1);
        // cout << pos1 << " " << pos2 << endl;
        // cout << i << " " <<  node[i].pos << endl;
        // cout << pos1 << " " << pos2 << endl;
        int k1 = node[i].val / std::abs(node[i].pos - pos1);
        int k2 = node[i].val / std::abs(node[i].pos - pos2);
        k = min(k1, k);
        k = min(k2, k);
        // cout << "nowk:" << k << endl;
    }
    cout << k << endl;
    return 0;
}
//5 4 3 2 1