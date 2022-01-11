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
    map<int, bool> M;
    vector<int> unuse, targetNum;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        if (!M[temp] && temp <= n)
            M[temp] = true;
        else
            unuse.push_back(temp);
    }
    sort(unuse.begin(), unuse.end());
    for (int i = 0; i < unuse.size(); i++)
    {
        int nowNum = unuse[i] / 2;
        // cout << nowNum << " !!!";
        bool ok = false;
        while (nowNum)
        {
            if (M[nowNum] == false && nowNum <= n)
            {
                M[nowNum] = true;
                ok = true;
                // cout << " find-  " << nowNum << endl;
                break;
            }
            nowNum = nowNum / 2;
        }
        if (!ok)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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