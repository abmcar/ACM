#include <bits/stdc++.h>
#define ll long long
// #define int long long
#define endl '\n'
#define buff                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;
const int N = 1e6;
int cnt = 0;
int ma[N+1000];

void solve()
{
    int n;
    cin >> n;
    // unordered_map<int, int> ma;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ma[x] = 1;
    }
    clock_t strT = clock();
    int ans = 0;
    for (int i = N; i >= 1; i--)
    {
        if (ma[i] == 0)
        {
            int d = 0;
            for (int j = i + i; j <= N; j += i)
            {
                cnt++;
                if (ma[j])
                {
                    d = __gcd(d, j);
                    if (d == i)
                    {
                        ma[d] = 1;
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    cout << clock() - strT << endl;
}
int main()
{
    buff;
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    cout << cnt << endl;
}
