#include "bits/stdc++.h"
#define ll long long

using namespace std;

ll n;
ll ans;
priority_queue<ll, vector<ll>, greater<ll>> Q;

int main()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll temp;
        cin >> temp;
        Q.push(temp);
    }
    while (Q.size() > 1)
    {
        ll t1 = Q.top();
        Q.pop();
        ll t2 = Q.top();
        Q.pop();
        ans += t1 + t2;
        Q.push(t1 + t2);
    }
    cout << ans << endl;
    return 0;
}