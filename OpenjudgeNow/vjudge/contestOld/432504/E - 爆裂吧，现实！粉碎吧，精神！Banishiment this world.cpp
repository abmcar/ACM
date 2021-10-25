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

bool check(ll num)
{
    ll temp = num;
    while (temp != 0)
    {
        ll tempNum = temp % 10;
        temp = temp / 10;
        if (tempNum != 0)
        if (num % tempNum != 0)
            return false;
    }
    return true;
}

int main()
{
    Buff;
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        while (!(check(n)))
            n++;
        cout << n << endl;
    }
    return 0;
}