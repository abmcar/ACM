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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;
vector<int> preAns;
vector<bool> isOk;

int fun(int str, int end)
{
    if (str > end)
        return 0;
    cout << str << " " << end << endl;
    int nowCnt = preAns[end] - preAns[str - 1];
    // if ((end - str + 1) % 2 == 0 && nowCnt == ((end - str + 2) / 2 + 1))
    // {
    //     if (isOk[str] || isOk[end])
    //         return 2;
    //     return 1;
    // }
    // if (nowCnt == ((end - str + 1) / 2 + 1))
    //     return 1;
    int nowAns = 0;
    for (int i = str+1; i <= end; i++)
    {
        int nowNum = preAns[i] - preAns[str - 1];
        int nowSize = i - str + 1;
        if (nowNum * 2 > nowSize)
        {
            nowAns += fun(str, i) + fun(i + 1, end);
            break;
        }
    }
    cout << str << " " << end << " " << nowAns << endl;
    return nowAns;
}

void work()
{
    cin >> n >> m;
    vector<int> nums(n + 1);
    isOk.resize(n + 1);
    preAns.resize(n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        if (nums[i] >= m)
        {
            isOk[i] = true;
            cnt++;
        }
    }
    if (cnt * 2 <= n)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
        preAns[i] = preAns[i - 1] + isOk[i];
    cout << fun(1, n) << endl;
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