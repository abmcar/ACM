#include "bits/stdc++.h"

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
#define int long long
// #define Debug

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n;
String s1, s2;

template <typename T>
class Fenwick
{
public:
    vector<T> fenw;
    int n;
    Fenwick(int _n) : n(_n)
    {
        fenw.resize(n);
    }

    void modify(int x, T val)
    {
        while (x < n)
        {
            fenw[x] += val;
            // x += lowbit(x);
            x |= (x + 1);
        }
    }

    T get(int x)
    {
        T nowAns{};
        while (x >= 0)
        {
            nowAns += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return nowAns;
    }
};

void work()
{
    int ans = 1e18;
    cin >> n;
    cin >> s1 >> s2;
    vector<vector<int>> pos(26);
    vector<int> ptr(26);
    Fenwick<int> fen(n);
    for (int i = 0; i < n; i++)
        pos[s1[i] - 'a'].push_back(i);
    for (int i = 0; i < n; i++)
        fen.modify(i, 1);
    int cur = 0;
    // cout<< "test1" << endl;
    for (int i = 0; i < n; i++)
    {
        int targetChar = s2[i] - 'a';
        for (int j = 0; j < targetChar; j++)
        {
            if (ptr[j] < pos[j].size())
            {
                int x = pos[j][ptr[j]];
                ans = min(ans, cur + fen.get(x - 1));
            }
        }
        if (ptr[targetChar] == pos[targetChar].size())
            break;
        int x = pos[targetChar][ptr[targetChar]];
        cur += fen.get(x-1);
        fen.modify(x,-1);
        ptr[targetChar]++;
    }
    if (ans == 1e18)
        ans = -1;
    cout << ans << endl;
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