#include "bits/stdc++.h"

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
#define int long long
// #define Debug

using namespace std;

const int Maxn = 1e6 + 10;
const ll Mod = 1e9 + 7;

int t, n;

struct Node
{
    int pos, value;
    int id;
    bool operator<(Node b) const
    {
        return value > b.value;
    }
} node[Maxn];
int pos[Maxn];
int totAns;

void work()
{
    totAns = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> node[i].value;
        node[i].id = i;
    }
    sort(node + 1, node + 1 + n);
    int cnt = -1;
    for (int i = 1; i <= n; i++)
    {
        totAns += abs(cnt)*node[i].value;
        pos[node[i].id] = cnt;
        if (cnt > 0)
        {
            cnt++;
            cnt = cnt * -1;
        }
        else
            cnt = cnt * -1;
    }
    cout << totAns*2 << endl;
    cout << 0 << " ";
    for (int i = 1; i <= n; i++)
        cout << pos[i] << " ";
    cout << endl;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}