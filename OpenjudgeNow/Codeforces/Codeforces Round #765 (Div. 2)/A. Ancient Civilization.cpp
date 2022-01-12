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

int t, n, m;

string intToString(int x)
{
    string ans = "";
    while (x)
    {
        ans = ans + (char)(x % 2 + '0');
        x = x / 2;
    }
    return ans;
}

void work()
{
    cin >> n >> m;
    map<int, int> M;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        string nowString;
        nowString = intToString(temp);
        for (int j = 0; j < nowString.size(); j++)
            if (nowString[j] == '1')
                M[j]++;
    }
    ll nowNum = 0;
    for (int i = 0; i < m; i++)
        if (M[i] * 2 > n)
            nowNum += (1 << i);
    cout << nowNum << endl;
}

signed main()
{
    // cout << intToString(5) << endl;
    // cout << intToString(16) << endl;
    // cout << intToString(15) << endl;
    // cout << intToString(42) << endl;
    // cout << intToString(83) << endl;
    // cout << intToString(65) << endl;
    // cout << intToString(78) << endl;
    // cout << intToString(42) << endl;
    // cout << intToString(2) << endl;
    // cout << intToString(11) << endl;
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