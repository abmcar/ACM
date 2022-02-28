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
vector<int> t;
vector<int> st, aftAns;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> q;
    t.resize(n);
    st.resize(n - 1);
    aftAns.resize(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];
    for (int i = 0; i < n - 1; i++)
        st[i] = t[i + 1] - t[i];
    sort(st.begin(), st.end());
    // for (int i = 0; i < n - 1; i++)
    //     cout << st[i] << " ";
    // cout << endl;
    for (int i = n - 2; i >= 0; i--)
        aftAns[i] = aftAns[i + 1] + st[i];
    while (q--)
    {
        int k, p;
        cin >> k >> p;
        int SP = upper_bound(st.begin(),st.end(),k)-st.begin();
        int totS = aftAns[SP] - k*(n-1-SP);
        // cout << SP << endl;
        // cout << totS << endl;
        if (totS >= p)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}