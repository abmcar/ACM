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

int t, n;
int num[Maxn];
int tot;
int ans[Maxn];

void work()
{
    tot = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i], tot += num[i], ans[i] = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        int nowTot = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                nowTot += num[j];
        }
        // cout << nowTot << endl;
        if (nowTot * 2 <= tot)
            continue;
        for (int j = 0; j < n; j++)
            if ((1 << j) & i)
                if ((nowTot - num[j]) * 2 <= tot)
                    ans[j]++;
    }
    for (int i = 0; i < n-1; i++)
        cout << ans[i] << " ";
    cout << ans[n-1];
    cout << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}