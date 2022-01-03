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

int n, p, key, cnt, id;
vector<int> arr;
map<int, int> M;

void clear()
{
    cnt = 0;
    M.clear();
    arr.resize(n + 123);
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        cin >> key;
        id = key % p;
        if (M[id] == 0)
        {
            M[id] = key;
            arr[cnt++] = id;
        }
        else
        {
            int j = -1;
            if (M[id] == key)
            {
                arr[cnt++] = id;
            }
            if (M[id] != key)
            {
                while (M[(id + 1) % p] != 0 && M[(id + 1) % p] != key)
                    id++;
                M[(id + 1) % p] = key;
                arr[cnt++] = (id + 1) % p;
            }
        }
    }
}

void output()
{
    for (int i = 0; i < cnt; i++)
    {
        if (i != 0)
            cout << " ";
        cout << arr[i];
    }
    cout << endl;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    while (cin >> n >> p)
    {
        clear();
        solve();
        output();
    }
}