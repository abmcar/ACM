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

string s1;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> s1;
    unordered_map<char,int> M;
    int maxn = 0;
    for (char it : s1)
    {
        M[it]++;
        maxn = max(maxn,M[it]);
    }
    if (maxn % 2)
        cout << "kou" << Endl;
    else
        cout << "yukari" << Endl;
    return 0;
}