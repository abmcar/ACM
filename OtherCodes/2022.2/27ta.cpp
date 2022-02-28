#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

signed main()
{
    cin >> n >> k;
    unordered_map<int, int> M;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        M[temp]++;
    }
    for (auto it : M)
        Q.push({it.first, it.second});
    while (k > 0)
    {
        pair<int, int> nowTop = Q.top();
        if (nowTop.second > k)
            break;
        Q.pop();
        k = k - nowTop.second;
        if (Q.size())
        {
            pair<int, int> nextTop = Q.top();
            if (nextTop.first == nowTop.first + 1)
            {
                Q.pop();
                nextTop.second += nowTop.second;
                Q.push(nextTop);
                continue;
            }
        }
        Q.push({nowTop.first + 1, nowTop.second});
    }
    cout << Q.top().first << endl;
    return 0;
}