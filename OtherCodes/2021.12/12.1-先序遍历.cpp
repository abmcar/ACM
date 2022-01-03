#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3 + 10;

int node[Maxn];
int nums[20480];
int n, m;
int ans, nowMax, nowDeep;

int lc(int x) { return x * 2; }
int rc(int x) { return x * 2 + 1; }

void build(int pos)
{
    if (!nums[++m])
        return;
    node[pos] = nums[m];
    n = max(n, pos);
    build(lc(pos));
    build(rc(pos));
}

void work()
{
    int cntNode = 0;
    int nowPos = 1;
    int nowAns = 0;
    nowMax = -1e9;
    bool ok = false;
    while (nowPos <= n)
    {
        if (node[lc(nowPos)] == 0 && node[rc(nowPos)] == 0)
        {
            nowAns = nowAns + node[nowPos];
            ok = true;
        }
        nowPos++;
        cntNode++;
        if (cntNode == pow(2, nowDeep) || nowPos == n + 1)
        {
            // cout << nowDeep << " " << nowAns << endl;
            if (ok)
            if (nowMax <= nowAns)
            {
                nowMax = nowAns;
                ans = nowDeep;
            }
            ok = false;
            nowDeep++;
            cntNode = nowAns = 0;
            nowAns = 0;
        }
    }
}

int main()
{
    int temp;
    int cnt = 1;
    while (cin >> temp)
        nums[cnt++] = temp;
    build(1);
    work();
    cout << ans << endl;
    return 0;
}
