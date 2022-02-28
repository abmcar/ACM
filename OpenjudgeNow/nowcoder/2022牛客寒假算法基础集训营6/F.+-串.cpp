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

void work()
{
    n = m = 0;
    string s;
    map<char, int> M;
    cin >> s >> n;
    for (char it : s)
        M[it]++;
    int hf = s.size() / 2;
    if (M['+'] > M['-'])
    {
        int temp = min(hf - M['-'], n);
        M['+'] -= temp;
        M['-'] += temp;
        n -= temp;
    }else
    {
        int temp = min(hf - M['+'], n);
        M['-'] -= temp;
        M['+'] += temp;
        n -= temp;
    }
    // cout << M['-'] << " " << M['+'] << " " << n << endl;
    if (n % 2)
        if (M['-'] <= M['+'])
        {
            M['+']--;
            M['-']++;
        }else
        {
            M['-']--;
            M['+']++;
        }
    cout << abs(M['+']-M['-']) << endl;
}

signed main()
{
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