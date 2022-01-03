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
int n;

int dfs(char *pre, char *in, int n)
{
    if (n == 0)
        return 0;
    int i;
    for (i = 0; i < n; i++)
        if (pre[0] == in[i])
            break;
    int left = dfs(pre + 1, in, i);
    int right = dfs(pre + i + 1, in + i + 1, n - i - 1);
    return max(left, right) + 1;
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    while (cin >> n)
    {
        char pre[n + 1], in[n + 1];
        cin >> pre >> in;
        cout << dfs(pre, in, n) << endl;
    }
    return 0;
}