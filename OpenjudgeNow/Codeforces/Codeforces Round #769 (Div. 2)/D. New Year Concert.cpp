#include <bits/stdc++.h>

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

const int Maxn = 1e6 + 10;
const ll Mod = 1e9 + 7;

struct Node
{
    int l, r, val;
} node[Maxn];
int n, ans;
vector<int> nums;
vector<int> segs[Maxn];

int lc(int x) { return x * 2; }
int rc(int x) { return x * 2 + 1; }

void pushUp(int x)
{
    node[x].val = __gcd(node[lc(x)].val, node[rc(x)].val);
}

void build(int pos, int nowL, int nowR)
{
    if (nowL == nowR)
    {
        node[pos] = {nowL, nowR, nums[nowL]};
        return;
    }
    int nowMid = (nowL + nowR) / 2;
    build(lc(pos), nowL, nowMid);
    build(rc(pos), nowMid + 1, nowR);
    pushUp(pos);
}

int query(int pos, int nowL, int nowR, int targetL, int targetR)
{
    if (nowL >= targetL && nowR <= targetR)
        return node[pos].val;
    int nowMid = (nowL + nowR) / 2;
    int finVal = -1;
    if (nowMid >= targetL)
    {
        int nowVal = query(lc(pos), nowL, nowMid, targetL, targetR);
        finVal = nowVal;
    }
    if (nowMid + 1 <= targetR)
    {
        int nowVal = query(rc(pos), nowMid + 1, nowR, targetL, targetR);
        if (finVal == -1)
            finVal = nowVal;
        else
            finVal = __gcd(finVal, nowVal);
    }
    // cout << nowL << " " << nowR << " " << targetL << " " << targetR << " " << finVal << endl;
    return finVal;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    nums.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    build(1, 1, n);
    for (int i = 1; i <= n; i++)
    {
        int nowL = i + 1;
        int nowR = n;
        int ans = i;
        while (nowL <= nowR)
        {
            int nowMid = (nowL + nowR) / 2;
            if (query(1, 1, n, i, nowMid) >= nowMid - i + 1)
            {
                ans = nowMid;
                nowL = nowMid + 1;
            }
            else
                nowR = nowMid - 1;
        }
        // cout << i << " " << ans << endl;
        if (query(1, 1, n, i, ans) == ans - i + 1)
            segs[ans].push_back(i);
    }
    int nowPos = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int it : segs[i])
        {
            // cout << i << " " << it << endl;
            if (it > nowPos)
            {
                ans++;
                nowPos = i;
            }
            // cout << nowPos << " " << ans << endl;
        }
        cout << ans << " ";
    }
    return 0;
}