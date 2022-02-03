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

int n, q;
map<char,int> M;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    string oriString;
    cin >> n >> q;
    cin >> oriString;
    for (auto it : oriString)
        M[it]++;
    while (n--)
    {
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            int val;
            cin >> val;
            for (auto &it : M)
                it.second = (it.second + it.second * val % Mod) % Mod;
                
        }else
        {
            char val;
            cin >> val;
            cout << M[val] << endl;
        }
    }
    return 0;
}