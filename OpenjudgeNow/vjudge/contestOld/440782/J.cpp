#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <unordered_map>
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

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;
int t, n, m;
unordered_map<int,int> M,Mpre;
int bd[Maxn][Maxn];

void work()
{
    int ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        cin >> bd[i][j];
    for (int i = 2; i <= n; i++)
    {
        M.clear();
        for (int j = 1; j <= m; j++)
            M[bd[i-1][j]]++;
        for (int j = 1; j <= m; j++)
        if (M[bd[i][j]] > 0)
        {
            M[bd[i][j]]--;
            ans++;
        }
    }
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