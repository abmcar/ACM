#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<pair<int, char>> a(n);
    // for (auto &[x, g] : a)
    // {
    //     cin >> x >> g;
    // }
    a.emplace_back(1e9, '@');
    sort(a.begin(), a.end());
    int res = 0;
    int i = 0;
    while (i < n)
    {
        int j = 1;
        while (i + j < n && a[i].second == a[i + j].second)
        {
            ++j;
        }
        res = max(res, a[i + j - 1].first - a[i].first);
        i += j;
    }
    vector<int> pre(n + n, 1e9);
    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        pre[n + k] = min(pre[n + k], a[i].first);
        if (a[i].second == 'G')
        {
            ++k;
        }
        else
        {
            --k;
        }
        res = max(res, a[i].first - pre[n + k]);
    }
    cout << res << endl;
    return 0;
}
