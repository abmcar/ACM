#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define buff                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;
// pair<char, int> s;
// vector<vector<int>> p(n, vector<int>(m));
// #define int ll
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, int> ma;
    ma.clear();
    int res2 = 0, res1 = 0;

    for (int i = 0; i < n; i++)
    {
        ma[s[i]]++;
        if (ma[s[i]] == 2)
        {
            res2++;
            ma[s[i]] = 0;
        }
    }
    for (int i = 0; i < n; i++)
        if (ma[s[i]] == 1)
            res1++;
    cout << "res1" << res1 << endl;
    int sum = 0;
    sum = res2 / k * 2;
    res2 = res2 % k;
    res1 += res2 * 2;
    if (res1 >= k)
    {
        sum++;
    }

    cout << sum << endl;
}
int main()
{
    buff;
    int t;
    cin >> t;
    function<int(int)> fp = [&](int u) {
        cout << u;
        return u;
    };
    while (t--)
        solve();
}
