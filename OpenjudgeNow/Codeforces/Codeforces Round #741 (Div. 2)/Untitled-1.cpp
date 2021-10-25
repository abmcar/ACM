#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
char s[N];
char s2[N];
int pre[N];
int pre2[N];

char re(char s)
{
    if (s == '-')
        return '+';
    return '-';
}
void solve()
{
    int n, q;
    scanf("%d %d", &n, &q);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
    {
        s2[i] = s[i];
        if (i & 1)
            s2[i] = re(s2[i]);
        else
            s[i] = re(s[i]);
    }
    for (int i = 1; i <= n; i++)
        if (s[i] == '-')
            pre[i] = pre[i - 1] - 1;
        else
            pre[i] = pre[i - 1] + 1;
    for (int i = 1; i <= n; i++)
        if (s2[i] == '-')
            pre2[i] = pre2[i - 1] - 1;
        else
            pre2[i] = pre2[i - 1] + 1;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        if (len & 1)
        {
            puts("1");
        }
        else
        {
            if (l & 1)
            {
                if (pre[r] - pre[l - 1] == 0)
                {
                    puts("0");
                    continue;
                }
            }
            else
            {
                if (pre2[r] - pre2[l - 1] == 0)
                {
                    puts("0");
                    continue;
                }
            }
            puts("2");
        }
    }
}

int main()
{
    // cout << re('-') << endl;
    // freopen("1.txt", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

/*


*/
