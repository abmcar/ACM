#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug
#define int unsigned long long
using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int k;
string a, b;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> k >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string c = "";
    int nowNum = 0;
    int lena = a.size();
    int lenb = b.size();
    for (int i = 0; i < max(lena, lenb); i++)
    {
        if (i >= lena)
            nowNum += b[i] - '0';
        else if (i >= lenb)
            nowNum += a[i] - '0';
        else
            nowNum += (a[i] - '0') + (b[i] - '0');
        c = c + (char)(nowNum % k + '0');
        nowNum = nowNum / k;
    }
    // cout << nowNum << endl;
    while (nowNum)
    {
        c = c + (char)(nowNum % k + '0');
        nowNum = nowNum / k;
    }
    reverse(c.begin(), c.end());
    cout << c << endl;
    return 0;
}