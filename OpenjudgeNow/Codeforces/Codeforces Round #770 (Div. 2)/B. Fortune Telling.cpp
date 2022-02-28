#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug
#define int long long

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, x, y;
bool ok = false;
vector<int> nums;

void dfs(int nowNum, int nowPos, int nowAns)
{
    if (ok)
        return;
    if (nowPos == n + 1)
    {
        if (nowNum == y)
            ok = true;
        return;
    }
    if (nowNum + nowAns < y)
        return;
    dfs(nowNum + nums[nowPos], nowPos + 1, nowAns - nums[nowPos]);
    dfs(nowNum xor nums[nowPos], nowPos + 1, nowAns - nums[nowPos]);
}

void work()
{
    ok = false;
    cin >> n >> x >> y;
    nums.resize(n + 1);
    int totAns = 0;
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    totAns = x % 2 ;
    for (int i = 1; i <= n; i++)
        totAns = totAns xor (nums[i] % 2);
    if (y % 2 == totAns)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
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