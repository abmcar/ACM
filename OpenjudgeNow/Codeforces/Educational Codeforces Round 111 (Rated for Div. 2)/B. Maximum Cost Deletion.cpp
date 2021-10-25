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

const int Maxn = 1234 + 10;
const ll Mod = 1e9 + 7;

int t, n, a, b;
vector<int> V;
string oriString;

void work()
{
    V.clear();
    cin >> n >> a >> b;
    cin >> oriString;
    for (int i = 0; i < n; i++)
    {
        int nowPos = i;
        while (oriString[nowPos] == oriString[i] && i < n)
            nowPos++;
        V.push_back(nowPos - i);
        i = nowPos-1;
    }
    // cout << V.size() << Endl;
    int ans = 0;
    if (b >= 0)
        ans = a * n + b * n;
    if (b < 0)
        ans = a * n + b * ((V.size() + 2) / 2);
    cout << ans << endl;
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}