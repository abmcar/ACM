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

int t, n, m, k, x;

void work()
{
    string oriS;
    cin >> n >> k >> x;
    cin >> oriS;
    if (k == 0)
    {
        for (auto it : oriS)
            if (it != '*')
                cout << it;
        cout << endl;
        return;
    }
    x--;
    // vector<int> ans;
    // while (x)
    // {
    //     int nowNum = x % k;
    //     if (k == 1)
    //         nowNum = x, x = 0;
    //     ans.push_back(nowNum);
    //     cout << x << " " << k << " " << nowNum << endl;
    //     x = x / k;
    // }
    string ansS = "";
    reverse(oriS.begin(), oriS.end());
    int cnt = 0;
    int nowValue = 1;
    for (auto it : oriS)
    {
        if (it != '*')
        {
            if (cnt != 0)
            {
                int nowLen = k * cnt;
                int nowNum = x % (nowLen + 1);
                // x = x - nowNum * nowValue;
                x = x / (nowLen + 1);
                for (int i = 1; i <= nowNum; i++)
                    ansS += "b";
                cnt = 0;
                // cout << x << " " << nowValue << endl;
                // x = x / nowLen;
            }
            ansS += it;
        }
        else
            cnt++;
    }
    int nowLen = k * cnt;
    int nowNum = min(nowLen, x / nowValue);
    x = x - nowNum * nowValue;
    nowValue *= nowLen;
    for (int i = 1; i <= nowNum; i++)
        ansS += "b";
    reverse(ansS.begin(), ansS.end());
    cout << ansS << endl;
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