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
#include <ctime>
#include <cstdio>
#include <cstdlib>
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

int t;
ll n, m;

ll quickPow(int base, int x)
{
    ll nowNum = 1;
    ll nowBase = base;
    while (x != 0)
    {
        if (x % 2 == 1)
        {
            x--;
            nowNum = nowNum * nowBase % m;
        }
        nowBase = nowBase * nowBase % m;
        x = x / 2;
    }
    return nowNum;
}

void work()
{
    cin >> m >> n;
    ll nowAns = 0;
    while (n--)
    {
        int t1, t2;
        cin >> t1 >> t2;
        nowAns = (nowAns + quickPow(t1, t2)) % m;
    }
    cout << nowAns << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}