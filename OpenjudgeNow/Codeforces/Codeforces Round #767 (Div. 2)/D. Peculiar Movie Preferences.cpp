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

int t, n, m;

void work()
{
    cin >> n;
    unordered_map<string,bool> M;
    bool ok = false;
    while (n--)
    {
        string s,ts;
        cin >> s;
        ts = s;
        reverse(ts.begin(),ts.end());
        M[ts] = true;
        if ((M[s]) || (s.size() == 3 && M[s.substr(1,2)]))
            ok = true;
        if (s.size() == 2)
            for (char nc = 'a'; nc <= 'z'; nc++)
                if(M[nc+s])
                    ok = true;
        if (s.size() == 1)
        {
            for (char nc = 'a'; nc <= 'z'; nc++)
                if(M[nc+s])
                {
                    ok = true;
                    break;
                }
            for (char n1 = 'a'; n1 <= 'z'; n1++)
            for (char n2 = 'a'; n2 <= 'z'; n2++)
            {
                string nowS = n2 + s;
                nowS = n1 + nowS;
                if (M[nowS])
                {
                    ok = true;
                    break;
                }
            }
        }
    }
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "cw", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}