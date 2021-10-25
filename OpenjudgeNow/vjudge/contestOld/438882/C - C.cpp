#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;
ll t, n, now, d, nowTime;

void work()
{
    cin >> n >> now;
    ll head, tail;
    head = tail = now;
    ll nowTime = 0;
    bool ok = true;
    for (int i = 1; i <= n; i++)
    {
        ll t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        if (head > tail)
            continue;
        d = t1 - nowTime;
        head -= d;
        tail += d;
        nowTime = t1;
        head = max(head, t2);
        tail = min(tail, t3);
        if (head > tail)
            ok = false;
    }
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}