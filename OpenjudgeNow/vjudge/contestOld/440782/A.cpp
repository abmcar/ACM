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

int t, n, k;

void work()
{
    priority_queue<int,vector<int>,greater<int>> Q;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        Q.push(temp);
    }
    for (int i = 1; i <= k; i++)
    {
        int temp = Q.top();
        Q.pop();
        Q.push(temp*-1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += Q.top(), Q.pop();
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