#include <bits/stdc++.h>

using namespace std;

int n, k;
int p1, p2;

signed main()
{
    cin >> n >> k;
    vector<int> n1, n2;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (i % 2)
            n1.push_back(i);
        else
            n2.push_back(i);
    for (int i = 1; i <= (k + 1) / 2; i++)
    {
        ans.push_back(n1[p1++]);
        ans.push_back(n2[p2++]);
    }
    while (p2 < n2.size())
        ans.push_back(n2[p2++]);
    if (p1 < n1.size())
        if (k % 2 == 0)
            ans.push_back(n1[p1++]);
    while (p1 < n1.size())
        ans.insert(ans.begin(), n1[p1++]);
    for (int it : ans)
        cout << it << " ";
    return 0;
}