#include <iostream>
#include <algorithm>
#define ll long long
#define endl '\n'

using namespace std;

const int Maxn = 1e5 + 10;

int t, n;
ll a;
ll h[Maxn];

void work()
{
    cin >> n >> a;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    sort(h + 1, h + 1 + n);
    ll tot = 0;
    int pos = 0;
    for (int i = 1; i <= n; i++)
        if (h[i] < a)
            tot += h[i], ++pos;
    // pos--;
    tot -= h[pos];
    ll nowL = -h[pos];
    ll nowR = 0;
    // pos = max(0, pos);
    for (int i = pos+1; i <= n; i++)
    {
        nowR += a;
        nowL = min(nowL, nowR - h[i]);
        // cout << nowL << " " << nowR << endl;
    }
    // cout << pos << endl;
    // cout << tot << endl;
    tot += nowR - nowL;
    // cout << nowL << endl;
    nowL += a;
    // cout << nowL << endl;
    while (nowL < 0 && pos > 1)
    {
        pos--;
        tot -= min(h[pos], nowL*-1);
        nowL += a;
    }
    cout << tot << endl;
}

int main()
{
    cin >> t;
    while (t--)
        work();
    return 0;
}