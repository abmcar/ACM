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

int n;
ll ans;
int cnt;

int main()
{
    Buff;
    while (cin >> n)
    {
        string temp;
        ll nowNum = 0;
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> temp;
            nowNum = 0;
            for (int j = 0; j < temp.size(); j++)
                nowNum += temp[j];
            ans = max(ans, nowNum);
        }
        cout << "Case " << ++cnt << ": ";
        cout << ans << endl;
    }
    return 0;
}