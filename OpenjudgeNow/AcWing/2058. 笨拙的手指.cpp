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
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int get(string s, int b)
{
    int res = 0;
    for (char nowChar : s)
        res = res * b + nowChar - '0';
    return res;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    string a, b;
    cin >> a >> b;

    unordered_set<int> S;

    for (auto &c : a)
    {
        c ^= 1;
        S.insert(get(a, 2));
        c ^= 1;
    }

    for (auto &c : b)
    {
        char t = c;
        for (int i = 0; i < 3; i++)
            if (i + '0' != t)
            {
                c = i + '0';
                int x = get(b, 3);
                if (S.count(x))
                {
                    cout << x << endl;
                    return 0;
                }
            }
        c = t;
    }
    return 0;
}