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

int t, n;

// void work1()
// {
//     cin >> n;
//     string oriString;
//     cin >> oriString;
//     string ans = oriString;
//     reverse(ans.begin(),ans.end());
//     ans = oriString + ans;
//     string nowString1 = "";
//     string nowString2 = "";
//     for (int i = 0; i < n; i++)
//     {
//         nowString1 += oriString[i];
//         nowString2 = oriString[i] + nowString2;
//         string newString = nowString1 + nowString2;
//         ans = min(ans, newString);
//         // cout << newString << endl;
//     }
//     cout << ans << endl;
// }

void work()
{
    string nowS;
    cin >> n >> nowS;
    int cnt = n - 1;
    for (int i = 0; i + 1 < n; i++)
        if (nowS[i] < nowS[i + 1] || (i == 0 && nowS[i] == nowS[i + 1]))
        {
            cnt = i;
            break;
        }
    string ans = nowS;
    ans = ans.substr(0, cnt + 1);
    reverse(ans.begin(), ans.end());
    ans = nowS.substr(0, cnt + 1) + ans;
    cout << ans << endl;
}

signed main()
{
    // cout << min(string("cbaabc"), string("cbaaaabc")) << endl;
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
    {
        work();
        // work1();
    }
    return 0;
}