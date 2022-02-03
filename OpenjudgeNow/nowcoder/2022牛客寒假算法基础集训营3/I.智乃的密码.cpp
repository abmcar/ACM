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

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

int n, l, r, ans;
string password;
int preAns[5][Maxn];

int getType(char nowChar)
{
    if (nowChar >= 'a' && nowChar <= 'z')
        return 1;
    if (nowChar >= 'A' && nowChar <= 'Z')
        return 2;
    if (nowChar >= '0' && nowChar <= '9')
        return 3;
    return 4;
}

bool check(int strPos, int targetPos)
{
    vector<int> nums(5);
    int temp = 0;
    for (int j = 1; j <= 4; j++)
    {
        nums[j] = preAns[j][targetPos] - preAns[j][strPos - 1];
        if (nums[j] > 0)
            temp++;
    }
//     cout << "check " << strPos << " " << targetPos << " " << temp << endl;
    return temp >= 3;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> l >> r;
    cin >> password;
    password = "-" + password;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 4; j++)
            preAns[j][i] = preAns[j][i-1];
        preAns[getType(password[i])][i]++;
    }
    for (int i = 1; i + l - 1 <= n; i++)
    {
        int nowL = i + l - 1;
        int nowR = min(n, i + r - 1);
        int nowAns = 0;
        while (nowL <= nowR)
        {
            int nowMid = (nowL + nowR) / 2;
            if (check(i, nowMid))
            {
                nowAns = nowMid;
                nowR = nowMid - 1;
            }
            else
                nowL = nowMid + 1;
        }
        if (nowAns == 0)
            continue;
        // cout << i << " " << nowAns << endl;
        int effAns = min(n, i + r - 1) - nowAns + 1;
        // cout << effAns << endl;
        ans += effAns;
    }
    cout << ans << endl;
    return 0;
}