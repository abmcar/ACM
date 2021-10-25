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
#define Endl "\n"
// #define Debug

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    ll a, b, c ,d;
    ll e, f, g, h;
    cin >> a >> b >> c >> d;
    if (a == 0 || b == 0 || c == 0 || d == 0)
    {
        cin >> e >> f >> g >> h;
        int temp = 0;
        if (a==0)
            temp++;
        if (b==0)
            temp++;
        if (c==0)
            temp++;
        if (d==0)
            temp++;
        if (temp == 1)
        {
            if (a + h == 0 || b + g == 0 || c + f == 0 || d + e == 0)
                cout << "No" << Endl;
            else
                cout << "Yes" << Endl;
        }else
            cout << "Yes" << Endl;
        return 0;
    }
    cin >> e >> f >> g >> h;
    if (a == e && b == f && g == c && d == h)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}