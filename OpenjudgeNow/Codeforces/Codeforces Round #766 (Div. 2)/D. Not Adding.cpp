#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;

void work()
{

}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    priority_queue<int,vector<int>,greater<int> > Q;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        Q.push(temp);
    }
    int cnt = 0;
    while (Q.size() >= 2)
    {
        int nowTop1 = Q.top();
        Q.pop();
        if (nowTop1 == 1)
            continue;
        int nowTop2 = Q.top();
        Q.pop();
        if (__gcd(nowTop1,nowTop2) == nowTop1)
        {
            Q.push(nowTop2);
            continue;
        }
        cnt++;
        Q.push(__gcd(nowTop1,nowTop2));
        cout << __gcd(nowTop1,nowTop2) << endl;
    }
    cout << cnt << endl;
    return 0;
}