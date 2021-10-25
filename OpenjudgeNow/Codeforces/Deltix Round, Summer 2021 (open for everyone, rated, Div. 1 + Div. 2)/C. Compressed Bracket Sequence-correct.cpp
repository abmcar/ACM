#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
long long a[N];
 
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    // for (int i = 1; i <= n; i++)
    //     printf("%lld ", a[i]);
    // puts("");
    long long ans = 0;
    for (int i = 1; i <= n; i += 2)
    {
        long long sum = a[i], mx, s1 = 0, s2 = 0;
        bool is_fir = 1;
        for (int j = i + 1; j <= n; j += 2)
        {
            if (is_fir)
            {
                s1 += a[j - 1];
                s2 += a[j];
                is_fir = 0;
                ans += min(a[j - 1], a[j]);
                sum -= a[j];
                mx = s1 - s2;
                // if (mx < 0)
                //     break;
                // mx = mx - a[j];
                if (sum < 0)
                    break;
                continue;
            }
 
            // cout << sum << ' ' << mx << endl;
            long long L = a[j - 1] + (sum - mx);
            long long R = min(sum + a[j - 1], a[j]);
            // cout << '\t';
            // cout << i << ' ' << j << ' ' << sum << ' ' << L << ' ' << R << endl;
            if (R - L + 1 > 0)
                ans += R - L + 1;
            sum -= a[j] - a[j - 1];
            if (sum < 0)
                break;
            // if (a[j] > a[j - 1])
            s1 += a[j - 1];
            s2 += a[j];
            mx = min(mx, s1 - s2);
            mx = max(0ll, mx);
        }
        // cout << "debug " << i << ' ' << ans << endl;
    }
    // cout << "\t\t\t";
    cout << ans << endl;
}
 
int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out1.txt", "w", stdout);
    // int t;
    // scanf("%d", &t);
    // while (t--)
    solve();
    return 0;
}
/*
1
8
3 2 3 4 4 3 2 3
1
8                     
14 6 13 6 6 13 13 14
*/