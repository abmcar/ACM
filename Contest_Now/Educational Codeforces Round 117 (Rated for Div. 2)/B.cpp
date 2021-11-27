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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, a, b;

void work()
{
    cin >> n >> a >> b;
    map<int, bool> M;
    vector<int> V1, V2;
    M[a] = true;
    M[b] = true;
    V1.push_back(a);
    V2.push_back(b);
    for (int i = n; i >= a; i--)
    {
        if (M[i])
            continue;
        M[i] = true;
        V1.push_back(i);
        if (V1.size() == n/2)
            break;
    }
    for (int i = 1; i <= b; i++)
    {
        if (M[i])
            continue;
        M[i] = true;
        V2.push_back(i);
        if (V2.size() == n/2)
            break;
    }
    if (V1.size() != n/2 || V2.size() != n/2)
    {
        cout << "-1" << endl;
        return;
    }
    for (int it : V1)
        cout << it << " ";
    for (int it : V2)
        cout << it << " ";
    cout << endl;
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