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

int n, m, ans;
string s, t;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m;
    cin >> s >> t;
    unordered_map<char, int> M1, M2;
    for (char it : s)
        M2[it]++;
    for (char it : t)
        M1[it]++;
    for (auto it : M1)
    {
        M1[it.first]--;
        for (char nowChar = 'A'; nowChar <= 'Z'; nowChar++)
        {
            unordered_map<char, int> tempM = M1;
            tempM[nowChar]++;
            int nowAns = 0;
            for (auto itt : tempM)
                nowAns += itt.second * M2[itt.first];
            ans = max(nowAns, ans);
        }
        M1[it.first]++;
    }
    cout << ans << endl;
    return 0;
}