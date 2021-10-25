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
#include <unordered_map>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;
ll num[Maxn];

ll getNum(int x)
{
    ll ans = 1;
    while (x != 0)
    {
        ans = ans * (x % 10);
        x = x / 10;
    }
    return ans;
}

ll getL(int x)
{
    int ans = 0;
    while (x != 0)
    {
        ans++;
        x = x / 10;
    }
    return ans;
}

int t;
int n = sqrt(2e9);
ll w;

void work()
{
    cin >> w;
    if (w == 0)
    {
        cout << "0 0" << endl;
        return;
    }
    int nowAns = 1e9;
    int ansl, ansr;
    for (int i = 1; i <= n; i++)
    {
        ll nowR = i;
        ll nowNum = num[i];
        ll llen = getL(i);
        while (nowNum != 0 && nowNum <= w)
        {
            ll rlen = getL(nowR);
            if (llen + rlen > nowAns)
                break;
            if (nowNum == w)
            {
            // cout << nowNum << endl;
                if (llen + rlen < nowAns)
                {
                    ansl = i;
                    ansr = nowR;
                    // cout << ansl << " " << ansr << " " << getL(nowR) + getL(i) << endl;
                    nowAns = llen + rlen;
                }
            }
            nowR++;
            nowNum *= num[nowR];
        }
    }
    if (nowAns == 1e9)
    {
        // cout << "-1" << endl;
        string ans;
        for (int i = 1; i <= 20; i++)
        {
            for (int j = 9; j >= 2; j--)
                if (w % j == 0)
                    ans = ans + char(i + '0');
        }
        if (w == 0)
        {
            sort(ans.begin(),ans.end());
            cout << ans << endl;
        }else
        {
            cout << "-1" << endl;
        }
        return;
    }else
    {
        cout << ansl << " " << ansr << endl;
    }
}

int main()
{
    // Buff;
    for (int i = 1; i <= n; i++)
        num[i] = getNum(i);
    cin >> t;
    while (t--)
        work();
    return 0;
}