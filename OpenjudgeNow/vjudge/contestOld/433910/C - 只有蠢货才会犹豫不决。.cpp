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

int t;
ll a, b;

void work()
{
    cin >> a >> b;
    if (a < b)
        swap(a, b);
    if (b*2 <= a)
    {
        cout << b << endl;
        return;
    }
    int ans = 0;
    while (a - b >= 2)
    {
        int temp = a-3-b;
        temp = temp / 2;
        if (temp == 0)
            temp++;
        a = a - temp*2;
        b = b - temp;
        ans += temp;
        if (a < b)
            swap(a,b);
        cout << a << " " << b << endl; 
    }
    // cout << a << " " << b << " " << ans << endl;
    int temp = b/3;
    ans += temp*2;
    b = b - 3*temp;
    a = a - 3*temp;
    if (a == 2 && b == 1)
        ans++;
    if (a == 2 && b == 2)
        ans++;
    if (a == 3 && b == 2)
        ans++;
    if (a == 3 && b == 1)
        ans++;
    // cout << a << " " << b << " " << ans << endl;
    cout << ans << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}