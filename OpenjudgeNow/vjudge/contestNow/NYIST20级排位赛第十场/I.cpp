#include "bits/stdc++.h"

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int n, m;
int nums[Maxn];

struct Node
{
    int pos, val, type;
    bool operator<(Node b) const
    {
        if (val == b.val)
            return pos < b.pos;
        return val > b.val;
    }
} node[Maxn];

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    while (cin >> n >> m)
    {
        vector<int> V;
        for (int i = 1; i <= n; i++)
            cin >> nums[i];
        for (int i = 1; i <= m; i++)
        {
            cin >> node[i].type >> node[i].val;
            node[i].pos = i;
        }
        sort(node + 1, node + 1 + m);
        int cntPos = 0;
        int lastType = 3;
        for (int i = 1; i <= m; i++)
        {
            if (node[i].pos <= cntPos)
                continue;
            cntPos = node[i].pos;
            if (i == 1)
            {
                if (node[i].type == 1)
                    sort(nums + 1, nums + 1 + node[i].val);
                else
                    sort(nums + 1, nums + 1 + node[i].val, greater<int>());
                V.push_back(node[i].val);
                lastType = node[i].type;
            }
            if (node[i].type != lastType)
                V.push_back(node[i].val);
            // reverse(nums + 1, nums + 1 + node[i].val);
            lastType = node[i].type;
        }
        int l, r;
        l = 1;
        r = V[0];
        V.push_back(0);
        vector<int> ans(n + 10);
        for (int i = 1; i <= n; i++)
            ans[i] = nums[i];
        // for (int i = 1; i <= n; i++)
        //     cout << ans[i] << " ";
        // cout << endl;
        for (int i = 1; i < V.size(); i++)
        {
            // cout << V[i] << " !!! " << Endl;
            for (int j = V[i - 1]; j >= V[i] + 1; j--)
            {
                if (i % 2 == 0)
                    ans[j] = nums[l++];
                else
                    ans[j] = nums[r--];
            }
        }
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
}