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

ll k, a, b;
int ans;

int main()
{
    Buff;
    cin >> k >> a >> b;
    if (k > 0)
    {
        k = k - a;
        if (k <= 0)
        {
            cout << "1" << endl;
            return 0;
        }
        if (a <= b)
        {
            cout << "-1" << endl;
            return 0;
        }
        ans = k / (a-b) + 1;
        if (k % (a-b) != 0)
            ans++;
        cout << ans << endl;
        return 0;
    }
    if (b <= a)
    {
        cout << "-1" << endl;
        return 0;
    }
    k = k * -1;
    ans = k / (b-a);
    if (k % (b-a) != 0)
        ans++;
    cout << ans << endl;
    return 0;
}
/*
8 3 1
3 2 5 4 
*/