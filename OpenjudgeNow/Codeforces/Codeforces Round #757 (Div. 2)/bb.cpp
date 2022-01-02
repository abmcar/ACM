#include <bits/stdc++.h>
#define ll long long
#define int ll
#define endl '\n'
#define buff                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;
struct e
{
    ll v;
    ll g;
} ass[200005];

int cmp(e a, e b)
{
    if (a.v < b.v)
        return 0;
    return 1;
}
int c[200005];

signed main()
{
    buff;
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> ass[i].v;
            ass[i].g = i;
        }
        sort(ass + 1, ass + n + 1, cmp);
        int flag = 0;
        int zuo = 0;
        int you = 0;
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (flag == 1)
            {
                flag = 0;
                you++;
                ans += 2 * you * ass[i].v;
                c[ass[i].g] = you;
            }
            else
            {
                flag = 1;
                zuo++;
                ans += 2 * zuo * ass[i].v;
                c[ass[i].g] = -zuo;
            }
        }
        cout << ans << endl;
        cout << 0 << ' ';
        for (int i = 1; i <= n; i++)
        {
            cout << c[i] << ' ';
        }
        cout << endl;
    }
}
