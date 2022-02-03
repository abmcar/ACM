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

int n;
vector<pair<string, int>> ans;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string temp;
        cin >> temp;
        for (char &it : temp)
            if (it == 'X')
                it = '9';
        ans.push_back({temp, i});
    }
    sort(ans.begin(), ans.end(), [&](pair<string,int> a, pair<string,int> b)
         {
             if (a.first.size() != b.first.size())
                 return a.first.size() > b.first.size();
             return a.first > b.first;
         });
    cout << ans[0].second << endl;
    return 0;
}